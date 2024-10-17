#include "ortho_camera_controller.h"
#include "bakara/events/dispacher.h"
#include "bakara/events/event.h"
#include "bakara/events/window_event.h"
#include "bakara/io/keyboard.h"
#include "glm/trigonometric.hpp"
#include <cmath>

namespace Bk
{
    OrthoCameraController::OrthoCameraController(float aspectRatio, bool rotation, bool zoom)
    : aspectRatio(aspectRatio), 
    camera(-aspectRatio * zoomLevel, aspectRatio * zoomLevel, -zoomLevel, zoomLevel), 
    rotation(rotation), zoom(zoom) {}

    void OrthoCameraController::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowResizeEvent>(BK_BIND_DISPACHER_FN(WindowResizeEvent, OnWindowResize));
        dispatcher.dispatch<MouseScrollEvent>(BK_BIND_DISPACHER_FN(MouseScrollEvent, OnMouseScroll));
    }

    void OrthoCameraController::OnUpdate(DeltaTime dt)
    {
        if (rotation) 
        {
            if(Keyboard::KeyDown(KeyCode::Q))
                cameraRotation -= rotationSpeed * dt;
            if(Keyboard::KeyDown(KeyCode::E))
                cameraRotation += rotationSpeed * dt;
            camera.SetRotation(cameraRotation);
        }

        if(Keyboard::KeyDown(KeyCode::W))
        {
            cameraPosition.x += -std::sin(Math::radians(cameraRotation)) * moveSpeed * dt;
            cameraPosition.y += std::cos(Math::radians(cameraRotation)) * moveSpeed * dt;
        }
        if(Keyboard::KeyDown(KeyCode::S))
        {
            cameraPosition.x -= -std::sin(Math::radians(cameraRotation)) * moveSpeed * dt;
            cameraPosition.y -= std::cos(Math::radians(cameraRotation)) * moveSpeed * dt;
        }
        if(Keyboard::KeyDown(KeyCode::D))
        {
            cameraPosition.x += std::cos(Math::radians(cameraRotation)) * moveSpeed * dt;
            cameraPosition.y += std::sin(Math::radians(cameraRotation)) * moveSpeed * dt;
        }
        if(Keyboard::KeyDown(KeyCode::A)) 
        {
            cameraPosition.x -= std::cos(Math::radians(cameraRotation)) * moveSpeed * dt;
            cameraPosition.y -= std::sin(Math::radians(cameraRotation)) * moveSpeed * dt;
        }
        camera.SetPosition(cameraPosition);
    }

    bool OrthoCameraController::OnMouseScroll(MouseScrollEvent& e)
    {
        if (zoom) 
        {
            zoomLevel -= e.GetDY() * 0.01;
            zoomLevel = std::max(zoomLevel, 0.5f);
            zoomLevel = std::min(zoomLevel, 10.0f);
            camera.SetProjection(-aspectRatio * zoomLevel, aspectRatio * zoomLevel, -zoomLevel, zoomLevel);
            return true;
        }
        return false;
    }

    bool OrthoCameraController::OnWindowResize(WindowResizeEvent& e)
    {
        aspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
        camera.SetProjection(-aspectRatio * zoomLevel, aspectRatio * zoomLevel, -zoomLevel, zoomLevel);
        return false;
    }
}