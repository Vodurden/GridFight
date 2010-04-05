#ifndef GRIDFIGHT_INTERFACE_BASERENDERAREA_H
#define GRIDFIGHT_INTERFACE_BASERENDERAREA_H
#include <SFML/Graphics.hpp>
#include "../utility/Point.h"
namespace Interface
	{
	class BaseRenderArea
		{
		public:
			BaseRenderArea(
				Utility::fPoint pos,
				Utility::fPoint size
				);

			virtual ~BaseRenderArea() = 0;

			virtual void render(sf::RenderTarget& target) = 0;	

			Utility::fPoint getPosition() const;

			Utility::fPoint getSize() const;
		protected:
			void setPosition(const Utility::fPoint& position);

			void setSize(const Utility::fPoint& size);
		private:
			Utility::fPoint m_pos;

			Utility::fPoint m_size;
		};
	}
#endif
