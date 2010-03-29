#include "Grid.h"
using namespace Core;
using namespace Object;

Grid::Grid(const std::string& name)
	{
	Utility::Module module = Utility::ModuleManager::GetDefaultModule();
	const Utility::Config config = module.getConfigFile(module.getGridDefinition());

	m_gridbase = getImage(module.getRelativePath() + "/" + config.lookupf<const char*>("grid", name, "tile", "path"));


	m_pos = Utility::fPoint(
		config.lookupf<float>("grid", name, "position", "x"),
		config.lookupf<float>("grid", name, "position", "y")
		);
	
	m_size = Utility::iPoint(
		config.lookupf<int>("grid", name, "size.w"),
		config.lookupf<int>("grid", name, "size.h")
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
	// Render the tiles
	for(int y = 0; y < m_size.getY(); ++y)
		{
		for(int x = 0; x < m_size.getX(); ++x)
			{
			m_gridbase.SetX( (m_gridbase.GetSize().x * x) + m_pos.getX() );
			m_gridbase.SetY( (m_gridbase.GetSize().y * y) + m_pos.getY() );
			target.Draw(m_gridbase);
			}
		}
	}
