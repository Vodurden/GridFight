#ifndef GRIDFIGHT_CORE_OBJECT_GROUP_H
#define GRIDFIGHT_CORE_OBJECT_GROUP_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <utility>
#include "../../utility/Point.h"
#include "BaseUnit.h"
namespace Core
	{
	namespace Object
		{
		class Group
			{
			public:
				Group(Utility::iPoint pos = Utility::iPoint(0, 0));

				~Group();

				bool isColliding(Group& other);

				/**
				 * Returns the position of the group
				 * based on the (0, 0) relative unit
				 */
				Utility::iPoint getPosition() const;

				void setOffset(Utility::fPoint pos);

				virtual void update();

				virtual void render(sf::RenderTarget& target);

				std::vector<std::pair<Utility::fPoint, Utility::fPoint> > getUnitBorderPoints(
					BaseUnit& unit, 
					const Utility::fPoint gridTileSize
					);

				
				typedef std::vector<BaseUnit*>::iterator iterator;
				
				iterator begin();
				iterator end();
			private:
				friend class GroupFactory;
				
				/**
				 * Adds a unit to this group
				 * positions are relative to the groups
				 * position
				 *
				 * Takes ownership of the given unit
				 * (Will be deleted by this object)
				 */
				void addUnit(Utility::iPoint relativePos, BaseUnit* unit);

				BaseUnit* getRelativeUnit(BaseUnit& unit, Utility::iPoint pos);

				struct UnitPosition
					{
					UnitPosition(Utility::iPoint p, BaseUnit* u) :
						pos(p),
						unit(u)
						{
						}

					Utility::iPoint pos;
					BaseUnit* unit;
					};

				typedef std::vector<UnitPosition>::iterator UnitIter;

				std::vector<UnitPosition> m_units;
				std::vector<BaseUnit*> m_unitReferences;

				Utility::iPoint m_pos;
			};
		}
	}
#endif
