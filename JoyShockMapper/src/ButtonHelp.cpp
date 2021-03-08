﻿#pragma once

#include <JoyShockMapper.h>

const map<ButtonID, string> buttonHelpMap{
	{ ButtonID::UP, "Up on the d-pad" },
	{ ButtonID::DOWN, "Down on the d-pad" },
	{ ButtonID::LEFT, "Left on the d-pad" },
	{ ButtonID::RIGHT, "Right on the d-pad" },
	{ ButtonID::L, "L1 or L, the top left shoulder button" },
	{ ButtonID::ZL, "L2 or ZL, the bottom left shoulder button(or trigger)" },
	{ ButtonID::MINUS, "Share or -" },
	{ ButtonID::CAPTURE, "Touchpad click or Capture" },
	{ ButtonID::E, "The East face button, Circle or A" },
	{ ButtonID::S, "The South face button, Cross or B" },
	{ ButtonID::N, "The North face button, Triangle or X" },
	{ ButtonID::W, "The West face button, Square or Y" },
	{ ButtonID::R, "R1 or R, the top right shoulder button" },
	{ ButtonID::ZR, "R2 or ZR, the bottom right shoulder button" },
	{ ButtonID::PLUS, "Options or +" },
	{ ButtonID::HOME, "PS or Home" },
	{ ButtonID::LSL, "Left joycon SL, only on JoyCons" },
	{ ButtonID::LSR, "Left joycon SR, only on JoyCons" },
	{ ButtonID::RSL, "Right Joycon SL, only on JoyCons" },
	{ ButtonID::RSR, "Right joycon SR, only on JoyCons" },
	{ ButtonID::L3, "L3 or Left stick click" },
	{ ButtonID::R3, "R3 or Right stick click" },
	{ ButtonID::LUP, "Left stick tilted up" },
	{ ButtonID::LDOWN, "Left stick tilted down" },
	{ ButtonID::LLEFT, "Left stick tilted left" },
	{ ButtonID::LRIGHT, "Left stick tilted right" },
	{ ButtonID::LRING, "Left ring binding, either inner or outer." },
	{ ButtonID::RUP, "Right stick tilted up" },
	{ ButtonID::RDOWN, "Right stick tilted down" },
	{ ButtonID::RLEFT, "Right stick tilted left" },
	{ ButtonID::RRIGHT, "Right stick tilted right" },
	{ ButtonID::RRING, "Right ring binding, either inner or outer." },
	{ ButtonID::MUP, "Motion stick tilted forward" },
	{ ButtonID::MDOWN, "Motion stick tilted back" },
	{ ButtonID::MLEFT, "Motion stick tilted left" },
	{ ButtonID::MRIGHT, "Motion stick tilted right" },
	{ ButtonID::MRING, "Motion ring binding, either inner or outer." },
	{ ButtonID::LEAN_LEFT, "Tilt the controller to the left" },
	{ ButtonID::LEAN_RIGHT, "Tilt the controller to the right" },
	{ ButtonID::TOUCH, "The touchpad is being touched" },
	{ ButtonID::ZLF, "Full pull binding of left trigger, only on controllers with analog triggers" },
	{ ButtonID::ZRF, "Full pull binding of right trigger, only on controllers with analog triggers" },
};