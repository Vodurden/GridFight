#include "ImageButton.h"
using namespace Interface;

ImageButton::ImageButton(Utility::fPoint pos) : Button(pos)
	{

	}

ImageButton::~ImageButton()
	{

	}

void ImageButton::draw(sf::RenderTarget& target)
	{
	m_sprite_base.SetPosition(m_pos.getX(), m_pos.getY());
	m_sprite_clicked.SetPosition(m_pos.getX(), m_pos.getY());
	m_sprite_hover.SetPosition(m_pos.getX(), m_pos.getY());

	switch(getState())
		{
		case STATE_NONE:
			target.Draw(m_sprite_base);
			break;
		case STATE_MOUSE_LBUTTON_DOWN:
			target.Draw(m_sprite_clicked);
			break;
		case STATE_MOUSE_HOVER:
			target.Draw(m_sprite_hover);
			break;
		}
	}


bool ImageButton::mouseInsideButton(Utility::fPoint pos)
	{
	if(pos.getX() > m_sprite_base.GetPosition().x &&
		pos.getX() < m_sprite_base.GetPosition().x + m_sprite_base.GetSize().x &&
		pos.getY() > m_sprite_base.GetPosition().y &&
		pos.getY() < m_sprite_base.GetPosition().y + m_sprite_base.GetSize().y
		)
		{
		return true;
		}
	return false;
	}
