cmake_minimum_required(VERSION 3.28)
set(this LibraryTemplate)
project(${this})

set(CMAKE_CXX_STANDARD 26)
file(GLOB_RECURSE LIB_SOURCES "lib/*.cpp" "lib/*.h")
file(GLOB_RECURSE TEST_SOURCES "test/*.cpp" "test/*.h")

add_library(${this}_lib SHARED ${LIB_SOURCES})
target_include_directories(${this}_lib PUBLIC lib)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME}_test ${TEST_SOURCES})
target_include_directories(${PROJECT_NAME}_test PUBLIC test)
target_link_libraries(${PROJECT_NAME}_test gtest ${this}_lib)

add_subdirectory(test)