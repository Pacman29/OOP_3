#ifndef KEEPER_ERROR
#define KEEPER_ERROR
#include "base_error/base_error.h"
namespace keeper_error {

class delete_model_error : public base_error
{
public:
    delete_model_error(){}
    const char* what() override
    {
        return "keeper_error::no model to delete";
    }
};

class no_scene_error : public base_error
{
public:
    no_scene_error(){}
    const char* what() override
    {
        return "keeper_error::no scene";
    }
};

class delete_camera_error : public base_error
{
public:
    delete_camera_error(){}
    const char* what() override
    {
        return "keeper_error::no camera to delete";
    }
};

class camera_error : public base_error
{
public:
    camera_error(){}
    const char* what() override
    {
        return "keeper_error::no camera with that index";
    }
};

class model_error : public base_error
{
public:
    model_error(){}
    const char* what() override
    {
        return "keeper_error::no model with that index";
    }
};
}
#endif // KEEOER_ERROR

