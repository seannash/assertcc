cmake_minimum_required(VERSION 3.18)

project(
  AssertCC
  VERSION 0.0.1
  DESCRIPTION "A Fluent Assertions library."
  LANGUAGES CXX)

set(INSTALL_GTEST OFF)
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  set(CMAKE_CXX_EXTENSIONS OFF)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
  include(CTest)
  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()
endif()

add_library(asertcc INTERFACE)
target_include_directories(asertcc INTERFACE include/)
install(DIRECTORY include/assertcc DESTINATION "include/")

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) AND BUILD_TESTING)
   enable_testing()
   add_subdirectory(tests)
endif()
