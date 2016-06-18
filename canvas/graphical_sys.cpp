#include "graphical_sys.h"
#include "model/model.h"

void Graphical_sysImpl::Draw_model(base_painter* pntr, base_model &mod, base_camera &cam)
{

    size_t line_count = mod.line_count();
    if(!line_count)
        throw graphic_sys_error::model_empty();

    for(size_t i = 0; i<line_count; ++i)
    {
        line tmp = mod.get_line(i);

        vector<double> start = mod.get_vertex(tmp.start()).to_vector();
        vector<double> end = mod.get_vertex(tmp.end()).to_vector();
        matrix<double> view = cam.GetViewMatrix();
        start = start * view;
        end = end * view;
        pntr->draw_line(point(start),point(end));
    }
}

void Graphical_sysImpl::clear_scene(base_painter *pntr)
{
    pntr->clear_scene();
}


