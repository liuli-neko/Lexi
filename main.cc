#include <Btk/comctl.hpp>
#include <Btk/context.hpp>
#include <iostream>
#include <pthread.h>

#include "common/log/lexi_log.hpp"
#include "core/glyph/glyph.hpp"

void track1() {
  std::cout << "track1 step : 1" << std::endl;
  throw "track 1";
  std::cout << "track1 step : 2" << std::endl;
}

void track2() {
  std::cout << "step 1:" << std::endl;
  try {
    track1();
  } catch (char *e) {
    std::cout << e << std::endl;
  }
  std::cout << "step 2:" << std::endl;
}

int main() {
  LOG_INFO("this is a log %d", 1024);
  lexi::core::Glyph *glyph = lexi::core::Glyph::New();
  return 0;
}