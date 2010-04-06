link_libraries(boost_unit_test_framework GF_INTERFACE)

add_executable(Color_Test Color_Test.cpp)

add_test(Color_Test Color_Test)
