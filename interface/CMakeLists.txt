set(INTERFACE_SRCS
	BaseController.cpp
	SFMLController.cpp
	Button.cpp
	ImageButton.cpp
	TextRectButton.cpp
	ButtonFactory.cpp
	BaseRenderArea.cpp
	TextArea.cpp
	FormattedTextArea.cpp
	Style.cpp
	Color.cpp
	Position.cpp
	Wrap.cpp
	)

add_library(GF_INTERFACE ${INTERFACE_SRCS})
target_link_libraries(GF_INTERFACE
	GF_UTILITY
	sfml-window
	sfml-system
	boost_filesystem
	)
