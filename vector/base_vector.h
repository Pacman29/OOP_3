#ifndef BASE_VECTOR_H
#define BASE_VECTOR_H
#include "cstddef"

class base_vector
{
public:
    virtual const size_t length() const = 0;
protected:
    size_t _length;
};

#endif // BASE_VECTOR_H
