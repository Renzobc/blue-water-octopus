cmake_minimum_required(VERSION 3.8)

#add the library
add_library(Capra STATIC Capra/Capra.cpp)
add_library(Magazino STATIC Magazino/Magazino.cpp)

set(CODILITY_SOURCES 
Codility/arrays/cyclic_rotation.cpp
Codility/arrays/odd_occurencesin_array.cpp
Codility/counting_elements/frog_river_one.cpp
Codility/counting_elements/max_counters.cpp
Codility/counting_elements/missing_integer.cpp
Codility/counting_elements/perm_check.cpp
Codility/iteractions/binary_gap.cpp
Codility/time_complexity/frog_imp.cpp
Codility/time_complexity/perm_missing_elem.cpp
Codility/time_complexity/tape_equilibrium.cpp
)

add_library(Codility STATIC ${CODILITY_SOURCES})


#add target include directories of header files
target_include_directories(Capra PUBLIC ${CMAKE_HOME_DIRECTORY}/include/)
target_include_directories(Magazino PUBLIC ${CMAKE_HOME_DIRECTORY}/include/)
target_include_directories(Codility PUBLIC ${CMAKE_HOME_DIRECTORY}/include/Codility/)

# All users of this library will need at least C++11
target_compile_features(Capra PUBLIC cxx_std_20)
target_compile_features(Magazino PUBLIC cxx_std_20)
target_compile_features(Codility PUBLIC cxx_std_20)