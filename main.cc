#include <Btk/comctl.hpp>
#include <Btk/context.hpp>
#include <iostream>

#include "Btk/widget.hpp"
#include "Btk/widgets/button.hpp"
#include "common/log/lexi_log.hpp"

class Window : public Btk::Widget {
public:
  Window() {
    btn.signal_clicked().connect([this, n = 0]() mutable {
      n += 1;
      if (n == 5) {
        this->close();
      }
    });

    // Or add widget like this
    auto label = new Btk::Label("HelloWorld");
    add_child(label);
  }

private:
  Btk::Button btn{this};
};

int main() {
  LOG_INFO("this is a log %d", 1024);
  Btk::UIContext ctxt;
  Window win;
  win.show();
  ctxt.run();
  return 0;
}