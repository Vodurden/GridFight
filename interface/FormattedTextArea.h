#ifndef GRIDFIGHT_INTERFACE_FORMATTEDTEXTAREA_H
#define GRIDFIGHT_INTERFACE_FORMATTEDTEXTAREA_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "BaseRenderArea.h"
#include "Style.h"
#include "Color.h"
#include "Position.h"
#include "Wrap.h"
#include "../utility/Utility.h"
#include "../utility/SFMLUtility.h"
namespace Interface
	{
	/**
	 * IOStream style visual text-area. 
	 */
	class FormattedTextArea : public BaseRenderArea
		{
		public:
			FormattedTextArea(
				Utility::fPoint pos,
				Utility::fPoint size
				);

			virtual ~FormattedTextArea();

			virtual void render(sf::RenderTarget& target);

			/**
			 * Special Style formats, see Style.h
			 */
			FormattedTextArea& operator<<(const Style& rhs);

			FormattedTextArea& operator<<(const Color& rhs);

			FormattedTextArea& operator<<(const Position& rhs);

			FormattedTextArea& operator<<(const Wrap& rhs);

			template <typename T>
			FormattedTextArea& operator<<(const T& rhs)
				{
				std::stringstream stream;
				stream << this->m_ptrCurrentTextData->text;
				stream << rhs;

				this->m_ptrCurrentTextData->text = stream.str();
				return *this;
				}

		private:
			struct TextData
				{
				TextData();
				TextData(const TextData& rhs);
			
				std::string text;
				unsigned long style;
				Color color;
				Position position;
				Wrap wrap;
				};

			TextData* copyStyleAttributes(const TextData& old) const;

			std::vector<TextData*> m_textData;
			TextData* m_ptrCurrentTextData;
		};
	}
#endif
