#ifndef BASE_LOADER
#define BASE_LOADER
#include "point/point.h"
#include "line/line.h"
#include "model/model.h"
class base_loader
{
public:
    virtual bool Load(model &Unit, const char *Name) = 0;

};
#endif // BASE_LOADER

