#include "Type.h"
using namespace Utility;

Type::Type()
	{

	}


Type::Type(const std::string& name)
	{
	Module module = ModuleManager::GetDefaultModule();
	const Config& config = module.getConfigFile(module.getTypeDefinition());
	
	m_color = config.lookupf<Color>("type", name, "color");
	}


Type::~Type()
	{

	}


void Type::setColor(Color color)
	{
	m_color = color;
	}


Color Type::getColor() const
	{
	return m_color;
	}
