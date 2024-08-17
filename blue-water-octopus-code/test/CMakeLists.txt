# # Testing library
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()

# add_executable(test-Capra Capra/test-Capra.cpp)
# add_executable(test-Magazino Magazino/test-Magazino.cpp)

# add_executable(test-binary-gap Codility/iteractions/binary_gap.cpp)
#  Codility/arrays/cyclic_rotation.cpp
# Codility/arrays/odd_occurencesin_array.cpp
# Codility/counting_elements/frog_river_one.cpp
# Codility/counting_elements/max_counters.cpp
# Codility/counting_elements/missing_integer.cpp
# Codility/counting_elements/perm_check.cpp
# Codility/iteractions/binary_gap.cpp
# Codility/time_complexity/frog_imp.cpp
# Codility/time_complexity/perm_missing_elem.cpp
# Codility/time_complexity/tape_equilibrium.cpp




# set(TEST_LIBS_CALC gtest_main)

# target_link_libraries(test-Capra PUBLIC ${TEST_LIBS_CALC} Capra)
# target_link_libraries(test-Magazino PUBLIC ${TEST_LIBS_CALC} Magazino)

# target_link_libraries(test-binary-gap PUBLIC ${TEST_LIBS_CALC} Codility)


# include(GoogleTest)
# gtest_discover_tests(test-Capra)
# gtest_discover_tests(test-Magazino)
# gtest_discover_tests(test-binary-gap)

# find_package(ament_cmake_gmock REQUIRED)
find_package(ament_cmake_gtest REQUIRED)

set(CMAKE_CXX_STANDARD 20)

ament_add_gtest(test-binary-gap Codility/iteractions/binary_gap.cpp)
target_link_libraries(test-binary-gap Codility)


ament_add_gtest(test-cyclic_rotation Codility/arrays/cyclic_rotation.cpp)
target_link_libraries(test-cyclic_rotation Codility)


ament_add_gtest(test-tape_equilibrium Codility/time_complexity/tape_equilibrium.cpp)
target_link_libraries(test-tape_equilibrium Codility)


ament_add_gtest(test-frog-river-one Codility/counting_elements/frog_river_one.cpp)
target_link_libraries(test-frog-river-one Codility)

ament_add_gtest(test-perm-check Codility/counting_elements/perm_check.cpp)
target_link_libraries(test-perm-check Codility)

ament_add_gtest(test-max-counters Codility/counting_elements/max_counters.cpp)
target_link_libraries(test-max-counters Codility)