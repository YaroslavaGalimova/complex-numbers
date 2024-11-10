cmake_minimum_required(VERSION 3.5.0)
project(
    complex_expression
    VERSION 0.0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(LIB_DIR ${PROJECT_SOURCE_DIR}/libraries)

enable_testing()

add_subdirectory(libraries)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC libraries/expression/include ibraries/complex/include)
target_link_libraries(${PROJECT_NAME} expression complex)