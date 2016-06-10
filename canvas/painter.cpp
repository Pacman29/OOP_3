#include "painter.h"
#include "QDebug"
painter::painter(QPixmap *pix)
{
    if(pix->isNull())
        throw painer_error::pix_null();
    this->_pix = pix;
    this->_clr = Qt::black;
    this->_th = 1;
    this->_centre_x = pix->width()/2;
    this->_centre_y = pix->height()/2;
}

painter::~painter()
{
}

void painter::draw_line(point start, point end)
{
    QPainter pntr(this->_pix);
    pntr.setPen(QPen(QBrush(this->_clr),this->_th));
    pntr.drawLine((int)start.X()+this->_centre_x,(int)start.Y()+this->_centre_y,
                  (int)end.X()+this->_centre_x,(int)end.Y()+this->_centre_y);
}

void painter::clear_scene()
{
    this->_pix->fill();
}

void painter::pen_color(int R, int G, int B, int a)
{
    this->_clr = QColor(R,G,B,a);
}

void painter::pen_thickness(int Th)
{
    this->_th = Th;
}
