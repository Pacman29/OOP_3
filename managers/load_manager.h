#ifndef LOAD_MANAGER
#define LOAD_MANAGER
#include "base_manager/base_manager.h"
#include "loader/loader.h"
class load_manager : public base_manager
{
public:
    load_manager() : ld(new file_loader){}
    ~load_manager(){}

    base_object* load_obj( const char *name)
    {
        base_model* mdl = new model();
        this->ld->Load(*mdl,name);
        return (base_object*) mdl;
    }
private:
    base_loader* ld;
};

#endif // LOAD_MANAGER

