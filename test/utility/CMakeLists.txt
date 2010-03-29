link_libraries(boost_unit_test_framework GF_UTILITY)

add_executable(Config_Test Config_Test.cpp)
add_executable(Module_Test Module_Test.cpp)
add_executable(ConfigValidator_Test ConfigValidator_Test.cpp)
add_executable(Color_Test Color_Test.cpp)

add_test(Config_Test Config_Test)
add_test(Module_Test Module_Test)
add_test(ConfigValidator_Test ConfigValidator_Test)
add_test(Color_Test Color_Test)
