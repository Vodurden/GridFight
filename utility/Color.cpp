#include "Color.h"
using namespace Utility;

Color::Color() :
	m_r(0),
	m_g(0),
	m_b(0),
	m_a(0)
	{

	}


Color::Color(libconfig::Setting& colorSetting) :
	m_r(static_cast<int>(colorSetting["r"])),
	m_g(static_cast<int>(colorSetting["g"])),
	m_b(static_cast<int>(colorSetting["b"])),
	m_a(static_cast<int>(colorSetting["a"]))
	{

	}


Color::Color(const int r, const int g, const int b, const int a) :
	m_r(r),
	m_g(g),
	m_b(b),
	m_a(a)
	{

	}


Color::~Color()
	{

	}


int Color::getR() { return m_r; }
int Color::getG() { return m_g; }
int Color::getB() { return m_b; }
int Color::getA() { return m_a; }

void Color::setR(int r) { m_r = r; }
void Color::setG(int g) { m_g = g; }
void Color::setB(int b) { m_b = b; }
void Color::setA(int a) { m_a = a; }


void Color::set(int r, int g, int b, int a)
	{
	m_r = r;
	m_g = g;
	m_b = b;
	m_a = a;
	}


sf::Color getSFMLColor(Color& color)
	{
	return sf::Color(color.getR(), color.getG(), color.getB(), color.getA());
	}
