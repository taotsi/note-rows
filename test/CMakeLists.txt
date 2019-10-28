add_executable(test_note_rows test_main.cc test_note_rows.cc test_basic_concepts.cc)

target_include_directories(test_note_rows PUBLIC ${include_dir})
target_include_directories(test_note_rows PUBLIC ${catch2_dir})
target_include_directories(test_note_rows PUBLIC ${utility_dir})

target_link_libraries(test_note_rows PRIVATE libnote_rows)

if(MSVC)
  set_target_properties(test_note_rows PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
  set_target_properties(test_note_rows PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR})
  set_target_properties(test_note_rows PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_BINARY_DIR})
else()
  set_target_properties(test_note_rows PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
endif(MSVC)

