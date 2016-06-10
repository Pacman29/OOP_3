#ifndef BASE_GRAPHICAL_SYS
#define BASE_GRAPHICAL_SYS
#include "model/model.h"
#include "painter.h"
#include "camera/camera.h"

class Graphical_sys_base
{
public:
    virtual void Draw_model(model &model, camera &cam) = 0;
protected:
    painter *_painter;
};

#endif // BASE_GRAPHICAL_SYS

