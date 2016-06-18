#ifndef GRAPHICAL_SYS_H
#define GRAPHICAL_SYS_H
#include "base_graphical_sys.h"
#include "graphic_sys_error.h"
#include "point/_point.h"
class Graphical_sysImpl : public base_Graphical_sys_Impl
{
public:
    void Draw_model(base_painter *pntr,base_model &mod, base_camera &cam) override;
    void clear_scene(base_painter* pntr) override;
};

class Graphical_sys : public Graphical_sys_base
{
public:
    Graphical_sys() : Graphical_sys_base(new Graphical_sysImpl){}
    void Draw_model(base_model &mod, base_camera &cam) override
    {
        this->GrImpl->Draw_model(this->_painter,mod,cam);
    }
    void clear_scene() override
    {
        this->GrImpl->clear_scene(this->_painter);
    }
    void set_scene(base_painter &pntr) override
    {
        this->_painter = &pntr;
    }
private:
    base_painter *_painter;
};

#endif // GRAPHICAL_SYS_H
