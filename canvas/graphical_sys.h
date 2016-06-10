#ifndef GRAPHICAL_SYS_H
#define GRAPHICAL_SYS_H
#include "base_graphical_sys.h"
#include "graphic_sys_error.h"
#include "point/_point.h"
class Graphical_sys : public Graphical_sys_base
{
public:
    Graphical_sys(painter *cur_painter);
    void Draw_model(model &mod, camera &cam) override;
};

#endif // GRAPHICAL_SYS_H
