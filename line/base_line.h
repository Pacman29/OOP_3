#ifndef BASE_LINE_H
#define BASE_LINE_H
#include "point/point.h"
#include "object/visible_object.h"
class base_line : public visible_object
{
public:
    virtual size_t start() = 0;
    virtual size_t  end() = 0;

    virtual void set_start(size_t  start) = 0;
    virtual void set_end(size_t  end) = 0;
    virtual void transform(base_transformations *transform) = 0;
protected:
    size_t  _start;
    size_t  _end;
};

#endif // BASE_LINE_H
