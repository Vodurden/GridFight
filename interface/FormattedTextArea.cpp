#include "FormattedTextArea.h"
using namespace Interface;

FormattedTextArea::FormattedTextArea(
	Utility::fPoint pos,
	Utility::fPoint size) :
	BaseRenderArea(pos, size)
	{
	m_textData.push_back(new TextData());
	m_ptrCurrentTextData = m_textData.back();
	}


FormattedTextArea::~FormattedTextArea()
	{
	for(std::vector<TextData*>::iterator textData = m_textData.begin();
		textData != m_textData.end();
		++textData)
		{
		delete *textData;
		}
	}

	
FormattedTextArea& FormattedTextArea::operator<<(const Style& rhs)
	{
	if(m_ptrCurrentTextData->text != "")
		{
		m_textData.push_back(copyStyleAttributes(*m_ptrCurrentTextData));
		m_ptrCurrentTextData = m_textData.back();
		}
			
	// 0 is equivilent to regular
	if(rhs.getType() == 0)
		{
		m_ptrCurrentTextData->style = 0;
		}
	else
		{
		m_ptrCurrentTextData->style |= rhs.getType();
		}
	return *this;
	}


FormattedTextArea& FormattedTextArea::operator<<(const Color& rhs)
	{
	// Add a new TextData with the old ones attributes (sans text)	
	if(m_ptrCurrentTextData->text != "")
		{
		m_textData.push_back(copyStyleAttributes(*m_ptrCurrentTextData));
		m_ptrCurrentTextData = m_textData.back();
		}

	m_ptrCurrentTextData->color = rhs;
	return *this;
	}


FormattedTextArea& FormattedTextArea::operator<<(const Position& rhs)
	{
	if(m_ptrCurrentTextData->text != "")
		{
		m_textData.push_back(copyStyleAttributes(*m_ptrCurrentTextData));
		m_ptrCurrentTextData = m_textData.back();
		}

	m_ptrCurrentTextData->position = rhs;
	return *this;
	}


/*void FormattedTextArea::render(sf::RenderTarget& target)
	{
	std::vector<sf::String> visualStrings;

	Utility::fPoint cursorPos = getPosition();

	POSITION_TYPE currentPositionType;
	for(std::vector<TextData*>::iterator textData = m_textData.begin();
		textData != m_textData.end();
		++textData)
		{
		// Split the text into a collection of new-lines
		std::vector<std::string> lines = Utility::splitString((*textData)->text, "\n");

		currentPositionType = (*textData)->position.getType();

		for(std::vector<std::string>::iterator line = lines.begin();
			line != lines.end();
			++line)
			{
			std::cout << "for line: " << *line << std::endl;

			// If the length of the next amount of text to write plus our cursor
			// is beyond the boundry then it needs to be split
			float lineSize = Utility::getLengthInPixels(*line, sf::Font::GetDefaultFont(), 30.0f) + cursorPos.getX();
			std::cout << "LineSize: " << lineSize << std::endl;
			if(lineSize < getSize().getX())
				{
				std::cout << "Printing line: " << *line << std::endl;
				 if(currentPositionType != (*textData)->position.getType())
				 	{
					switch((*textData)->position.getType())
						{
						case Position_Left:
							cursorPos.setX(getPosition().getX());
							break;
						case Position_Center:
							cursorPos.setX((getPosition().getX() + (getSize().getX() / 2)) - (lineSize / 2));
							break;
						case Position_Right:
							cursorPos.setX(getPosition().getX() + getSize().getX() - lineSize);
							break;
						}
					currentPositionType = (*textData)->position.getType();
					}
				std::cout << "At pos: (" << cursorPos.getX() << "," << cursorPos.getY() << ")\n";

				sf::String vString(*line);
				vString.SetX(cursorPos.getX());
				vString.SetY(cursorPos.getY());
				vString.SetColor(getSFMLColor((*textData)->color));
				vString.SetStyle((*textData)->style);		
				visualStrings.push_back(vString);

				cursorPos.setX(cursorPos.getX());
				}
			else
				{
				std::cout << "Splitting line: " << *line << std::endl;
				std::string currentLine = *line;
				std::string leftoverLine = "";

				size_t lastWordPos = Utility::findLastWordPosition(
					currentLine,
					getSize().getX(),
					sf::Font::GetDefaultFont(),
					30.0f);

				leftoverLine = currentLine.substr(lastWordPos+1);
				currentLine = currentLine.substr(0, lastWordPos);

				line = lines.erase(line);
				line -= 1;
				line = lines.insert(line+1, leftoverLine);
				line -= 1;

				sf::String vString(*line);
				vString.SetX(cursorPos.getX());
				vString.SetY(cursorPos.getY());
				vString.SetColor(getSFMLColor((*textData)->color));
				vString.SetStyle((*textData)->style);
				visualStrings.push_back(vString);

				cursorPos.setX(getPosition().getX());

				std::cout << "VContents: " << std::endl;
				for(std::vector<std::string>::iterator s = lines.begin();
					s != lines.end();
					++s)
					{
					std::cout << "\t" << *s << std::endl;
					}
				}
			}

		}
	
	for(std::vector<sf::String>::iterator vString = visualStrings.begin();
		vString != visualStrings.end();
		++vString)
		{
		target.Draw(*vString);	
		}
	}*/


