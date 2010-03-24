#include "TextRectButton.h"
using namespace Interface;

TextRectButton::TextRectButton(Utility::fPoint pos) :
	Button(pos)
	{
	m_text.SetPosition(pos.getX(), pos.getY());
	m_shape.SetPosition(pos.getX(), pos.getY());
	}

TextRectButton::~TextRectButton()
	{

	}

bool TextRectButton::mouseInsideButton(Utility::fPoint pos)
	{
	if(pos.getX() > m_shape.GetPosition().x &&
		pos.getX() < m_shape.GetPosition().x + m_w &&
		pos.getY() > m_shape.GetPosition().y &&
		pos.getY() < m_shape.GetPosition().y + m_h)
		{
		return true;
		}
	return false;
	}

void TextRectButton::applyColors(sf::Color& rect, sf::Color& text, sf::Color& border)
	{
	m_text.SetColor(text);

	//Set the outline and center to the correct color
	for(unsigned int pointIndex = 0; pointIndex < m_shape.GetNbPoints(); ++pointIndex)
		{
		m_shape.SetPointColor(pointIndex, rect);
		m_shape.SetPointOutlineColor(pointIndex, border);
		}
	}

void TextRectButton::draw(sf::RenderTarget& target)
	{
	//Apply the correct colours
	m_shape.SetOutlineWidth(m_borderThickness);
	centerText();
	switch(getState())
		{
		case STATE_NONE:
			applyColors(m_baseColor, m_textColor, m_borderColor);
			break;
		case STATE_MOUSE_HOVER:
			applyColors(m_baseHoverColor, m_textHoverColor, m_borderHoverColor);
			break;
		case STATE_MOUSE_LBUTTON_DOWN:
			applyColors(m_baseClickColor, m_textClickColor, m_borderClickColor);
			break;
		}
	
	target.Draw(m_shape);
	target.Draw(m_text);
	}

void TextRectButton::centerText()
	{
	Utility::fPoint buttonPos = getPosition();
	float posX = buttonPos.getX() + (m_w / 2) - (m_text.GetRect().GetWidth() / 2);
	float posY = buttonPos.getY() + (m_h / 2) - (m_text.GetRect().GetHeight() / 2);
	m_text.SetPosition(posX, posY);
	}

void TextRectButton::setSize(float w, float h)
	{
	Utility::fPoint pos = getPosition();
	m_shape = sf::Shape::Rectangle(
		0, 0,
		w, h,
		sf::Color(0, 0, 0)
		);
	m_shape.SetPosition(pos.getX(), pos.getY());
	m_w = w;
	m_h = h;
	centerText();
	}

void TextRectButton::setText(const std::string& text)
	{
	m_text.SetText(text);
	centerText();
	}

void TextRectButton::setTextSize(float size)
	{
	m_text.SetSize(size);
	centerText();
	}

void TextRectButton::setBaseColor(int r, int g, int b, int a)
	{
	m_baseColor = sf::Color(r, g, b, a);
	}

void TextRectButton::setHoverColor(int r, int g, int b, int a)
	{
	m_baseHoverColor = sf::Color(r, g, b, a);
	}

void TextRectButton::setClickColor(int r, int g, int b, int a)
	{
	m_baseClickColor = sf::Color(r, g, b, a);
	}

void TextRectButton::setTextBaseColor(int r, int g, int b, int a)
	{
	m_textColor = sf::Color(r, g, b, a);
	}

void TextRectButton::setTextHoverColor(int r, int g, int b, int a)
	{
	m_textHoverColor = sf::Color(r, g, b, a);
	}

void TextRectButton::setTextClickColor(int r, int g, int b, int a)
	{
	m_textClickColor = sf::Color(r, g, b, a);
	}

void TextRectButton::setBorderThickness(int t)
	{
	m_borderThickness = t;
	}

void TextRectButton::setBorderBaseColor(int r, int g, int b, int a)
	{
	m_borderColor = sf::Color(r, g, b, a);
	}

void TextRectButton::setBorderHoverColor(int r, int g, int b, int a)
	{
	m_borderHoverColor = sf::Color(r, g, b, a);
	}

void TextRectButton::setBorderClickColor(int r, int g, int b, int a)
	{
	m_borderClickColor = sf::Color(r, g, b, a);
	}
