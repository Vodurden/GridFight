#ifndef GRIDFIGHT_INTERFACE_TEXTRECTBUTTON_H
#define GRIDFIGHT_INTERFACE_TEXTRECTBUTTON_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Button.h"
#include "../utility/Point.h"
namespace Interface
	{
	class TextRectButton : public Button
		{
		public:
			TextRectButton(Utility::fPoint pos);

			virtual ~TextRectButton();

			bool mouseInsideButton(Utility::fPoint pos);

			void draw(sf::RenderTarget& target);

			void setSize(float w, float h);

			void setText(const std::string& text);
			void setTextSize(float size);

			void setSize(Utility::fPoint size);

			void setBaseColor(int r, int g, int b, int a);
			void setHoverColor(int r, int g, int b, int a);
			void setClickColor(int r, int g, int b, int a);

			void setTextBaseColor(int r, int g, int b, int a);
			void setTextHoverColor(int r, int g, int b, int a);
			void setTextClickColor(int r, int g, int b, int a);

			void setBorderThickness(int t);
			void setBorderBaseColor(int r, int g, int b, int a);
			void setBorderHoverColor(int r, int g, int b, int a);
			void setBorderClickColor(int r, int g, int b, int a);
		private:
			void applyColors(sf::Color& rect, sf::Color& text, sf::Color& border);

			void centerText();

			friend class ButtonFactory;

			sf::Shape m_shape;
			sf::String m_text;

			sf::Color m_baseColor;
			sf::Color m_baseHoverColor;
			sf::Color m_baseClickColor;

			sf::Color m_textColor;
			sf::Color m_textHoverColor;
			sf::Color m_textClickColor;

			int m_borderThickness;
			sf::Color m_borderColor;
			sf::Color m_borderHoverColor;
			sf::Color m_borderClickColor;

			float m_w, m_h;
		};
	}
#endif
