#include "composit_object.h"

base_object *composit_object::operator [](size_t index)
{
    return this->arr[index];
}

size_t composit_object::length()
{
    return arr.length();
}
