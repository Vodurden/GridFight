#ifndef GRIDFIGHT_INTERFACE_STYLE_H
#define GRIDFIGHT_INTERFACE_STYLE_H
namespace Interface
	{

	/** 
	 * Mirrors the SFML (www.sfml-dev.org)
	 * styles
	 *
	 * To use these styles you should call the respective
	 * Regular()/Bold()/Italic()/Underlined() function
	 */
	enum STYLE_TYPE
		{
		INTERNAL_Regular = 0,
		INTERNAL_Bold = 1 << 0,
		INTERNAL_Italic = 1 << 1,
		INTERNAL_Underlined = 1 << 2
		};
	
	class Style
		{
		public:
			static const Style Regular;
			static const Style Bold;
			static const Style Italic;
			static const Style Underlined;

			Style(STYLE_TYPE type);

			Style(const Style& rhs);

			STYLE_TYPE getType() const;

			void setType(STYLE_TYPE type);
		private:
			STYLE_TYPE m_type;

		};
	}
#endif
