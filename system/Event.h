// THIS IS AN ALTERED VERSION OF SF::EVENT
// See www.sfml-dev.org

#ifndef GRIDFIGHT_SYSTEM_EVENT_H
#define GRIDFIGHT_SYSTEM_EVENT_H
#include "Key.h"
#include "Mouse.h"

namespace System
	{
	/**
	 * Event is an encapsulation for Keyboard and Mouse events
	 *
	 * It's used to abstract various input systems such as SFML (Player)
	 * or an AI.
	 */
	class Event
		{
		public :
	    struct KeyEvent
		    {
			System::Key Code;
	        bool      Alt;
	        bool      Control;
	        bool      Shift;
		    };

	    struct MouseMoveEvent
		    {
	        int X;
	        int Y;
		    };

	    struct MouseButtonEvent
		    {
	        System::Mouse::Button Button;
	        int           X;
	        int           Y;
		    };

	    struct MouseWheelEvent
		    {
	        int Delta;
		    };

	    struct SizeEvent
		    {
	        unsigned int Width;
	        unsigned int Height;
		    };

	    enum EventType
		    {
	        Closed,
	        Resized,
	        LostFocus,
	        GainedFocus,
	        KeyPressed,
	        KeyReleased,
	        MouseWheelMoved,
	        MouseButtonPressed,
	        MouseButtonReleased,
	        MouseMoved,
	        MouseEntered,
	        MouseLeft,
			Error,
			Ignore
		    };

	    EventType type; ///< Type of the event

	    union
		    {
	        KeyEvent         Key;
	        MouseMoveEvent   MouseMove;
	        MouseButtonEvent MouseButton;
	        MouseWheelEvent  MouseWheel;
	        SizeEvent        Size;
		    };
	};
}


#endif 
