#ifndef GRIDFIGHT_INTERFACE_POSITION_H
#define GRIDFIGHT_INTERFACE_POSITION_H
namespace Interface
	{
	enum POSITION_TYPE
		{
		Position_Left,
		Position_Center,
		Position_Right	
		};
	
	class Position
		{
		public:
			static const Position Left;
			static const Position Center;
			static const Position Right;

			Position(POSITION_TYPE type);

			Position(const Position& rhs);

			POSITION_TYPE getType() const;

			void setType(POSITION_TYPE type);	
		private:
			POSITION_TYPE m_type;	
		};
	}
#endif
