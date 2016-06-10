#include "scene_composit.h"

scene_composit::scene_composit()
{

}

void scene_composit::load_model(const char *file_name)
{
    loader ld;
    model *tmp = new model();
    ld.Load(*tmp,file_name);
    models.add(tmp);
}

void scene_composit::delete_model(size_t index)
{
    models.del(index);
}

void scene_composit::change_model(base_transformations *transform, size_t index)
{
    if(!index)
        models.transform(transform);
    else
        models[index-1]->transform(transform);
}

void scene_composit::change_camera(base_transformations *transform, size_t index)
{
    cams[index]->transform(transform);
}

void scene_composit::add_cam()
{
    camera* cam = new camera;
    cams.add(cam);
}

void scene_composit::delete_camera(size_t index)
{
    cams.del(index);
}


void scene_composit::draw(painter *pntr, size_t index_cam)
{
    Graphical_sys gr(pntr);
    for(size_t i = 0; i<models.length(); ++i)
        gr.Draw_model(*((model*) models[i]),*((camera*) cams[index_cam]));
}

void scene_composit::clear(painter *pntr)
{
    pntr->clear_scene();
}





