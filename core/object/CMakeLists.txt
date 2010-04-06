set(OBJECT_SRCS
	BaseUnit.cpp
	ConfigUnit.cpp
	ImageObject.cpp
	Group.cpp
	GroupFactory.cpp
	Grid.cpp
	)

add_library(GF_OBJECT ${OBJECT_SRCS})
target_link_libraries(GF_OBJECT
	GF_UTILITY
	GF_INTERFACE
	)
