#ifndef GRIDFIGHT_INTERFACE_BASECONTROLLER_H
#define GRIDFIGHT_INTERFACE_BASECONTROLLER_H
#include "../utility/Point.h"
#include "../system/Event.h"
#include <queue>
namespace Interface
	{
	/**
	 * Abstract class to allow control from multiple sources.
	 * works on a two-tier system. Events and currently pressed buttons
	 *
	 * Standard event use is:
	 * \code
	 * System::Event event;
	 * while(controllerInstance.getEvent(event))
	 *	{
	 *	if(event.type == System::Event::*)
	 *		{
	 *		//do things with whatever event
	 *		}
	 *	} 
	 * \endcode
	 *
	 * See $ROOT/core/state for examples
	 */
	class BaseController
		{
		public:
			/**
			 * Deconstructor
			 */
			virtual ~BaseController();

			/**
			 * Returns the current position of the mouse.
			 */
			virtual Utility::iPoint getMousePosition() const = 0;

			/**
			 * Returns true if a given key is currently pressed
			 */
			virtual bool isKeyDown(System::Key Key) const = 0;

			/**
			 * Returns true if a given mouse button is currently pressed
			 */
			virtual bool isMouseButtonDown(System::Mouse::Button Button) const = 0;

			/**
			 * Gets the next polled event and sets out_event to it
			 */
			virtual bool getEvent(System::Event& out_event) = 0;
		protected:
			void addEvent(System::Event event);

			System::Event& getCurrentEvent();

			void moveToNextEvent();

			bool eventQueued();
		private:
			std::queue<System::Event> m_events;

			System::Event m_errorEvent;
		};
	}
#endif
