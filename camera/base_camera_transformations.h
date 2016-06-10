#ifndef BASE_CAMERA_TRANSFORMATIONS
#define BASE_CAMERA_TRANSFORMATIONS
#include "transformations/transformations.h"
#include "camera.h"
class base_camera_transformations : public base_transformations
{
public:
    virtual void execute(camera* _camera) = 0;
};
#endif // BASE_CAMERA_TRANSFORMATIONS

