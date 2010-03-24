set(CORE_SRCS
	Game.cpp BaseState.cpp
	)

add_library(GF_CORE ${CORE_SRCS})
target_link_libraries(GF_CORE
	GF_UTILITY
	GF_STATE
	GF_INTERFACE
	GF_STATE
	sfml-graphics
	sfml-window
	sfml-system
	)

add_subdirectory(state)
add_subdirectory(object)
