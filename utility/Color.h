#ifndef GRIDFIGHT_UTILITY_COLOR_H
#define GRIDFIGHT_UTILITY_COLOR_H
#include <libconfig.h++>
namespace Utility
	{
	class Color
		{
		public:
			Color();
			Color(libconfig::Setting& colorSetting);
			Color(const int r, const int g, const int b, const int a = 255);
			~Color();

			int getR();
			int getG();
			int getB();
			int getA();

			void setR(int r);
			void setG(int g);
			void setB(int b);
			void setA(int a);

			void set(int r, int g, int b, int a = 255);
		private:
			int m_r, m_g, m_b, m_a;
		};
	}
#endif
