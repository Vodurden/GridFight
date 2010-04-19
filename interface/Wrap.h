#ifndef GRIDFIGHT_INTERFACE_WRAP_H
#define GRIDFIGHT_INTERFACE_WRAP_H
namespace Interface
	{
	class Wrap
		{
		public:
			enum WRAP_TYPE
				{
				INTERNAL_Enabled,
				INTERNAL_Disabled
				};

			static const WRAP_TYPE Enabled;
			static const WRAP_TYPE Disabled;

			Wrap(WRAP_TYPE wrap);
			Wrap(const Wrap& other);

			WRAP_TYPE getType() const;

			void setType(WRAP_TYPE type);

			operator bool()	
				{
				return (m_wrap == INTERNAL_Enabled);
				}
		private:
			WRAP_TYPE m_wrap;
		};
	
	}
#endif
