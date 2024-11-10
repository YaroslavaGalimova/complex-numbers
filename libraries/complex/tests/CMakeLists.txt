add_executable(${PROJECT_NAME}_tests tests.cpp)

include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.6.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

target_link_libraries(
  ${PROJECT_NAME}_tests 
  Catch2::Catch2WithMain 
  ${PROJECT_NAME}
)
target_include_directories(
  ${PROJECT_NAME}_tests PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)

include(CTest)
add_test(
  NAME ${PROJECT_NAME}_tests
  COMMAND ${PROJECT_NAME}_tests
)
