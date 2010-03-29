#include "Grid.h"
using namespace Core;
using namespace Object;

Grid::Grid(const std::string& name)
	{
	Utility::Module module = Utility::ModuleManager::GetDefaultModule();
	const Utility::Config config = module.getConfigFile(module.getGridDefinition());

	m_gridBase = getImage(module.getRelativePath() + "/" + config.lookupf<const char*>("grid", name, "tile", "path"));


	m_pos = Utility::fPoint(
		config.lookupf<float>("grid", name, "position", "x"),
		config.lookupf<float>("grid", name, "position", "y")
		);
	
	m_size = Utility::iPoint(
		config.lookupf<int>("grid", name, "size.w"),
		config.lookupf<int>("grid", name, "size.h")
		);
	
	m_gridBaseColor = config.lookupf<Utility::Color>("grid", name, "tile", "color");
	m_alphaSquareColor = config.lookupf<Utility::Color>("grid", name, "tile", "alpha");
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
	// Move the groups "Forward"


	// Update the groups
	for(std::vector<Group*>::iterator group = m_groups.begin();
		group != m_groups.end();
		++group)
		{
		(*group)->update();
		}
	}


void Grid::render(sf::RenderTarget& target)
	{
	renderGridTiles(target);
	renderCheckerPattern(target);
	renderUnitSprites(target);
	}


Utility::fPoint Grid::getTileSize()
	{
	return Utility::fPoint(m_gridBase.GetSize().x, m_gridBase.GetSize().y);
	}


void Grid::renderGridTiles(sf::RenderTarget& target)
	{
	m_gridBase.SetColor(getSFMLColor(m_gridBaseColor));
	for(int y = 0; y < m_size.getY(); ++y)
		{
		for(int x = 0; x < m_size.getX(); ++x)
			{
			m_gridBase.SetX( (m_gridBase.GetSize().x * x) + m_pos.getX() );
			m_gridBase.SetY( (m_gridBase.GetSize().y * y) + m_pos.getY() );
			target.Draw(m_gridBase);
			}
		}
	}


void Grid::renderUnitSprites(sf::RenderTarget& target)
	{
	for(std::vector<Group*>::iterator group = m_groups.begin();
		group != m_groups.end();
		++group)
		{
		(*group)->setOffset(m_pos);
		(*group)->render(target);	
		}
	}


void Grid::renderCheckerPattern(sf::RenderTarget& target)
	{
	m_gridBase.SetX(0.0f);
	m_gridBase.SetY(0.0f);
	sf::Shape alphaRect = sf::Shape::Rectangle(
		m_gridBase.GetPosition().x,
		m_gridBase.GetPosition().y,
		m_gridBase.GetPosition().x + m_gridBase.GetSize().x,
		m_gridBase.GetPosition().y + m_gridBase.GetSize().y,
		getSFMLColor(m_alphaSquareColor)
		);
	
	bool renderAlpha = true;
	for(int y = 0; y < m_size.getY(); ++y)
		{
		for(int x = 0; x < m_size.getX(); ++x)
			{
			if(renderAlpha)
				{
				alphaRect.SetX((x * m_gridBase.GetSize().x) + m_pos.getX());
				alphaRect.SetY((y * m_gridBase.GetSize().y) + m_pos.getY());
				target.Draw(alphaRect);
				}
			renderAlpha = !renderAlpha;
			}
		renderAlpha = !renderAlpha;
		}
	}
