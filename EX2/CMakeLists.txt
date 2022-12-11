# CMakeList.txt: проект CMake для EX1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("EX2")

set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 871ed52d350214a034f6ef8a3b8f51c5ce1bd400) # The commit hash for 1.9.0. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (EX2 "EX2.cpp")
target_link_libraries(EX2 PRIVATE cpr::cpr)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EX2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
