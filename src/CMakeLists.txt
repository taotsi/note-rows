add_library(libnote_rows note_rows.cc basic_concepts.cc)

target_include_directories(libnote_rows PUBLIC ${include_dir})
target_include_directories(libnote_rows PUBLIC ${utility_dir})

if(MSVC)
  set_target_properties(libnote_rows PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
  set_target_properties(libnote_rows PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR})
  set_target_properties(libnote_rows PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_BINARY_DIR})
else()
  set_target_properties(libnote_rows PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
endif(MSVC)

add_executable(note_rows main.cc)

target_include_directories(note_rows PUBLIC ${include_dir})
target_include_directories(note_rows PUBLIC ${utility_dir})

target_link_libraries(note_rows PRIVATE libnote_rows)
target_link_libraries(note_rows PRIVATE midifile)

if(MSVC)
  set_target_properties(note_rows PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
  set_target_properties(note_rows PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR})
  set_target_properties(note_rows PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_BINARY_DIR})
else()
  set_target_properties(note_rows PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
endif(MSVC)

