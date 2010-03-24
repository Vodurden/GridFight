#ifndef GRIDFIGHT_INTERFACE_SFMLCONTROLLER_H
#define GRIDFIGHT_INTERFACE_SFMLCONTROLLER_H
#include <SFML/Window.hpp>
#include "BaseController.h"
namespace Interface
	{

	class SFMLController : public BaseController
		{
		public:
			SFMLController(sf::Window& window);

			~SFMLController();

			Utility::iPoint getMousePosition() const;

			bool isKeyDown(System::Key Key) const;

			bool isMouseButtonDown(System::Mouse::Button Button) const;

			bool getEvent(System::Event& out_event);

			void allowAutoClose(const bool close);
		private:
			sf::Window& m_refWindow;

			bool m_allowAutoClose;

			System::Event SFMLEventToSystemEvent(sf::Event& event);
		};
	}
#endif
