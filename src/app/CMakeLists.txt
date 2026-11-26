aux_source_directory(. SRC_LIST)
add_executable(main ${SRC_LIST})

target_include_directories(main PUBLIC
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_link_libraries(main cal)