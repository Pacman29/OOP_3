#ifndef BASE_GRAPHICAL_SYS
#define BASE_GRAPHICAL_SYS
#include "model/model.h"
#include "painter.h"
#include "camera/camera.h"
class base_Graphical_sys_Impl;

class Graphical_sys_base
{
public:
    Graphical_sys_base(base_Graphical_sys_Impl* Gr) : GrImpl(Gr){}
    virtual ~Graphical_sys_base()
    {
        delete GrImpl;
    }
    virtual void Draw_model(base_model &model, base_camera &cam) = 0;
protected:
    base_Graphical_sys_Impl* GrImpl;
};

class base_Graphical_sys_Impl
{
public:
    virtual ~base_Graphical_sys_Impl(){}
    virtual void Draw_model(base_painter *pntr, base_model &model, base_camera &cam) = 0;
};

#endif // BASE_GRAPHICAL_SYS

