cmake_minimum_required(VERSION 3.11.0)
project("Vector2D" VERSION 0.1.0 
                   DESCRIPTION "A header only c++ library for vectors of length 2"
                   HOMEPAGE_URL "https://github.com/MattKAnderson/Vector2D"
                   LANGUAGES CXX)

string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

include(GNUInstallDirs)

option(VECTOR2D_BUILD_TESTS "Build Vector2D tests" OFF)
option(VECTOR2D_INSTALL "Generate target for installing Vector2D" is_top_level)

add_library(Vector2D INTERFACE)
add_library(Vector2D::Vector2D ALIAS Vector2D)

target_include_directories(
  Vector2D
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_compile_features(Vector2D INTERFACE cxx_std_11)

install(
  TARGETS Vector2D
  EXPORT ${PROJECT_NAME}_Targets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "Vector2D-config-version.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

install(
  EXPORT ${PROJECT_NAME}_Targets
  FILE ${PROJECT_NAME}Targets.cmake
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
)

install(
  FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
        "${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake"
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION include)

if(VECTOR2D_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
