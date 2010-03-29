#include "Grid.h"
using namespace Core;
using namespace Object;

Grid::Grid(const std::string& name)
	{
	Utility::Module module = Utility::ModuleManager::GetDefaultModule();
	const Utility::Config config = module.getGridDefinition();

	m_gridbase = getImage(config.lookupf<const char*>("grid", name, "tile", "path"));


	m_pos = Utility::fPoint(
		config.lookupf<float>("grid", name, "position", "x"),
		config.lookupf<float>("grid", name, "position", "y")
		);
	
	m_size = Utility::iPoint(
		config.lookupf<int>("grid", name, "position.x"),
		config.lookupf<int>("grid", name, "position.y")
		);
	}


Grid::~Grid()
	{
	for(std::vector<Group*>::iterator group = m_groups.begin();
		group != m_groups.end();
		++group)
		{
		delete *group;
		}
	}


void Grid::addGroup(Group* group)
	{
	m_groups.push_back(group);
	}


void Grid::update()
	{

	}


void Grid::render(sf::RenderTarget& target)
	{
	// Render the tile pattern
	}
