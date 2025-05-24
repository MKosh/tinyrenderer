#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "tgaimage.h"
#include "lines.h"

constexpr TGAColor white = {255, 255, 255, 255}; // BGRA order
constexpr TGAColor green = {  0, 255,   0, 255};
constexpr TGAColor red   = {  0,   0, 255, 255};
constexpr TGAColor blue  = {255, 128,  64, 255};
constexpr TGAColor yellow= {  0, 200, 255, 255};


auto main() -> int {
  constexpr int width  = 64;
  constexpr int height = 64;
  TGAImage framebuffer(width, height, TGAImage::RGB);

  int ax =  7, ay =  3;
  int bx = 12, by = 37;
  int cx = 62, cy = 53;

  std::srand(std::time({}));
  for (int i = 0; i < (1<<24); i++) {
    int ax = rand() % width, ay = rand() % height;
    int bx = rand() % width, by = rand() % height;
    line(ax, ay, bx, by, framebuffer, { static_cast<std::uint8_t>(rand()%255), static_cast<std::uint8_t>(rand()%255), static_cast<std::uint8_t>(rand()%255), static_cast<std::uint8_t>(rand()%255) });
  }

  framebuffer.write_tga_file("lines2.tga");

  return 0;
}
