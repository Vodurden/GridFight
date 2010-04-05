#include "TextArea.h"
using namespace Interface;

TextArea::TextArea(
	Utility::fPoint pos,
	Utility::fPoint size
	) :
	BaseRenderArea(pos, size)
	{

	}


TextArea::~TextArea()
	{

	}


void TextArea::render(sf::RenderTarget& target)
	{

	std::vector<sf::String> visualStrings;

	// Split the text into lines
	int currentLine = 0;
	boost::char_separator<char> seperator("\n");
	boost::tokenizer<boost::char_separator<char> > tok(m_text, seperator);
	for(boost::tokenizer<boost::char_separator<char> >::iterator line = tok.begin();
		line != tok.end();
		++line)
		{
		//Create a test visual string to see how long we are
		sf::String testStr(*line);
		unsigned int lineSize = (testStr.GetCharacterPos(line->length()-1) -
			testStr.GetCharacterPos(0)).x;
		/**
		 * If we are short enough we can just add the line
		 * to our lines to be rendered 
		 */
		if(lineSize < getSize().getX())
			{
			sf::String vString(*line);
			vString.SetX(getPosition().getX());
			vString.SetY(getPosition().getY() + (currentLine * vString.GetSize()));
			visualStrings.push_back(vString);
			}
		else
			{
			// We need to do some splitting
						
			}
		currentLine += 1;
		}
	

	for(std::vector<sf::String>::iterator string = visualStrings.begin();
		string != visualStrings.end();
		++string)
		{
		target.Draw(*string);
		}
	}


const std::string& TextArea::getText() const
	{
	return m_text;
	}


void TextArea::setText(const std::string& text)
	{
	m_text = text;
	}
