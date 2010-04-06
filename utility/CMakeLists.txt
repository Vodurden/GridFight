set(UTILITY_SRCS
	Config.cpp Module.cpp
	ModuleManager.cpp ConfigValidator.cpp
	Type.cpp
	Utility.cpp SFMLUtility.cpp
	)

add_library(GF_UTILITY ${UTILITY_SRCS})
target_link_libraries(GF_UTILITY
	config++
	boost_filesystem
	sfml-graphics
	sfml-window
	sfml-system
	)
