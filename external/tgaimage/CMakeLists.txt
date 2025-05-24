add_library(tgaimage tgaimage.cpp)

target_include_directories(tgaimage PUBLIC
  ${CMAKE_SOURCE_DIR}/external/tgaimage
)
