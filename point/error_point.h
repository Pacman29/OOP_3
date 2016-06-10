#ifndef ERROR_POINT_H
#define ERROR_POINT_H
#include "base_error/base_error.h"

namespace point_error {

class vector_error : public base_error
{
public:
    vector_error(){}
    const char* what() override
    {
        return "point_error::vector dimension incorrectly";
    }
};

}
#endif // ERROR_POINT_H
