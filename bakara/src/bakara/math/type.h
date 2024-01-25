#pragma once

/*! \file type.h
    Math types alias file used to abstract math types and not depend on any library. 
    As long as it's implemented here. 
*/

/*! \typedef Bk::uint
\brief Simplefied name for unsigned int
*/

/*! \typedef Bk::Vec2
\brief Wrapper around glm::vec2
*/

/*! \typedef Bk::Vec3
\brief Wrapper around glm::vec3
*/

/*! \typedef Bk::Vec4
\brief Wrapper around glm::vec4
*/

/*! \typedef Bk::Mat3
\brief Wrapper around glm::mat3
*/

/*! \typedef Bk::Mat4
\brief Wrapper around glm::mat4
*/

#include <bakara/math/mathpch.h>

namespace Bk
{
    using uint = unsigned int;
    using Vec2 = glm::vec2;
    using Vec3 = glm::vec3;
    using Vec4 = glm::vec4;
    using Mat3 = glm::mat3;
    using Mat4 = glm::mat4;   
}
