#include "ConfigUnit.h"
using namespace Core;
using namespace Object;

ConfigUnit::ConfigUnit(const std::string& name)
	{
	Utility::Module& module = Utility::ModuleManager::GetDefaultModule();
	const Utility::Config& conf = module.getConfigFile(module.getUnitDefinition());

	m_health = static_cast<int>(conf.lookupf("unit", name, "attributes", "health"));
	m_damage = static_cast<int>(conf.lookupf("unit", name, "attributes", "damage"));
	m_defense = static_cast<int>(conf.lookupf("unit", name, "attributes", "defense"));
	m_range = static_cast<int>(conf.lookupf("unit", name, "attributes", "range"));
	m_attackSpeed = static_cast<int>(conf.lookupf("unit", name, "attributes", "attack_speed"));
	m_moveSpeed = static_cast<int>(conf.lookupf("unit", name, "attributes", "move_speed"));

	m_sprite.SetImage(getImage(static_cast<const char*>(conf.lookupf("unit", name.c_str(), "sprite"))));
	}


ConfigUnit::~ConfigUnit()
	{

	}


Utility::iPoint ConfigUnit::getPosition()
	{
	return m_pos;
	}


Utility::iPoint ConfigUnit::getSize()
	{
	return m_size;
	}


bool ConfigUnit::isColliding(BaseUnit& other)
	{
	Utility::iPoint o_pos = other.getPosition();
	Utility::iPoint o_size = other.getSize();
	if( m_pos.getX() >= o_pos.getX() &&
		m_pos.getX() <= o_pos.getX() + o_size.getX() &&
		m_pos.getY() + m_size.getY() >= o_pos.getY() &&
		m_pos.getY() <= o_pos.getY() + o_size.getY())
		{
		return true;
		}
	return false;
	}


void ConfigUnit::update()
	{

	}


void ConfigUnit::alignToGrid(Utility::fPoint gridTileSize)
	{
	m_sprite.SetPosition(
		m_pos.getX() * gridTileSize.getX(),
		m_pos.getY() * gridTileSize.getY()
		);
	}


void ConfigUnit::render(sf::RenderTarget& target)
	{
	target.Draw(m_sprite);
	}
