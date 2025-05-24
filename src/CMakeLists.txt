################################################################################
add_executable(test test.cpp)

target_include_directories(test PUBLIC
  ${CMAKE_SOURCE_DIR}/external/tgaimage
)

target_link_libraries(test PUBLIC
  tgaimage
)

################################################################################
add_executable(simple_lines simple_lines.cpp)
target_include_directories(simple_lines PUBLIC
  ${CMAKE_SOURCE_DIR}/external/tgaimage
)

target_link_libraries(simple_lines PUBLIC
  tgaimage
)
