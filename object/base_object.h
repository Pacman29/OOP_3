#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H
#include "transformations/transformations.h"

class base_object
{
public:
    virtual bool is_display() = 0;
    virtual void transform(base_transformations *transform) = 0;
    virtual bool add(base_object *){return false;}
};

#endif // BASE_OBJECT_H
