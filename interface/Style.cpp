#include "Style.h"
using namespace Interface;

const Style Style::Regular(Interface::INTERNAL_Regular);
const Style Style::Bold(Interface::INTERNAL_Bold);
const Style Style::Italic(Interface::INTERNAL_Italic);
const Style Style::Underlined(Interface::INTERNAL_Underlined);



Style::Style(STYLE_TYPE type) :
	m_type(type)
	{

	}


Style::Style(const Style& rhs) :
	m_type(rhs.m_type)
	{

	}


STYLE_TYPE Style::getType() const
	{
	return m_type;
	}


void Style::setType(STYLE_TYPE type)
	{
	m_type = type;
	}
