# # Testing library
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test-Capra Capra/test-Capra.cpp)
add_executable(test-Magazino Magazino/test-Magazino.cpp)


set(TEST_LIBS_CALC gtest_main)

target_link_libraries(test-Capra PUBLIC ${TEST_LIBS_CALC} Capra)
target_link_libraries(test-Magazino PUBLIC ${TEST_LIBS_CALC} Magazino)


include(GoogleTest)
gtest_discover_tests(test-Capra)
gtest_discover_tests(test-Magazino)