#include "ortho_camera.h"
#include "bakara/math/types.h"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/matrix.hpp"
#include "glm/trigonometric.hpp"

namespace Bk 
{
    OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
    : projectionMatrix(Math::ortho(left, right, bottom, top, -1.0f, 1.0f))
    {
        RecalculViewMatrix();
    }

    void OrthographicCamera::RecalculViewMatrix()
    {
        Mat4 transform = Math::translate(Mat4(1.0f), position); 
        transform = Math::rotate(transform, Math::radians(rotation) , Vec3(0.0f, 0.0f, 1.0f));
        viewMatrix = Math::inverse(transform);
        viewProjectionMatrix = projectionMatrix * viewMatrix;
    }
}