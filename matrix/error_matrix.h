#ifndef ERROR_MATRIX_H
#define ERROR_MATRIX_H
#include "base_error_matrix.h"

namespace matrix_error {

class size_error : public base_error_matrix
{
public:
    size_error(){}
    const char* what() override
    {
        return "matrix_error::the dimension of the matrix is set incorrectly";
    }
};

class index_error : public base_error_matrix
{
public:
    index_error(){}
    const char* what() override
    {
        return "matrix_error::incorrect index";
    }
};

class different_size_error : public base_error_matrix
{
public:
    different_size_error(){}
    const char* what() override
    {
        return "matrix_error::matrix of different size";
    }
};

class incorrect_multiplication : public base_error_matrix
{
public:
    incorrect_multiplication(){}
    const char* what() override
    {
        return "matrix_error::incorrect_multiplication";
    }
};


class memory_error : public base_error_matrix
{
public:
    memory_error(){}
    const char* what() override
    {
        return "matrix_error::memory is not allocated";
    }
};
}

#endif // ERROR_MATRIX_H
