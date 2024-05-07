cmake_minimum_required(VERSION 3.0.0)
project(easyui VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include_directories(head/)


set(SOURCE_DIR /source/)

file(GLOB_RECURSE SOURCE_FILES 
  RELATIVE ${SOURCE_DIR} 
  "*.cpp"
)

add_executable(easyui source/Image.cpp source/main.cpp source/Page.cpp source/Text.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
