#include <iostream>
#include <cmath>

#include "tgaimage.h"

constexpr TGAColor white = {255, 255, 255, 255}; // BGRA order
constexpr TGAColor green = {  0, 255,   0, 255};
constexpr TGAColor red   = {  0,   0, 255, 255};
constexpr TGAColor blue  = {255, 128,  64, 255};
constexpr TGAColor yellow= {  0, 200, 255, 255};

auto line(int ax, int ay, int bx, int by, TGAImage& framebuffer, TGAColor color) -> void {
  //////////////////////////////////////////////////////////////////////////////
  /// Third attempt
  bool steep = std::abs(ax-bx) < std::abs(ay-by);
  if (steep) { // If the line is steep transpose the image
    std::swap(ax, ay);
    std::swap(bx, by);
  }

  if (ax > bx) { // Make the line go left to right
    std::swap(ax, bx);
    std::swap(ay, by);
  }

  for (int x = ax; x <= bx; x++) {
    float t = (x - ax) / static_cast<float>(bx - ax);
    int y = std::round(ay + (by - ay) * t);
    if (steep) { // if image was transposed, de-transpose it
      framebuffer.set(y, x, color);
    } else {
      framebuffer.set(x, y, color);
    }
  }

  //////////////////////////////////////////////////////////////////////////////
  /// Second attempt round 2 draws non-steep lines going in both directions fine,
  /// but steep lines are still a problem.
  // if (ax > bx) { // Make line go left to right
  //   std::swap(ax, bx);
  //   std::swap(ay, by);
  // }
  // for (int x = ax; x <= bx; x++) {
  //   float t = (x - ax) / static_cast<float>(bx - ax);
  //   int y = std::round(ay + (by-ay) * t);
  //   framebuffer.set(x, y, color);
  // }

  //////////////////////////////////////////////////////////////////////////////
  /// Second attempt draws non-steep lines going left to right fine, but
  /// steep lines and lines going right to left don't get drawn.
  // for (int x = ax; x <= bx; x++) {
  //   float t = (x - ax) / static_cast<float>(bx - ax);
  //   int y = std::round(ay + (by - ay) * t);
  //   framebuffer.set(x, y, color);
  // }

  //////////////////////////////////////////////////////////////////////////////
  /// First attempt has gaps and lines drawn depend on the direction
  // int x = 0;
  // int y = 0;
  // for (float t = 0.f; t < 1.f; t += 0.02f) {
  //   x = std::round(ax + (bx - ax) * t);
  //   y = std::round(ay + (by - ay) * t);
  //   framebuffer.set(x, y, color);
  // }
}

auto main() -> int {
  constexpr int width  = 64;
  constexpr int height = 64;
  TGAImage framebuffer(width, height, TGAImage::RGB);

  int ax =  7, ay =  3;
  int bx = 12, by = 37;
  int cx = 62, cy = 53;

  line(ax, ay, bx, by, framebuffer, blue);
  line(cx, cy, bx, by, framebuffer, green);
  line(cx, cy, ax, ay, framebuffer, yellow);
  line(ax, ay, cx, cy, framebuffer, red);

  framebuffer.set(ax, ay, white);
  framebuffer.set(bx, by, white);
  framebuffer.set(cx, cy, white);

  framebuffer.write_tga_file("lines.tga");

  return 0;
}
