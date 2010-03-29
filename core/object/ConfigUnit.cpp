#include "ConfigUnit.h"
using namespace Core;
using namespace Object;

ConfigUnit::ConfigUnit(const std::string& name, const Utility::fPoint gridTileSize) :
	m_pos(0, 0),
	m_size(0, 0),
	m_offset(0, 0),
	m_gridTileSize(gridTileSize)
	{
	Utility::Module& module = Utility::ModuleManager::GetDefaultModule();
	const Utility::Config& conf = module.getConfigFile(module.getUnitDefinition());

	m_type = conf.lookupf<Utility::Type>("unit", name, "attributes", "type");

	m_health = conf.lookupf<int>("unit", name, "attributes", "health");
	m_damage = conf.lookupf<int>("unit", name, "attributes", "damage");
	m_defense = conf.lookupf<int>("unit", name, "attributes", "defense");
	m_range = conf.lookupf<int>("unit", name, "attributes", "range");
	m_attackSpeed = conf.lookupf<int>("unit", name, "attributes", "attack_speed");
	m_moveSpeed = conf.lookupf<int>("unit", name, "attributes", "move_speed");

	std::string sprite_path = 
		module.getRelativePath() + "/" +
		conf.lookupf<const char*>("unit", name.c_str(), "sprite");

	m_sprite.SetImage(getImage(sprite_path));
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


Utility::Type ConfigUnit::getType()
	{
	return m_type;
	}


void ConfigUnit::setPosition(Utility::iPoint pos)
	{
	m_pos = pos;
	}


void ConfigUnit::setSize(Utility::iPoint size)
	{
	m_size = size;
	}


void ConfigUnit::setOffset(Utility::fPoint offset)
	{
	m_offset = offset;
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
	// Make sure we are aligned to the grid
	m_sprite.SetPosition(
		(m_pos.getX() * m_gridTileSize.getX()) + m_offset.getX(),
		(m_pos.getY() * m_gridTileSize.getY()) + m_offset.getY()
		);
	}

void ConfigUnit::render(sf::RenderTarget& target)
	{
	target.Draw(m_sprite);
	}
