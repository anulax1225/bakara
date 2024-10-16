#pragma once

#include <cstdint>

namespace Bk {
	/*! \typedef Bk::MouseCode
	Unsigned integer representing a unique mouse button
	*/
	using Code = uint16_t;

	/*! \enum Bk::MouseCodes
	Enumerator made to bind every mouse buttons with a Bk::MouseCode
	*/
	typedef enum : Code
	{
		Button0                = 0, /*!< Button left */
		Button1                = 1, /*!< Button right */
		Button2                = 2, /*!< Button middle */
		Button3                = 3, /*!< Macro1 */
		Button4                = 4, /*!< Macro2 */
		Button5                = 5, /*!< Macro3 */
		Button6                = 6, /*!< Macro4 */
		Button7                = 7,	/*!< Button last */

		ButtonLast             = Button7,
		ButtonLeft             = Button0,
		ButtonRight            = Button1,
		ButtonMiddle           = Button2
	} MouseCode;
}