#ifndef SCENE_COMPOSIT_H
#define SCENE_COMPOSIT_H
#include "camera/base_camera_transformations.h"
#include "model/model.h"
#include "canvas/painter.h"
#include "composit_object/composit_object.h"
#include "loader/loader.h"
#include "canvas/graphical_sys.h"
class scene_composit
{
public:
    scene_composit();
    void load_model(const char* file_name);
    void delete_model(size_t index);

    void change_model(base_transformations* transform,size_t index);
    void change_camera(base_transformations* transform, size_t index);

    void add_cam();
    void delete_camera(size_t index);

    void draw(painter *pntr, size_t index_cam);
    void clear(painter *pntr);
private:
    //vector<camera> cams;
    composit_object cams;
    composit_object models;
};

#endif // SCENE_COMPOSIT_H
