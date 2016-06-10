#ifndef PAINTER_H
#define PAINTER_H
#include "base_painter.h"
#include "painter_error.h"
#include <QPixmap>

class painter :public base_painter
{
public:
    painter(QPixmap* pix);
    ~painter();
    void draw_line(point start, point end) override;
    void clear_scene() override;
    void pen_color(int R, int G, int B, int a) override;
    void pen_thickness(int Th) override;

};

#endif // PAINTER_H
