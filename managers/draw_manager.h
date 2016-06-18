#ifndef DRAW_MANAGER
#define DRAW_MANAGER
#include "base_manager/base_manager.h"
#include "managers/keeper.h"
#include "canvas/graphical_sys.h"
#include "camera/base_camera.h"
class draw_manager : public base_manager
{
public:
    draw_manager(): gr(new Graphical_sys){}
    ~draw_manager()
    {
        delete gr;
    }
    void drawScene(keeper& keep,base_painter& pntr, base_camera& cam)
    {
        gr->set_scene(pntr);
        gr->clear_scene();
        for(composit_object::it it = keep.objects_begin(), end = keep.objects_end();
            it <= end; it++)
        {
            if((*it)->is_display())
            {
                gr->Draw_model(*((base_model*)*it),cam);
            }
        }
    }
    void clear_scene(base_painter& pntr)
    {
        pntr.clear_scene();
    }

private:
    Graphical_sys_base* gr;
};

#endif // DRAW_MANAGER

