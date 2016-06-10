#ifndef CANVAS_H
#define CANVAS_H
#include "point/point.h"
#include <QPainter>
class base_painter
{
public:
    virtual void draw_line(point start, point end) = 0;
    virtual void clear_scene() = 0;
    virtual void pen_color(int R, int G, int B, int a) = 0;
    virtual void pen_thickness(int Th) = 0;
protected:
    QColor _clr;
    size_t _th;
    QPixmap* _pix;
    size_t _centre_x;
    size_t _centre_y;
};

#endif // CANVAS_H
