set(UTILITY_SRCS
	Config.cpp Module.cpp
	)

add_library(GF_UTILITY ${UTILITY_SRCS})
target_link_libraries(GF_UTILITY
	config++
	)
