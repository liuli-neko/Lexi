#include <iostream>
#include <Btk/comctl.hpp>
#include <Btk/context.hpp>

#include "common/log/lexi_log.hpp"

int main() {
  LOG_INFO("this is a log %d", 1024);
  return 0;
}