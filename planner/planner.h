#ifndef PLANNER_H
#define PLANNER_H
#include "managers/draw_manager.h"
#include "managers/keeper.h"
#include "managers/load_manager.h"
#include "scene/scene_composit.h"
#include "managers/camera_convert_manager.h"
#include "managers/model_conver_manager.h"
class planner
{
public:
    planner() ;
    void add_cam();
    void add_model(const char* name);
    void del_cam(size_t index);
    void del_model(size_t index);
    void draw_scene(base_painter &pntr, size_t cam_index);
    void clear_scene(base_painter& pntr);
    void convert_model(base_transformations *transform, size_t model_index);
    void convert_camera(base_transformations *transform, size_t cam_index);
private:
    scene_composit sc;
    load_manager ldm;
    keeper km;
    draw_manager drm;
    model_conver_manager model_convert_m;
    camera_conver_manager camera_convert_m;
};

#endif // PLANNER_H
