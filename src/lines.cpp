#include "tgaimage.h"
#include <cmath>

////////////////////////////////////////////////////////////////////////////////
///
auto line(int ax, int ay, int bx, int by, TGAImage& framebuffer, TGAColor color) -> void {
  bool steep = std::abs(ax-bx) < std::abs(ay-by);
  if (steep) { // If the line is steep transpose the image
    std::swap(ax, ay);
    std::swap(bx, by);
  }

  if (ax > bx) { // Make the line go left to right
    std::swap(ax, bx);
    std::swap(ay, by);
  }
  
  int y = ay;
  int ierror = 0;

  for (int x = ax; x <= bx; x++) {
    float t = (x - ax) / static_cast<float>(bx - ax);
    if (steep) { // if image was transposed, de-transpose it
      framebuffer.set(y, x, color);
    } else {
      framebuffer.set(x, y, color);
    }
    ierror += 2 * std::abs(by - ay);
    y += (by > ay ? 1 : -1) * (ierror > bx - ax);
    ierror -= 2 * (bx - ax) * (ierror > bx - ax);
  }
}


////////////////////////////////////////////////////////////////////////////////
///
auto line_2(int ax, int ay, int bx, int by, TGAImage& framebuffer, TGAColor color) -> void {
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
}
