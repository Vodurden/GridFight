#ifndef GRIDFIGHT_INTERFACE_BUTTON_H
#define GRIDFIGHT_INTERFACE_BUTTON_H
#include <SFML/Graphics.hpp>
#include "BaseController.h"
#include "../utility/Point.h"
namespace Interface
	{
	class Button 
		{
		public:
			Button(Utility::fPoint pos);

			virtual ~Button();

			enum State
				{
				STATE_NONE,
				STATE_MOUSE_LBUTTON_DOWN,
				STATE_MOUSE_HOVER
				};

			void setPosition(Utility::fPoint pos);

			Utility::fPoint getPosition();

			virtual bool mouseInsideButton(Utility::fPoint pos) = 0;

			virtual void draw(sf::RenderTarget& target) = 0;

			State getState();

			void setState(const State& state);
		protected:
			friend class ButtonFactory;

			State m_state;

			Utility::fPoint m_pos;
		};
	}
#endif
