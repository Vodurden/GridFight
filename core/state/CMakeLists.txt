set(STATE_SRCS
	Menu.cpp
	MainMenu.cpp
	Quit.cpp
	)

add_library(GF_STATE ${STATE_SRCS})
target_link_libraries(GF_STATE
	GF_CORE
	GF_UTILITY
	)
