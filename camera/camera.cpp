#include "camera.h"
#include "camera_transformations.h"
#include "base_camera_transformations.h"
camera::camera()
{
    this->right.resize(4);
    this->right[0] = this->right[3] = 1;;
    this->up.resize(4);
    this->up[1] = this->up[3] = 1;
    this->look.resize(4);
    this->look[2] = this->look[3] = 1;
    this->pos.resize(4);
    this->pos[3] = 1;
    this->target.resize(4);
    this->target[3] = 1;
}

camera::camera(point &pos, point &target, double &pitch, double &yaw, double &roll)
{
    this->pos = pos.to_vector();
    this->target = target.to_vector();
    this->right.resize(4);
    this->right[0] = this->right[3] = 1;;
    this->up.resize(4);
    this->up[1] = this->up[3] = 1;
    this->look.resize(4);
    this->look[2] = this->look[3] = 1;
    this->pitch(pitch);
    this->yaw(yaw);
    this->roll(roll);
}

void camera::set_position(point pos)
{
    this->pos = pos.to_vector();
}

void camera::set_target(point target)
{
    this->target = target.to_vector();
}

void camera::RotationUpDownSphere(double angle)
{
    matrix<double> transform = transform_matrix::rotation(this->up[0],this->up[1],this->up[2],angle);
    this->right = this->right * transform;
    this->look = this->look * transform;
    matrix<double> move = transform_matrix::move(this->target[0], this->target[1], this->target[2]);
    this->pos = this->pos * (-move) * transform * move;
}

void camera::RotationRightLeftSphere(double angle)
{
    matrix<double> transform = transform_matrix::rotation(this->right[0],this->right[1],this->right[2],angle);
    this->up = this->up * transform;
    this->look = this->look * transform;
    matrix<double> move = transform_matrix::move(this->target[0], this->target[1], this->target[2]);
    this->pos = this->pos * (-move) * transform * move;
}

void camera::transform(base_transformations *transform)
{
    if(!transform->is_visible())
        ((base_camera_transformations*)transform)->execute(this);
}

void camera::pitch(double angle)
{
    matrix<double> transform = transform_matrix::rotation(this->right[0],this->right[1],this->right[2],angle);
    this->up = this->up * transform;
    this->look = this->look * transform;
}

void camera::yaw(double angle)
{
    matrix<double> transform = transform_matrix::rotation(this->up[0],this->up[1],this->up[2],angle);
    this->right = this->right * transform;
    this->look = this->look * transform;
}

void camera::roll(double angle)
{
    matrix<double> transform = transform_matrix::rotation(this->look[0],this->look[1],this->look[2],angle);
    this->right = this->right * transform;
    this->up = this->up * transform;
}



matrix<double> camera::GetViewMatrix()
{
    this->look.normalize_vector();

    this->up = G_vector::cross(this->look,this->right);
    this->up.normalize_vector();

    this->right = G_vector::cross(this->up,this->look);
    this->right.normalize_vector();

    double x = -G_vector::scalar(this->right,this->pos);
    double y = -G_vector::scalar(this->up,this->pos);
    double z = -G_vector::scalar(this->look,this->pos);

    matrix<double> tmp(4,4);
    tmp.set_column(0,this->right);
    tmp.set_column(1,this->up);
    tmp.set_column(2,this->look);
    tmp[3][0] = x;
    tmp[3][1] = y;
    tmp[3][2] = z;
    tmp[3][3] = 1;
    return tmp;
}


