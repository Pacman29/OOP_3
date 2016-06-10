#ifndef BASE_CAMERA
#define BASE_CAMERA
#include "matrix/matrix.h"
#include "vector/g_vector.h"
#include "point/point.h"
#include "object/invisible_object.h"
class base_camera : public invisible_object
{
public:
    virtual void set_target(point target) = 0;
    virtual void set_position(point pos) = 0;
    virtual matrix<double> GetViewMatrix() = 0;
    virtual void RotationUpDownSphere(double angle) = 0;
    virtual void RotationRightLeftSphere(double angle) = 0;
    virtual void transform(base_transformations *transform) = 0;
    virtual void pitch(double angle) = 0;
    virtual void yaw(double angle) = 0;
    virtual void roll(double angle) = 0;

protected:
    G_vector look;
    G_vector up;
    G_vector right;

    G_vector pos;
    G_vector target;
};
#endif // BASE_CAMERA

