#ifndef GRIDFIGHT_UTILITY_POINT_H
#define GRIDFIGHT_UTILITY_POINT_H
namespace Utility
	{
	template <typename T>
	class Point
		{
		public:
			Point() :
				m_x(0),
				m_y(0)
				{

				}
			Point(const T& x, const T& y) :
				m_x(x),
				m_y(y)
				{
				
				}


			T getX() { return m_x; }
			T getY() { return m_y; }

			void setX(const T& x) { m_x = x; }
			void setY(const T& y) { m_y = y; }
			void setPosition(const T& x, const T& y) { m_x = x; m_y = y; }
		private:
			T m_x;
			T m_y;
		};
	
	typedef Point<int> iPoint;
	typedef Point<float> fPoint;
	}
#endif
