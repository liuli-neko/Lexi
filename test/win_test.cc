#include "core/window/window.hpp"

using namespace lexi::core;

#include <math.h>

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <iostream>
#include <memory>
using namespace std;
using namespace Eigen;

const double PI = acos(-1.0);

struct {
  Vector3d axis_x, axis_y, normal_vector;
  void init(Vector3d normal_vector, Vector3d direct_x) {
    this->normal_vector = normal_vector / normal_vector.norm();
    axis_x = direct_x - this->normal_vector.dot(direct_x) * this->normal_vector;
    axis_y = axis_x.cross(this->normal_vector);

    axis_x /= axis_x.norm();
    axis_y /= axis_y.norm();
  }
  Vector2d operator()(Vector3d point3d) {
    Vector2d point;
    point << point3d.dot(axis_x) / axis_x.norm(),
        point3d.dot(axis_y) / axis_y.norm();
    return point;
  }
} OrthographicProjection;

void drawRectangle(Window& win, Vector2d p1, Vector2d p2, Vector2d p3,
                   Vector2d p4, Btk::Color color) {
  win.SetPainterColor(color);
  win.DrawLine({p1[0], p1[1]}, {p2[0], p2[1]});
  win.DrawLine({p1[0], p1[1]}, {p2[0], p2[1]});
  win.DrawLine({p2[0], p2[1]}, {p3[0], p3[1]});
  win.DrawLine({p3[0], p3[1]}, {p4[0], p4[1]});
  win.DrawLine({p4[0], p4[1]}, {p1[0], p1[1]});
}
void drawRectangle3d(Window& win, Vector2d p[8], Btk::Color color) {
  win.SetPainterColor(color);
  for (int i = 0; i < 4; i++) {
    win.DrawLine({p[i][0], p[i][1]}, {p[(i + 1) % 4][0], p[(i + 1) % 4][1]});
    win.DrawLine({p[i + 4][0], p[i + 4][1]},
                 {p[(i + 1) % 4 + 4][0], p[(i + 1) % 4 + 4][1]});
    win.DrawLine({p[i][0], p[i][1]}, {p[i + 4][0], p[i + 4][1]});
  }
}
Quaterniond getQuad(double roll, double pitch, double yaw) {
  Vector3d eulerAngle(roll, pitch, yaw);
  AngleAxisd rollAngle(AngleAxisd(eulerAngle(0), Vector3d::UnitX()));
  AngleAxisd pitchAngle(AngleAxisd(eulerAngle(1), Vector3d::UnitY()));
  AngleAxisd yawAngle(AngleAxisd(eulerAngle(2), Vector3d::UnitZ()));
  Quaterniond qua;
  qua = yawAngle * pitchAngle * rollAngle;
  return qua;
}

class App : public Window {
 private:
  Quaterniond roat_z;
  Vector2d center, p2p[8];
  Vector3d p1, p2, p3, p4, p[8], np[8], np1, np2, np3, np4;

 public:
  App() : Window() {
    p1 << -100, -100, 0;
    p2 << 100, -100, 0;
    p3 << 100, 100, 0;
    p4 << -100, 100, 0;

    p[0] = {100, 100, 100};
    p[4] = {100, 100, -100};
    for (int i = 1; i < 4; i++) {
      p[i] = p[i - 1];
      p[i + 4] = p[i + 3];
      p[i][i % 2] *= -1;
      p[i + 4][i % 2] *= -1;
    }

    center << 300, 300;
    Vector3d norm({12, 12, 12});
    roat_z = getQuad(0.2 * PI / 60, 0.5 * PI / 60, 0.3 * PI / 60);
    norm = AngleAxisd(roat_z).axis();
    OrthographicProjection.init(norm, {1, 0, 0});
  }
  auto paint_event(Btk::PaintEvent& p_event) -> bool override {
    SetPainterColor(lexi::Color::Red);
    DrawLine({0, 0}, {100, 100});
    SetPainterColor(lexi::Color::Black);
    DrawLine({100, 100}, {200, 100});
    SetPainterColor(lexi::Color::Blue);
    DrawLine({200, 100}, {200, 200});
    SetPainterColor(lexi::Color::Black);
    lexi::Rectd rect{100, 70, 200, 20};
    DrawRect(rect);
    auto font_now = font();
    font_now.set_bold(true);
    painter().set_font(font_now);
    Btk::TextLayout tl;
    std::string txt = "鸡 -> ☹ -> チキン -> chicken?";
    tl.set_text(txt);
    tl.set_font(font_now);
    DrawString(txt, rect, 2, 3);
    Btk::Size txt_size = tl.size();

    DrawLine({rect.x + 2, rect.y + 1 + txt_size.h},
             {rect.x + 2 + txt_size.w, rect.y + 1 + txt_size.h});
    SetPainterColor(lexi::Color::Red);
    DrawLine({rect.x + 2, rect.y + 1 + txt_size.h / 2},
             {rect.x + 2 + txt_size.w, rect.y + 1 + txt_size.h / 2});
    for (int i = 0; i < 8; i++) {
      np[i] = roat_z * p[i];
      p2p[i] = OrthographicProjection(p[i]) + center;
    }

    drawRectangle(*this, OrthographicProjection(p1) + center,
                  OrthographicProjection(p2) + center,
                  OrthographicProjection(p3) + center,
                  OrthographicProjection(p4) + center, Btk::Color::Red);
    drawRectangle3d(*this, p2p, Btk::Color::Black);

    p1 = roat_z * p1;
    p2 = roat_z * p2;
    p3 = roat_z * p3;
    p4 = roat_z * p4;
    for (int i = 0; i < 8; i++) {
      p[i] = np[i];
    }

    return true;
  }
};

int main(int argc, char** argv) {
  Btk::UIContext ctxt;
  App win;
  Btk::Timer timer;
  timer.signal_timeout().connect([&win]() { win.repaint_now(); });
  timer.set_interval(10);
  timer.set_repeat(true);
  timer.start();
  win.SetBound(0, 0, 1024, 1024);
  ctxt.run();
  return 0;
}