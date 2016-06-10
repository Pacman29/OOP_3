#ifndef INVISIBLE_OBJECT_H
#define INVISIBLE_OBJECT_H
#include "base_object.h"

class invisible_object : public base_object
{
public:
    bool is_display() override;
    virtual void transform(base_transformations *transform) = 0;
};

#endif // INVISIBLE_OBJECT_H
