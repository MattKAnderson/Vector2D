cmake_minimum_required(VERSION 3.14)
project(Vector2D-tests)

string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

if (is_top_level)
    enable_testing()
    find_package(Vector2D REQUIRED)
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(Vector2D_tests)
target_sources(Vector2D_tests PRIVATE Vector2D_tests.cpp)
target_link_libraries(Vector2D_tests PRIVATE Vector2D::Vector2D GTest::gtest_main)
target_compile_features(Vector2D_tests PUBLIC cxx_std_14)

include(GoogleTest)
gtest_discover_tests(Vector2D_tests)