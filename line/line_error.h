#ifndef LINE_ERROR_H
#define LINE_ERROR_H
#include "base_error/base_error.h"

namespace line_error {

class no_connection : public base_error
{
public:
    no_connection(){}
    const char* what() override
    {
        return "line_error::no connection this point";
    }
};
}

#endif // LINE_ERROR_H
