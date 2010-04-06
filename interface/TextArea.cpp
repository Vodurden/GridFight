#include "TextArea.h"
using namespace Interface;

TextArea::TextArea( Utility::fPoint pos, Utility::fPoint size) :
	BaseRenderArea(pos, size),
	m_color(255, 255, 255, 255),
	m_size(30.0f)
	{

	}


TextArea::~TextArea()
	{

	}


void TextArea::render(sf::RenderTarget& target)
	{
	std::vector<sf::String> visualStrings;

	int currentLineVis = 0;
	std::vector<std::string> lines = Utility::splitString(m_text, "\n");

	for(std::vector<std::string>::iterator line = lines.begin();
		line != lines.end();
		++line)
		{
		unsigned int lineSize = Utility::getLengthInPixels(*line, sf::Font::GetDefaultFont(), m_size);
		/**
		 * If we are short enough we can just add the line
		 * to our lines to be rendered 
		 */
		if(lineSize < getSize().getX())
			{
			sf::String vString(*line);
			vString.SetSize(m_size);
			vString.SetColor(getSFMLColor(m_color));
			vString.SetX(getPosition().getX());
			vString.SetY(getPosition().getY() + (currentLineVis * vString.GetSize()));
			visualStrings.push_back(vString);
			currentLineVis += 1;
			}
		else
			{
			/**
			 * Split this line into small enough chunks
			 * and add them to our line array
			 */
			std::string currentLine = *line;
			std::string leftoverLine = "";

			/**
			 * Find out where the last word
			 * within our size range is
			 */
			size_t lastWordPos = Utility::findLastWordPosition(
				currentLine,
				getSize().getX(),
				sf::Font::GetDefaultFont(),
				m_size);

			// Find the new lines
			leftoverLine = currentLine.substr(lastWordPos+1);
			currentLine = currentLine.substr(0, lastWordPos);

			/**
			 * Erase the old line and append
			 * the new lines, set the iterator
			 * back to where we started to
			 * psudo-recursively deal with
			 * lines that are too long multiple
			 * times
			 */
			line = lines.erase(line);
			line -= 1;
			line = lines.insert(line+1, currentLine);
			line = lines.insert(line+1, leftoverLine);
			line -= 2;
			}
		}
	

	for(std::vector<sf::String>::iterator string = visualStrings.begin();
		string != visualStrings.end();
		++string)
		{
		target.Draw(*string);
		}
	}


void TextArea::setColor(Interface::Color color)
	{
	m_color = color;
	}


void TextArea::setSize(float size)
	{
	m_size = size;	
	}


const std::string& TextArea::getText() const
	{
	return m_text;
	}


void TextArea::setText(const std::string& text)
	{
	m_text = text;
	}
