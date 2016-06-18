#ifndef MODEL_CONVER_MANAGER
#define MODEL_CONVER_MANAGER
#include "base_manager/base_manager.h"
#include "keeper.h"
class model_conver_manager : public base_manager
{
public:
    model_conver_manager(){}

    void convert_model(base_transformations* transform, keeper& keep, size_t index)
    {
        if(!index)
        {
            keep.sc->objects.transform(transform);
        }
        else
        {
            keep.get_model(index)->transform(transform);
        }
    }
};

#endif // MODEL_CONVER_MANAGER

