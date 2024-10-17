#pragma once

#include "bakara/math/types.h"

namespace Bk 
{
    class OrthoCamera
    {
        public:
            OrthoCamera(float left, float right, float bottom, float top);

            void SetPosition(Vec3 position) { this->position = position; RecalculateView(); }
            const Vec3& GetPosition() const { return position; }
            void SetRotation(float rotation) { this->rotation = rotation; RecalculateView(); }
            float GetRotaion() const { return rotation; }

            const Mat4 GetView() const { return view; }
            void SetProjection(float left, float right, float bottom, float top);
            const Mat4 GetProjection() const { return projection; }
            const Mat4 GetViewProjection() const { return viewProjection; }

        private:
            void RecalculateView();
            Mat4 view;
            Mat4 projection;
            Mat4 viewProjection;

            Vec3 position = { 0.0f, 0.0f, 0.0f };
            float rotation = 0.0f;
    };
}