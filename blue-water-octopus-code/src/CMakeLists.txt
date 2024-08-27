cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 23)


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


set(BILLWEINMAN_SOURCES
LinkedInBillWeinman/advanced_concepts/advanced_concepts.cpp
LinkedInBillWeinman/advanced_concepts/rationale.cpp
LinkedInBillWeinman/advanced_concepts/move_semantics.cpp
LinkedInBillWeinman/advanced_concepts/constraints.cpp
LinkedInBillWeinman/advanced_concepts/concurrency.cpp
LinkedInBillWeinman/advanced_concepts/optional_vvariants_bidings.cpp
LinkedInBillWeinman/advanced_concepts/initialization_spaceship_chrono_span_filesystem.cpp
LinkedInBillWeinman/advanced_concepts/iterator.cpp
)

add_library(LinkedInBillWeinman STATIC ${BILLWEINMAN_SOURCES})


set(PARALLEL_PROGRAMMING_SOURCES 
ParallelProgramming/parallel_programing.cpp
)

add_library(ParallelProgramming STATIC ${PARALLEL_PROGRAMMING_SOURCES})


#add target include directories of header files
target_include_directories(Capra PUBLIC ${CMAKE_HOME_DIRECTORY}/include/)
target_include_directories(Magazino PUBLIC ${CMAKE_HOME_DIRECTORY}/include/)
target_include_directories(Codility PUBLIC ${CMAKE_HOME_DIRECTORY}/include/Codility/)
target_include_directories(LinkedInBillWeinman PUBLIC ${CMAKE_HOME_DIRECTORY}/include/LinkedInBillWeinman/)
target_include_directories(ParallelProgramming PUBLIC ${CMAKE_HOME_DIRECTORY}/include/ParallelProgramming/)


# All users of this library will need at least C++11
target_compile_features(Capra PUBLIC cxx_std_20)
target_compile_features(Magazino PUBLIC cxx_std_20)
target_compile_features(Codility PUBLIC cxx_std_20)
target_compile_features(LinkedInBillWeinman PUBLIC cxx_std_23)
target_compile_features(ParallelProgramming PUBLIC cxx_std_23)