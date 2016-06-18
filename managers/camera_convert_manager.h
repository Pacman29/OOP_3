#ifndef CAMERA_CONVERT_MANAGER
#define CAMERA_CONVERT_MANAGER
#include "base_manager/base_manager.h"
#include "keeper.h"
class camera_conver_manager : public base_manager
{
public:
    camera_conver_manager(){}
    ~camera_conver_manager(){}
    void convert_camera(base_transformations* transform, keeper& keep, size_t index)
    {
        keep.get_camera(index)->transform(transform);
    }
};
#endif // CAMERA_CONVERT_MANAGER

