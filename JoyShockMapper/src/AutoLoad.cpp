#include "AutoLoad.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <sstream>
// https://stackoverflow.com/a/4119881/1130520 gives us case insensitive equality
static bool iequals(const string& a, const string& b)
{
	return equal(a.begin(), a.end(),
	  b.begin(), b.end(),
	  [](char a, char b)
	  {
		  return tolower(a) == tolower(b);
	  });
}
namespace JSM
{

AutoLoad::AutoLoad(CmdRegistry* commandRegistry, bool start)
  : PollingThread("AutoLoad thread", std::bind(&AutoLoad::AutoLoadPoll, this, std::placeholders::_1), (void*)commandRegistry, 1000, start)
{
}


bool AutoLoad::AutoLoadPoll(void* param)
{
    auto registry = reinterpret_cast<CmdRegistry*>(param);
    static std::string lastModuleName;

    // Run the command to get the active window name
    std::string windowTitle, windowModule;
    std::string command = "xdotool getactivewindow getwindowname";
    FILE* fp = popen(command.c_str(), "r");

    if (!fp) {
        std::cerr << "Failed to execute command." << std::endl;
        return false;
    }

    char buffer[256];
    if (fgets(buffer, sizeof(buffer), fp)) {
        windowTitle = std::string(buffer);
        // Remove the newline character at the end
        windowTitle.erase(windowTitle.find_last_not_of("\n") + 1);
        windowModule = windowTitle;  // In this case, we'll assume the window title is also the module name.
    }

    fclose(fp);

    // Check if the window title (module) has changed and is not JoyShockMapper
    if (!windowModule.empty() && windowModule != lastModuleName && windowModule.compare("JoyShockMapper.exe") != 0)
    {
        lastModuleName = windowModule;
        std::string path(AUTOLOAD_FOLDER());
        auto files = ListDirectory(path);
        auto noextmodule = windowModule.substr(0, windowModule.find_first_of('.'));
        
        std::cout << "[AUTOLOAD] \"" << windowTitle << "\" in focus: "; // looking for config
        bool success = false;
        
        // Loop through files and check for a match
        for (const auto& file : files)
        {
            auto noextconfig = file.substr(0, file.find_first_of('.'));
            if (iequals(noextconfig, noextmodule))
            {
                std::cout << "loading \"AutoLoad\\" << noextconfig << ".txt\"." << std::endl;
                WriteToConsole(path + file);
                success = true;
                break;
            }
        }

        if (!success)
        {
            std::cout << "create ";
            std::cout << "AutoLoad\\" << noextmodule << ".txt";
            std::cout << " to autoload for this application." << std::endl;
        }
    }
    
    return true;
}

} // JSM