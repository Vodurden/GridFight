#include "Color.h"
using namespace Interface;

const Color Color::Black(0, 0, 0);
const Color Color::White(255, 255, 255);
const Color Color::Red(255, 0, 0);
const Color Color::Green(0, 255, 0);
const Color Color::Blue(0, 0, 255);
const Color Color::Yellow(255, 255, 0);
const Color Color::Magenta(255, 0, 255);
const Color Color::Cyan(0, 255, 255);

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


int Color::getR() const { return m_r; }
int Color::getG() const { return m_g; }
int Color::getB() const { return m_b; }
int Color::getA() const { return m_a; }

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


sf::Color Interface::getSFMLColor(const Color& color) 
	{
	return sf::Color(color.getR(), color.getG(), color.getB(), color.getA());
	}
