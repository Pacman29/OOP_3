#ifndef BASE_ORDER
#define BASE_ORDER
#include "scene/scene_composit.h"
class base_order
{
public:
    virtual void Execute(scene_composit *elm, int elm_id) = 0;
};
#endif // BASE_ORDER
