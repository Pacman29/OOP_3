#ifndef FACADE_H
#define FACADE_H
#include "order.h"
class facade
{
public:
    facade();
    ~facade();
    bool GetCommand(base_order &Element,int Count)
    {
        try
        {
            Element.Execute(_scene,Count);
        }
        catch(base_error& er)
        {
            this->err_message = er.what();
            return false;
        }
        return true;
    }

    const char* get_error_message()
    {
        const char* msg = this->err_message;
        this->err_message = "";
        return msg;
    }
private:
    scene_composit *_scene;
    const char* err_message;
};

#endif // FACADE_H
