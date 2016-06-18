#ifndef BASE_ORDER
#define BASE_ORDER
#include "planner/planner.h"
class base_order
{
public:
    virtual void Execute(planner *elm, size_t elm_id) = 0;
};
#endif // BASE_ORDER

