add_library(
    ${PROJECT_NAME} 
    abstract_operations.cpp
    un_operations.cpp
    bin_operations.cpp
    primitives.cpp
)

target_link_libraries(
    ${PROJECT_NAME} 
    complex
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC 
    ${LIB_DIR}/complex/include 
    ${PROJECT_SOURCE_DIR}/include
)