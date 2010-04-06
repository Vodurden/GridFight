#ifndef GRIDFIGHT_INTERFACE_TEXTAREA_H
#define GRIDFIGHT_INTERFACE_TEXTAREA_H
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <cstring>
#include <boost/tokenizer.hpp>
#include "BaseRenderArea.h"
#include "Color.h"
#include "../utility/Point.h"
#include "../utility/Utility.h"
#include "../utility/SFMLUtility.h"

namespace Interface
	{
	/**
	 * TextArea assumes that all text
	 * is left-justified
	 */
	class TextArea : public BaseRenderArea
		{
		public:
			TextArea(
				Utility::fPoint pos,
				Utility::fPoint size
				);

			virtual ~TextArea();

			virtual void render(sf::RenderTarget& target);

			template <typename T>
			friend TextArea& operator<<(TextArea& lhs, const T& rhs);

			void setColor(Interface::Color color);

			void setSize(float size);
		protected:
			const std::string& getText() const;

			void setText(const std::string& text);
		private:
			std::string m_text;

			Interface::Color m_color;

			float m_size;
		};
	

	template <typename T>
	TextArea& operator<<(TextArea& lhs, const T& rhs)
		{
		std::stringstream stream;
		stream << lhs.getText();
		stream << rhs;
		lhs.m_text = stream.str();
		return lhs;	
		}
	}
#endif
