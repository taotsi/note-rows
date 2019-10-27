cmake_minimum_required(VERSION 3.7)

project(note_rows VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(include_dir ${PROJECT_SOURCE_DIR}/include/note_rows)
set(utility_dir ${PROJECT_SOURCE_DIR}/extern/little-utility/)
set(catch2_dir ${PROJECT_SOURCE_DIR}/extern/catch2)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
add_test(
  NAME test_note_rows
  COMMAND $<TARGET_FILE:test_note_rows> --success
)

