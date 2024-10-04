#include "mouse.h"
namespace Bk
{
    double Mouse::x = 0;
    double Mouse::y = 0;

    double Mouse::lastX = 0;
    double Mouse::lastY = 0;

    double Mouse::dX = 0;
    double Mouse::dY = 0;

    double Mouse::scrollDX = 0;
    double Mouse::scrollDY = 0;

    bool Mouse::firstMouse;

    std::vector<bool> Mouse::buttons = { 0 };
    std::vector<bool> Mouse::buttonsChanged = { 0 };

    bool Mouse::CursorCallback(MouseMoveEvent& e) {
        x = e.get_x();
        y = e.get_y();

        if(firstMouse) {
            lastX = x;
            lastY = y;
            firstMouse = false;
        }
        dX = x - lastX;
        dY = y -lastY;
        lastX = x;
        lastY = y;
        return false;
    }

    bool Mouse::ButtonCallback(MouseButtonEvent& e) {
        if (e.get_name() != "MouseButtonRelease") {
            if(!buttons[e.get_btn()]) {
                buttons[e.get_btn()] = true;
            }
        } else {
            buttons[e.get_btn()] = false;
        }

        buttonsChanged[e.get_btn()] = true;
        return false;
    }

    bool Mouse::WheelCallback(MouseScrollEvent& e) {
        scrollDX = e.get_dx();
        scrollDY = e.get_dy();
        return false;
    } 

    Vec2 Mouse::GetPosition() {
        return Vec2(x, y);
    }

    double Mouse::GetDX() {
        double _dX = dX;
        dX = 0;
        return _dX;
    }

    double Mouse::GetDY() {
        double _dY = dY;
        dY = 0;
        return _dY;
    }

    double Mouse::GetScrollDX() {
        double _scrollDX = scrollDX;
        scrollDX = 0;
        return _scrollDX;
    }

    double Mouse::GetScrollDY() {
        double _scrollDY = scrollDY;
        scrollDY = 0;
        return _scrollDY;
    } 

    bool Mouse::Button(MouseCode button) {
        return buttons[button];
    }

    bool Mouse::ButtonUp(MouseCode button) {
        return !buttons[button] && buttonChanged(button);
    }

    bool Mouse::ButtonDown(MouseCode button) {
        return buttons[button] && buttonChanged(button);
    }

    bool Mouse::buttonChanged(MouseCode button) {
        bool ret = buttonsChanged[button];
        buttons[button] = false;
        return ret;
    }
}