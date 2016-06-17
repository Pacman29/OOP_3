#ifndef PAINTER_H
#define PAINTER_H
#include "base_painter.h"
#include "painter_error.h"
#include <QPixmap>
class painterImpl : public base_painterImpl
{
public:
    void draw_line(QPixmap* pix, point start, point end) override;
    void clear_scene(QPixmap* pix) override;
private:
};

class painter :public base_painter
{
public:
    painter(QPixmap* pix) : base_painter(new painterImpl), _pix(pix){}

    void draw_line(point start, point end) override
    {
        this->pntrImpl->draw_line(_pix,start,end);
    }
    void clear_scene() override
    {
        this->pntrImpl->clear_scene(_pix);
    }
private:
    QPixmap* _pix;
};

#endif // PAINTER_H
