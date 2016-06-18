#ifndef BASE_MATRIX_H
#define BASE_MATRIX_H
#include "cstddef"

class base_matrix
{
public:
    virtual const size_t& row_count() = 0;
    virtual const size_t& column_count() = 0;

    virtual const size_t& row_count() const = 0;
    virtual const size_t& column_count() const = 0;
protected:
    size_t _row_count;
    size_t _column_count;
};

#endif // BASE_MATRIX_H
