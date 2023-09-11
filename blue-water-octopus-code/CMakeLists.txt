cmake_minimum_required(VERSION 3.8)

# set the project name
project(blue-water-octopus VERSION 1.0 DESCRIPTION "leet code and other chanlenges" LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

#add subdirectories
add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(test)


