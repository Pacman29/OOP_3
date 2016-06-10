#ifndef VISIBLE_OBJECT_H
#define VISIBLE_OBJECT_H
#include "base_object.h"

class visible_object : public base_object
{
public:
    bool is_display() override;
    virtual void transform(base_transformations *transform) = 0;
    bool add(base_object *) override{return false;}
};

#endif // VISIBLE_OBJECT_H
