#ifndef BASE_ITERATOR
#define BASE_ITERATOR
#include <cstddef>
class base_iterator
{
public:
    virtual void next() = 0;
    virtual void prev() = 0;
    virtual void first() = 0;
    virtual void last() = 0;

protected:
    size_t pos;
};

#endif // BASE_ITERATOR

