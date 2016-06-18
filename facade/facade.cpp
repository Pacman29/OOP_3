#include "facade.h"

facade::facade()
{
    this->err_message = "";
    this->_planner = new planner();
}

