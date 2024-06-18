#pragma once
namespace Bk {
	/*! \typedef Bk::ControllerCode
	Unsigned integer representing a unique controller button
	*/
	using ControllerCode = uint16_t;
	/*! \typedef Bk::ControllerAxesCode
	Unsigned integer representing a unique controller axe
	*/
	using ControllerAxes = uint16_t;

	/*! \enum Bk::ControllerButton
	Enumerator made to bind every controller buttons with a Bk::ControllerCode
	*/
	typedef enum : ControllerCode
	{						
		BTN_DOWN = 0,				//!< Cross, A
		BTN_LEFT = 1,				//!< Square, X
		BTN_UP = 2,					//!< Triangle, Y	
		BTN_RIGHT = 3,				//!< Circle, B
		SHOULDER_LEFT = 4,			//!< L1, LB
		SHOULDER_RIGHT = 5,			//!< R1, RB
		TRIGGER_LEFT = 6,			//!< L2, LT
		TRIGGER_RIGHT = 7,			//!< R2, RT
		SELECT = 8,					//!< Share, Address
		START = 9,					//!< Options, Menu
		LEFT_STICK = 10,		    //!< L3, LS
		RIGHT_STICK = 11,			//!< R3, RS
		HOME = 12,					//!< Home, Home
		CLICK = 13,					//!< Touch pad, n/a
		DPAD_UP = 14,				//!< Dpad up, Dpad up
		DPAD_RIGHT = 15,			//!< Dpad right, Dpad right
		DPAD_DOWN = 16,				//!< Dpad down, Dpad down
		DPAD_LEFT = 17,				//!< Dpad left, Dpad left
	} ControllerButton;

	/*! \enum Bk::ControllerJoystick
	Enum made to bind every controller axes with a Bk::ControllerAxesCode
	*/
	typedef enum : ControllerAxes
	{
		AXES_LEFT_STICK_X = 0,
		AXES_LEFT_STICK_Y = 1,
		AXES_RIGHT_STICK_X = 2,
		AXES_LEFT_TRIGGER = 3,
		AXES_RIGHT_TRIGGER = 4,
		AXES_RIGHT_STICK_Y = 5,
	} ControllerJoystick;
}