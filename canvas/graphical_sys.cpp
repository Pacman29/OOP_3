#include "graphical_sys.h"
#include "model/model.h"

#include "QDebug"
Graphical_sys::Graphical_sys(painter *cur_painter)
{
    this->_painter = cur_painter;
}

void Graphical_sys::Draw_model(model &mod, camera &cam)
{

    size_t line_count = mod.line_count();
    if(!line_count)
        throw graphic_sys_error::model_empty();

    for(size_t i = 0; i<line_count; ++i)
    {
        line tmp = mod.get_line(i);

        vector<double> start = mod.get_vertex(tmp.start()).to_vector();
        //qDebug()<<"vertex start:"<<start[0]<<start[1]<<start[2]<<start[3];
        vector<double> end = mod.get_vertex(tmp.end()).to_vector();
        matrix<double> view = cam.GetViewMatrix();
        start = start * view;
        end = end * view;
        this->_painter->draw_line(point(start),point(end));
    }
}

