cmake_minimum_required(VERSION 3.5.0)
project(luaScriptExample VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES 0)
set(CMAKE_C_USE_RESPONSE_FILE_FOR_INCLUDES 0)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-m64")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/arch)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
message("Das aktuelle Arbeitsverzeichnis ist: ${CMAKE_CURRENT_SOURCE_DIR}")

include(CTest)
enable_testing()

add_subdirectory("dependencies/lua")
include_directories("dependencies/lua/project")

add_executable(luaScriptExample main.cpp)
target_link_libraries(luaScriptExample PRIVATE luaCPP)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
