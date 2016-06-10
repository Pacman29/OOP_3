#ifndef CAMERA_ERROR
#define CAMERA_ERROR
#include "base_error/base_error.h"
namespace camera_error
{
class empty_error : public base_error
{
public:
    empty_error(){}
    const char* what() override
    {
        return "camera_error::camera array is empty";
    }
};
}
#endif // CAMERA_ERROR

