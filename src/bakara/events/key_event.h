#pragma once

#include "bakara/io/key_codes.h"
#include "event.h"

namespace Bk {
    class KeyEvent : public Event 
    {
        public:
            Code get_key() const { return m_key; }

            EVENT_CLASS_CATEGORY(KeyboardCategory | InputCategory)

        protected: 
            KeyEvent(const Code key)
            : m_key(key) {}

            Code m_key;
    };   

    class KeyPressEvent : public KeyEvent 
    {
        public:
            KeyPressEvent(Code key, bool IsRepeated = false)
            : KeyEvent(key), p_is_repeated(IsRepeated) {}

            EVENT_CLASS_TYPE(KeyPress)

            EVENT_STRINGIFY("KeyPressEvent: %d repeat : %b", m_key, p_is_repeated)

            bool IsRepeated() { return p_is_repeated; }

        private: 
            bool p_is_repeated;
    };

    class KeyReleaseEvent : public KeyEvent 
    {
        public:
            KeyReleaseEvent(Code key)
            : KeyEvent(key) {}

            EVENT_CLASS_TYPE(KeyRelease)

            EVENT_STRINGIFY("KeyReleaseEvent: %d", m_key)
    };

    class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const Code keycode)
		: KeyEvent(keycode) {}

		EVENT_CLASS_TYPE(KeyTyped)

        EVENT_STRINGIFY("KeyTypedEvent: %d", m_key)
	};
}