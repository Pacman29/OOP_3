#include "painter.h"
#include "QDebug"
void painterImpl::draw_line(QPixmap* pix,point start, point end)
{
    if(pix->isNull())
        throw painter_error::pix_null();

    size_t _centre_x = pix->width()/2;
    size_t _centre_y = pix->height()/2;
    QPainter pntr(pix);
    pntr.setPen(QPen(QBrush(Qt::black),1));
    pntr.drawLine((int)start.X()+_centre_x,(int)start.Y()+_centre_y,
                  (int)end.X()+_centre_x,(int)end.Y()+_centre_y);
}

void painterImpl::clear_scene(QPixmap* pix)
{
    pix->fill();
}

