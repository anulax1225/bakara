#include "ortho_camera.h"
#include "bakara/math/types.h"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/matrix.hpp"
#include "glm/trigonometric.hpp"

namespace Bk 
{
    OrthoCamera::OrthoCamera(float left, float right, float bottom, float top)
    : projection(Math::ortho(left, right, bottom, top, -1.0f, 1.0f))
    {
        RecalculateView();
    }

    void OrthoCamera::SetProjection(float left, float right, float bottom, float top)
    {
        projection = Math::ortho(left, right, bottom, top, -1.0f, 1.0f);
        viewProjection = projection * view;
    }

    void OrthoCamera::RecalculateView()
    {
        Mat4 transform = Math::translate(Mat4(1.0f), position); 
        transform = Math::rotate(transform, Math::radians(rotation) , Vec3(0.0f, 0.0f, 1.0f));
        view = Math::inverse(transform);
        viewProjection = projection * view;
    }
}