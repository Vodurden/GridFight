#include "Wrap.h"
using namespace Interface;

const Wrap::WRAP_TYPE Wrap::Enabled(INTERNAL_Enabled);
const Wrap::WRAP_TYPE Wrap::Disabled(INTERNAL_Disabled);

Wrap::Wrap(Wrap::WRAP_TYPE wrap) :
	m_wrap(wrap)
	{

	}


Wrap::Wrap(const Wrap& other) :
	m_wrap(other.m_wrap)
	{

	}

Wrap::WRAP_TYPE Wrap::getType() const
	{
	return m_wrap;
	}


void Wrap::setType(WRAP_TYPE type)
	{
	m_wrap = type;
	}

