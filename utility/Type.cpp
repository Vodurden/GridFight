#include "Type.h"
using namespace Utility;

Type::Type()
	{

	}


Type::Type(const std::string& name)
	{
	Module module = ModuleManager::GetDefaultModule();
	const Config& config = module.getConfigFile(module.getTypeDefinition());
	
	m_color = config.lookupf<Interface::Color>("type", name, "color");
	}


Type::~Type()
	{

	}


void Type::setColor(Interface::Color color)
	{
	m_color = color;
	}


Interface::Color Type::getColor() const
	{
	return m_color;
	}
