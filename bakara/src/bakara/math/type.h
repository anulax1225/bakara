#pragma once

/*! \file type.h
Math types alias file used to abstract math types and not depend on any library. 
As long as it's implemented here. 
*/

#include <bakara/math/mathpch.h>

namespace Bk
{
    /*! \typedef Bk::uint
    Simplefied name for unsigned int
    */
    using uint = unsigned int;
    /*! \typedef Bk::Vec2
    Wrapper around glm::vec2
    */
    using Vec2 = glm::vec2;
    /*! \typedef Bk::Vec3
    Wrapper around glm::vec3
    */
    using Vec3 = glm::vec3;
    /*! \typedef Bk::Vec4
    Wrapper around glm::vec4
    */
    using Vec4 = glm::vec4;
    /*! \typedef Bk::Mat3
    Wrapper around glm::mat3
    */
    using Mat3 = glm::mat3;
    /*! \typedef Bk::Mat4
    Wrapper around glm::mat4
    */
    using Mat4 = glm::mat4;   
}
