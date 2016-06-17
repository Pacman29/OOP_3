#ifndef GRAPHICAL_SYS_H
#define GRAPHICAL_SYS_H
#include "base_graphical_sys.h"
#include "graphic_sys_error.h"
#include "point/_point.h"
class Graphical_sysImpl : public base_Graphical_sys_Impl
{
public:
    void Draw_model(base_painter *pntr,base_model &mod, base_camera &cam) override;
};

class Graphical_sys : public Graphical_sys_base
{
public:
    Graphical_sys(base_painter *cur_painter) : Graphical_sys_base(new Graphical_sysImpl),
        _painter(cur_painter){}
    void Draw_model(base_model &mod, base_camera &cam) override
    {
        this->GrImpl->Draw_model(this->_painter,mod,cam);
    }
private:
    base_painter *_painter;
};

#endif // GRAPHICAL_SYS_H
