#ifndef CAMERA_H
#define CAMERA_H
#include "camera_error.h"
#include "base_camera.h"
#include "point/point.h"
#include "object/invisible_object.h"
#include "geometric_transformations/geometric_transformations.h"
#include "vector/g_vector.h"

class camera : public base_camera
{
public:
    camera();
    camera(point& pos, point& target, double& pitch, double& yaw, double& roll);
    void set_position(point pos) override;
    void set_target(point target) override;
    matrix<double> GetViewMatrix() override;
    void RotationUpDownSphere(double angle) override;
    void RotationRightLeftSphere(double angle) override;

    void transform(base_transformations *transform) override;

    void pitch(double angle) override;
    void yaw(double angle) override;
    void roll(double angle) override;
};
#include "base_camera_transformations.h"
#endif // CAMERA_H
