add_executable(test test.cpp)

target_include_directories(test PUBLIC
  ${CMAKE_SOURCE_DIR}/external/tgaimage
)

target_link_libraries(test PUBLIC
  tgaimage
)
