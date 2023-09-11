# #add an executable that call the contructor of the class 
add_executable(app-Capra Capra/app-Capra.cpp)
add_executable(app-Magazino Magazino/app-Magazino.cpp)
add_executable(app-Codility Codility/app-Codility.cpp)


# compiler version
target_compile_features(app-Capra PUBLIC cxx_std_20)
target_compile_features(app-Magazino PUBLIC cxx_std_20)
target_compile_features(app-Codility PUBLIC cxx_std_20)


#link the library created above since in the file is included the calculator.hpp
target_link_libraries(app-Capra PUBLIC Capra)
target_link_libraries(app-Magazino PUBLIC Magazino)
target_link_libraries(app-Codility PUBLIC Magazino)
