#ifndef GRIDFIGHT_INTERFACE_IMAGEBUTTON_H
#define GRIDFIGHT_INTERFACE_IMAGEBUTTON_H
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "../utility/Point.h"
namespace Interface
	{
	class ImageButton : public Button
		{
		public:
			ImageButton(Utility::fPoint pos);

			virtual ~ImageButton();

			bool mouseInsideButton(Utility::fPoint pos);

			void draw(sf::RenderTarget& target);
		private:
			friend class ButtonFactory;

			sf::Sprite m_sprite_base;
			sf::Sprite m_sprite_clicked;
			sf::Sprite m_sprite_hover;
		};
	}
#endif
