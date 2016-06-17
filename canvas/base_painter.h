#ifndef CANVAS_H
#define CANVAS_H
#include "point/point.h"
#include <QPainter>
class base_painterImpl;

class base_painter
{
public:
    base_painter(base_painterImpl* pntr) : pntrImpl(pntr){}
    virtual ~base_painter()
    {
        delete pntrImpl;
    }

    virtual void draw_line(point start, point end) = 0;
    virtual void clear_scene() = 0;
protected:
    base_painterImpl* pntrImpl;
};

class base_painterImpl
{
public:
    virtual ~base_painterImpl(){}

    virtual void draw_line(QPixmap* pix, point start, point end) = 0;
    virtual void clear_scene(QPixmap* pix) = 0;
};

#endif // CANVAS_H
