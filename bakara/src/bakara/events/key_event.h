#pragma once


#include <bakara/core/key_codes.h>
#include "event.h"

namespace Bk {
    class KeyEvent : public Event 
    {
        public:
            KeyCode get_key() const { return m_key; }

            EVENT_CLASS_CATEGORY(KeyboardEvent)

        protected: 
            KeyEvent(const KeyCode key)
            : m_key(key) {}

            KeyCode m_key;
    };   

    class KeyPressEvent : public KeyEvent 
    {
        public:
            KeyPressEvent(KeyCode key, bool is_repeated = false)
            : KeyEvent(key), p_is_repeated(is_repeated) {}

            EVENT_CLASS_TYPE(KeyPress)

            EVENT_STRINGIFY("KeyPressEvent: %d repeat : %b", m_key, p_is_repeated)

            bool is_repeated() { return p_is_repeated; }

        private: 
            bool p_is_repeated;
    };

    class KeyReleaseEvent : public KeyEvent 
    {
        public:
            KeyReleaseEvent(KeyCode key)
            : KeyEvent(key) {}

            EVENT_CLASS_TYPE(KeyRelease)

            EVENT_STRINGIFY("KeyReleaseEvent: %d", m_key)
    };

    class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const KeyCode keycode)
		: KeyEvent(keycode) {}

		EVENT_CLASS_TYPE(KeyTyped)

        EVENT_STRINGIFY("KeyTypedEvent: %d", m_key)
	};
}