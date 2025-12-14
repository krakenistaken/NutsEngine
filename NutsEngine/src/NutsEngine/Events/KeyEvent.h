#pragma once

#include "NutsEngine/Events/Event.h"

namespace NutsEngine {



	class NUTSENGINE_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(ECategoryKey | ECategoryInput)
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {
		}

		int m_KeyCode;
	};

	class NUTSENGINE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCounter)
			: KeyEvent(keycode), m_repeatCounter(repeatCounter) {}

		inline int GetRepeatCount() const { return m_repeatCounter; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (repeat = " << m_repeatCounter << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		bool m_repeatCounter;
	};





	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};


}