void FormattedTextArea::render(sf::RenderTarget& target)
	{
	typedef std::pair<Utility::fPoint, std::string> StringPoint;

	/**
	 * work out where to put this string based on:
	 * 	-> Try to place it at the end of a string of
	 *		the same alignment
	 *	-> Too long? Split it and try again
	 */
	
	POSITION_TYPE currentPositionType = Position::Left.getType();
	Utility::fPoint cursor(getPosition().getX(), getPosition().getY());
	for(std::vector<TextData*>::iterator data = m_textData.begin();
		data != m_textData.end();
		++data)
		{
		std::vector<std::string> lines = Utility::splitString((*data)->text, "\n");
		std::vector<StringPoint> linePoints;

		// Go through each line and work out where it needs to be
		for(std::vector<std::string>::iterator line = lines.begin();
			line != lines.end();
			++line)
			{
			std::cout << "Analyzing string: " << *line << std::endl;
			//Are we short enough to simply place wehre the cursor is
			float lineLengthPx = Utility::getLengthInPixels(*line);
			float spaceTaken = lineLengthPx + (cursor.getX() - getPosition().getX());
			if(spaceTaken < getSize().getX())
				{
				std::cout << "\tPrinting" << std::endl;
				// We are short enough, append us where we need to be and
				// move the cursor after us

				float workingX = 0.0f;
				// Work out based on alignment
				switch((*data)->position.getType())
					{
					case Position_Left:
						workingX = getPosition().getX();
						break;
					case Position_Center:
						workingX = getPosition().getX() + 
							(getSize().getX() / 2) -
							(lineLengthPx / 2);
						break;
					case Position_Right:
						workingX = getPosition().getX() + getSize().getX() - lineLengthPx;
						break;
					}

				// Reset the X values if we've changed type
				if((*data)->position.getType() != currentPositionType)
					{
					std::cout << "\tType change detected" << std::endl;
					cursor.setX(workingX);
					currentPositionType = (*data)->position.getType();
					}
				else
					{
					cursor.setX((cursor.getX() - getPosition().getX()) + workingX);
					}

				std::cout << "\tCursor: (" << cursor.getX() << ", " << cursor.getY() << ")\n";

				//Draw something at cursor.x/y
				sf::String vString(*line);
				vString.SetPosition(cursor.getX(), cursor.getY());
				vString.SetColor(getSFMLColor((*data)->color));
				vString.SetStyle((*data)->style);
				target.Draw(vString);

				//Move the cursor forward(X)
				std::cout << "\t Moving Cursor:\n";
				cursor.setX(cursor.getX() + lineLengthPx);

				//If we are not the only element left or there is a \n at the end of the original data
				// then the cursor is moved down
				if(lines.size() > 1 || (*data)->text.at((*data)->text.length()-1) == '\n')
					{
					std::cout << "\tNewline detected, Moving down\n";
					cursor.setY(cursor.getY() + 30.0f);
					cursor.setX(getPosition().getX());
					}
				std::cout << "\t\t (" << cursor.getX() << ", " << cursor.getY() << ")\n";
				}
			else // We need to split ourselves up, and put us back for re-evaluation
				{
				std::cout << "\tSplitting" << std::endl;
				
				std::cout << "LengthX: " << lineLengthPx << std::endl;
				std::cout << "SizeTakenX: " << spaceTaken << std::endl;
				std::cout << "SizeX: " << getSize().getX() << std::endl;
				std::cout << "CursorX: " << cursor.getX() - getPosition().getX() << std::endl;
				size_t lastWordPos = Utility::findLastWordPosition(
					*line,
					getSize().getX() - (cursor.getX() - getPosition().getX()),
					sf::Font::GetDefaultFont(),
					30.0f);

				std::string currentString = line->substr(0, lastWordPos);
				std::string leftoverString = line->substr(lastWordPos+1);
				std::cout << "CurrentString: " << currentString << std::endl;
				std::cout << "LeftoverString: " << leftoverString << std::endl;

				line = lines.erase(line);
				line -= 1;
				line = lines.insert(line+1, currentString);
				line = lines.insert(line+1, leftoverString);
				line -= 2;

				std::cout << "Vector: " << std::endl;
				for(std::vector<std::string>::iterator s = lines.begin();
					s != lines.end();
					++s)
					{
					std::cout << "\t" << *s << std::endl;
					}
				}
			}
		}
	}


//+++++++++++++++++++++++++++
//   TextData Definitions
//+++++++++++++++++++++++++++
FormattedTextArea::TextData::TextData() :
	text(""),
	style(Style::Regular.getType()),
	color(Color::White),
	position(Position::Left)
	{
		
	}


FormattedTextArea::TextData::TextData(const FormattedTextArea::TextData& rhs) :
	text(rhs.text),
	style(rhs.style),
	color(rhs.color),
	position(rhs.position)
	{

	}

FormattedTextArea::TextData* FormattedTextArea::copyStyleAttributes(const TextData& old) const
	{
	TextData* ret = new TextData();
	ret->style = old.style;
	ret->color = old.color;
	ret->position = old.position;
	return ret;
	}
