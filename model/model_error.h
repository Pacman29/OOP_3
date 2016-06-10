#ifndef MODEL_ERROR_H
#define MODEL_ERROR_H
#include "base_error/base_error.h"

namespace model_error
{
class index_error : public base_error
{
public:
    index_error(){}
    const char* what() override
    {
        return "model_error::input incorrect index";
    }
};
class empty_error : public base_error
{
public:
    empty_error(){}
    const char* what() override
    {
        return "model_error::model array is empty";
    }
};


}

#endif // MODEL_ERROR_H
