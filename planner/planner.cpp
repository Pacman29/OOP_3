#include "planner.h"

planner::planner()
{
    this->km.set_scene(&(this->sc));
}

void planner::add_cam()
{
    this->sc.add((base_object*) new camera());
}

void planner::add_model(const char *name)
{
    this->sc.add(this->ldm.load_obj(name));
}

void planner::del_cam(size_t index)
{
    this->km.delete_camera(index);
}

void planner::del_model(size_t index)
{
    this->km.delete_model(index);
}

void planner::draw_scene(base_painter& pntr, size_t cam_index)
{
    this->drm.drawScene(this->km,pntr,*(this->km.get_camera(cam_index)));
}

void planner::clear_scene(base_painter& pntr)
{
    this->drm.clear_scene(pntr);
}

void planner::convert_model(base_transformations* transform,size_t model_index)
{
    this->model_convert_m.convert_model(transform,this->km,model_index);
}

void planner::convert_camera(base_transformations *transform, size_t cam_index)
{
    this->camera_convert_m.convert_camera(transform,this->km,cam_index);
}

