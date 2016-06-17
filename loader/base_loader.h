#ifndef BASE_LOADER
#define BASE_LOADER
#include "point/point.h"
#include "line/line.h"
#include "model/model.h"
class base_loaderImpl;

class base_loader
{
public:
    base_loader(base_loaderImpl* ld) : ldImpl(ld){}
    virtual ~base_loader()
    {
        delete ldImpl;
    }
    virtual bool Load(base_model &Unit, const char *Name) = 0;
protected:
    base_loaderImpl* ldImpl;
};

class base_loaderImpl
{
public:
    virtual ~base_loaderImpl(){}
    virtual bool Load(base_model &Unit, const char *Name) = 0;
};

#endif // BASE_LOADER

