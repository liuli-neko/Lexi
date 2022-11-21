#include <Btk/comctl.hpp>
#include <Btk/context.hpp>
#include <iostream>

#include "Btk/widget.hpp"
#include "Btk/widgets/button.hpp"
#include "common/log/lexi_log.hpp"

int main() {
  LOG_INFO("this is a log %d", 1024);
  Btk::UIContext ctxt;
  Window win;
  win.show();
  ctxt.run();
  
  return 0;
}