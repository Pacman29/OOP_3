#ifndef ORDER_H
#define ORDER_H
#include "scene/scene_composit.h"
#include "base_order.h"
#include "camera/camera_transformations.h"
#include "geometric_transformations/geometric_transformations.h"
#include "point/point_transform.h"

namespace order {
class load : public base_order
{
private:
    const char* file_name;
public:
    load(const char *name)
    {
        this->file_name = name;
    }
    ~load(){}

    void Execute(scene_composit *elm, int elm_id) override
    {
        elm->load_model(this->file_name);
    }
};

class delete_model : public base_order
{
public:
    delete_model(){}
    ~delete_model(){}

    void Execute(scene_composit *elm, int elm_id) override
    {
        elm->delete_model(elm_id);
    }
};

class draw: public base_order
{
private:
    painter *pntr;
public:
    draw(QPixmap *pixmap)
    {
        this->pntr = new painter(pixmap);
    }
    ~draw(){}

    void Execute(scene_composit *elm, int elm_id)
    {
        elm->clear(this->pntr);
        elm->draw(this->pntr,elm_id);
    }
};

class clear_scene: public base_order
{
private:
    painter *pntr;
public:
    clear_scene(QPixmap *pixmap)
    {
        this->pntr = new painter(pixmap);
    }
    ~clear_scene(){}

    void Execute(scene_composit *elm, int elm_id)
    {
        elm->clear(this->pntr);
    }
};


class add_cam : public base_order
{
public:
    add_cam(){}
    ~add_cam(){}

    void Execute(scene_composit *elm, int elm_id = 0)
    {
        elm->add_cam();
    }
};

class del_cam: public base_order
{
public:
    del_cam(){}
    ~del_cam(){}

    void Execute(scene_composit *elm, int elm_id)
    {
        elm->delete_camera(elm_id);
    }
};

class scale : public base_order
{
private:
    double delta;
public:
    scale(double d): delta(d){}
    ~scale(){}

    void Execute(scene_composit *elm, int elm_id)
    {
        elm->change_model(new change(transform_matrix::scale(delta)),elm_id);
    }
};


class rotate_y : public base_order
{
private:
    double delta;
public:
    rotate_y(double d)
    {
        delta = M_PI/180. * d;
    }
    ~rotate_y(){}

    void Execute(scene_composit *elm, int elm_id)
    {
        elm->change_model(new change(transform_matrix::rotationOY(delta)),elm_id);
    }
};

class rotate_z : public base_order
{
private:
    double delta;
public:
    rotate_z(double d)
    {
        delta = M_PI/180. * d;
    }
    ~rotate_z(){}

    void Execute(scene_composit *elm, int elm_id)
    {
        elm->change_model(new change(transform_matrix::rotationOZ(delta)),elm_id);
    }
};

class rotate_x : public base_order
{
private:
    double delta;
public:
    rotate_x(double d)
    {
        delta = M_PI/180. * d;
    }
    ~rotate_x(){}

    void Execute(scene_composit *elm, int elm_id)
    {
        elm->change_model(new change(transform_matrix::rotationOX(delta)),elm_id);
    }
};

class move_x : public base_order
{
private:
    double delta;
public:
    move_x(double d)
    {
        delta =  d;
    }
    ~move_x(){}

    void Execute(scene_composit *elm, int elm_id)
    {
        elm->change_model(new change(transform_matrix::moveOX(delta)),elm_id);
    }
};

class move_y : public base_order
{
private:
    double delta;
public:
    move_y(double d)
    {
        delta =  d;
    }
    ~move_y(){}

    void Execute(scene_composit *elm, int elm_id)
    {
        elm->change_model(new change(transform_matrix::moveOY(delta)),elm_id);
    }
};

class move_z : public base_order
{
private:
    double delta;
public:
    move_z(double d)
    {
        delta =  d;
    }
    ~move_z(){}

    void Execute(scene_composit *elm, int elm_id)
    {
        elm->change_model(new change(transform_matrix::moveOZ(delta)),elm_id);
    }
};

class yaw_cam : public base_order
{
private:
    double delta;
public:
    yaw_cam(double d)
    {
        this->delta = d;
    }
    ~yaw_cam(){}

    void Execute(scene_composit *elm, int elm_id)
    {
        elm->change_camera(new camera_transformations::yaw(this->delta),elm_id);
    }
};

class pitch_cam : public base_order
{
private:
    double delta;
public:
    pitch_cam(double d)
    {
        this->delta = d;
    }
    ~pitch_cam(){}

    void Execute(scene_composit *elm, int elm_id)
    {
        elm->change_camera(new camera_transformations::pitch(this->delta),elm_id);
    }
};

class roll_cam : public base_order
{
private:
    double delta;
public:
    roll_cam(double d)
    {
        this->delta = d;
    }
    ~roll_cam(){}

    void Execute(scene_composit *elm, int elm_id)
    {
        elm->change_camera(new camera_transformations::roll(this->delta),elm_id);
    }
};
}

#endif // ORDER_H
