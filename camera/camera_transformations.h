#ifndef CAMERA_TRANSFORMATIONS
#define CAMERA_TRANSFORMATIONS
#include "base_camera_transformations.h"
#include "camera.h"
#define M_PI		3.14159265358979323846
namespace camera_transformations
{
class yaw : public base_camera_transformations
{
public:
    yaw(double degree)
    {
        this->_angle = degree * M_PI/180.0;
    }

    void execute(camera* _camera) override
    {
        _camera->yaw(this->_angle);
    }
private:
    double _angle;
};

class pitch : public base_camera_transformations
{
public:
    pitch(double degree)
    {
        this->_angle = degree * M_PI/180.0;
    }

    void execute(camera* _camera) override
    {
        _camera->pitch(this->_angle);
    }
private:
    double _angle;
};

class roll : public base_camera_transformations
{
public:
    roll(double degree)
    {
        this->_angle = degree * M_PI/180.0;
    }

    void execute(camera* _camera) override
    {
        _camera->roll(this->_angle);
    }
private:
    double _angle;
};

class position : public base_camera_transformations
{
public:
    position(point pos)
    {
        this->_pos = pos;
    }

    void execute(camera* _camera) override
    {
        _camera->set_position(this->_pos);
    }
private:
    point _pos;
};

class target : public base_camera_transformations
{
public:
    target(point target)
    {
        this->_target = target;
    }

    void execute(camera* _camera) override
    {
        _camera->set_target(this->_target);
    }
private:
    point _target;
};
}
#endif // CAMERA_TRANSFORMATIONS

