#pragma once

#include "bakara/math/types.h"

namespace Bk 
{
    class OrthographicCamera
    {
        public:
            OrthographicCamera(float left, float right, float bottom, float top);

            void SetPosition(Vec3 position) { this->position = position; RecalculViewMatrix(); }
            Vec3 GetPosition() { return position; }
            void SetRotation(float rotation) { this->rotation = rotation; RecalculViewMatrix(); }
            float GetRotaion() { return rotation; }

            Mat4 GetViewMatrix() { return viewMatrix; }
            Mat4 GetProjectionMatrix() { return projectionMatrix; }
            Mat4 GetViewProjectionMatrix() { return viewProjectionMatrix; }

        private:
            void RecalculViewMatrix();
            Mat4 viewMatrix;
            Mat4 projectionMatrix;
            Mat4 viewProjectionMatrix;

            Vec3 position = { 0.0f, 0.0f, 0.0f };
            float rotation = 0.0f;
    };
}