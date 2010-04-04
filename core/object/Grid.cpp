#include "Grid.h"
using namespace Core;
using namespace Object;

Grid::Grid(const std::string& name) :
	m_groupBorderSize(2)
	{
	Utility::Module module = Utility::ModuleManager::GetDefaultModule();
	const Utility::Config config = module.getConfigFile(module.getGridDefinition());

	m_gridBase = getImage(module.getRelativePath() + "/" + 
		config.lookupf<const char*>("grid", name, "tile", "path")
		);
	m_boundryLine = getImage(module.getRelativePath() + "/" +
		config.lookupf<const char*>("grid", name, "boundry", "path")
		);

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
	m_boundryPosition = ceil(m_size.getX() / 2);
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
	for(std::vector<Group*>::iterator group = m_groups.begin();
		group != m_groups.end();
		++group)
		{
		(*group)->advance();
		
		if(isColliding(**group) || isInInvalidPosition(**group))
			{
			(*group)->retreat();
			}
		}


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
	renderUnitTiles(target);
	renderCheckerPattern(target);
	renderGroupBorders(target);
	renderUnitSprites(target);
	renderGridBoundry(target);
	}


Utility::fPoint Grid::getTileSize()
	{
	return Utility::fPoint(m_gridBase.GetSize().x, m_gridBase.GetSize().y);
	}


bool Grid::isColliding(Group& group)
	{
	for(std::vector<Group*>::iterator ogroup = m_groups.begin();
		ogroup != m_groups.end();
		++ogroup)
		{
		//Skip if we are the same group
		if( &group == *ogroup )
			{
			continue;
			}

		if( group.isColliding(**ogroup) )
			{
			return true;
			}
		}
	return false;
	}


bool Grid::isInInvalidPosition(Group& group)
	{
	return group.isBeyondBoundry(m_boundryPosition);
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


void Grid::renderUnitTiles(sf::RenderTarget& target)
	{
	m_gridBase.SetX(0.0f);
	m_gridBase.SetY(0.0f);
	for(std::vector<Group*>::iterator group = m_groups.begin();
		group != m_groups.end();
		++group)
		{
		for(Group::iterator unit = (*group)->begin();
			unit != (*group)->end();
			++unit)
			{
			sf::Shape unitBase = sf::Shape::Rectangle(
				m_gridBase.GetPosition().x,
				m_gridBase.GetPosition().y,
				m_gridBase.GetPosition().x + m_gridBase.GetSize().x,
				m_gridBase.GetPosition().y + m_gridBase.GetSize().y,
				getSFMLColor((*unit)->getType().getColor())
				);

			Utility::iPoint pos = (*unit)->getPosition();
			unitBase.SetX( (pos.getX() * m_gridBase.GetSize().x) + m_pos.getX() );
			unitBase.SetY( (pos.getY() * m_gridBase.GetSize().y) + m_pos.getY() );
			target.Draw(unitBase);
			}
		}
	}


void Grid::renderGroupBorders(sf::RenderTarget& target)
	{
	for(std::vector<Group*>::iterator group = m_groups.begin();
		group != m_groups.end();
		++group)
		{
		for(Group::iterator unit = (*group)->begin();
			unit != (*group)->end();
			++unit)
			{
			std::vector<std::pair<Utility::fPoint, Utility::fPoint> > points((*group)->getUnitBorderPoints(
				**unit,
				getTileSize()
				));

			for(std::vector<std::pair<Utility::fPoint, Utility::fPoint> >::iterator point = points.begin();
				point != points.end();
				++point)
				{
				sf::Shape line = sf::Shape::Line(
					point->first.getX(), point->first.getY(),
					point->second.getX(), point->second.getY(),
					m_groupBorderSize, 
					getSFMLColor((*unit)->getType().getColor()) * sf::Color(150, 150, 150, 255)
					);

				Utility::iPoint pos = (*unit)->getPosition();
				line.SetX( ( pos.getX() * m_gridBase.GetSize().x) + m_pos.getX());
				line.SetY( ( pos.getY() * m_gridBase.GetSize().y) + m_pos.getY());
				target.Draw(line);
				}
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
	
	bool renderAlpha = false;
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


void Grid::renderGridBoundry(sf::RenderTarget& target)
	{
	m_boundryLine.SetPosition(
		(m_boundryPosition * getTileSize().getX()) - (m_boundryLine.GetSize().x / 2.0f) + m_pos.getX(), 
		m_pos.getY()
		);

	for(int y = 0; y < m_size.getY(); ++y)
		{
		m_boundryLine.SetY((y * getTileSize().getY() ) + m_pos.getY());
		target.Draw(m_boundryLine);
		}
	}
