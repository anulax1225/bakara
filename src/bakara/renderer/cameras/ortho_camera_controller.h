#pragma once

#include "bakara/core/deltatime.h"
#include "bakara/events/event.h"
#include "bakara/events/mouse_event.h"
#include "bakara/events/window_event.h"
#include "ortho_camera.h"

namespace Bk 
{
    class OrthoCameraController
    {
        public:
            OrthoCameraController(float aspectRatio, bool rotation = false, bool zoom = false);

            void OnUpdate(DeltaTime dt);
            void OnEvent(Event& e);

            const OrthoCamera& GetCamera() { return camera; }

            void SetMoveSpeed(float moveSpeed) { this->moveSpeed = moveSpeed; }
            void SetRotationSpeed(float rotationSpeed) { this->rotationSpeed = rotationSpeed; }

        private:
            float aspectRatio;
            float zoomLevel = 1.0f;

            bool rotation, zoom;
            float cameraRotation = 0.0f;
            Vec3 cameraPosition = { 0, 0, 0 };
            float moveSpeed = 1.0f;
            float rotationSpeed = 1.0f;

            OrthoCamera camera;

            bool OnMouseScroll(MouseScrollEvent& e);
            bool OnWindowResize(WindowResizeEvent& e);
    };
}