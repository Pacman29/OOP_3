#ifndef ERROR_ITERATOR
#define ERROR_ITERATOR
#include "base_error/base_error.h"
namespace iterator_error {

class length_error : public base_error
{
public:
    length_error(){}
    const char* what() override
    {
        return "iterator_error::vector is empty";
    }
};

class different_error : public base_error
{
public:
    different_error(){}
    const char* what() override
    {
        return "iterator_error::iterators are different";
    }
};

class index_error : public base_error
{
public:
    index_error(){}
    const char* what() override
    {
        return "iterator_error::index is incorrect";
    }
};
}
#endif // ERROR_ITERATOR

