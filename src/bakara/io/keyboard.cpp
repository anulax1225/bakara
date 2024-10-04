#include "keyboard.h"

namespace Bk 
{
    std::vector<bool> Keyboard::keys;
    std::vector<bool> Keyboard::keysChanged;

    bool Keyboard::KeyCallback(KeyEvent& e) 
    {
        //If the button is pressed or down then key is true
        if (e.get_name() == "KeyPress" || e.get_name() == "KeyRelease") keys[e.get_key()] = !keys[e.get_key()];
        else keys[e.get_key()] = false;
        //If the button is not down then keyChanged is true
        keysChanged[e.get_key()] = e.get_name() == "KeyPress" || e.get_name() == "KeyRelease";
        return false;
    }

    bool Keyboard::KeyDown(KeyCode key) 
    {
        return keys[key];
    }

    bool Keyboard::KeyWentUp(KeyCode key) 
    {
        return !keys[key] && keyChanged(key);
    }

    bool Keyboard::KeyWentDown(KeyCode key) 
    {
        return keys[key] && keyChanged(key);
    }

    bool Keyboard::keyChanged(KeyCode key) 
    {
        bool ret = keysChanged[key];
        keysChanged[key] = false;
        return ret;
    }
}