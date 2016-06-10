#include "matrix.h"

template <typename T>
matrix<T>::matrix()
{
    matrix<T>(1,1);
}

template <typename T>
matrix<T>::matrix(matrix<T>& other)
{
    M.resize(other._row_count);
    for(size_t i = 0; i<other._row_count; ++i)
        M[i].resize(other._column_count);


    this->_column_count =other._column_count;
    this->_row_count =other._row_count;

    for(size_t i = 0; i<this->_row_count; ++i)
        for(size_t j = 0; j<this->_column_count; ++j)
            M[i][j] = other[i][j];
}

template <typename T>
matrix<T>::matrix(matrix<T> &&other)
{
    M.resize(other._row_count);
    for(size_t i = 0; i<other._row_count; ++i)
        M[i].resize(other._column_count);


    this->_column_count =other._column_count;
    this->_row_count =other._row_count;

    for(size_t i = 0; i<this->_row_count; ++i)
        for(size_t j = 0; j<this->_column_count; ++j)
            M[i][j] = other[i][j];
}

template <typename T>
matrix<T>::matrix(size_t row_count, size_t column_count)
{
    if(!(row_count && column_count))
        throw matrix_error::size_error();

    this->_column_count = column_count;
    this->_row_count = row_count;

    M.resize(row_count);
    for(size_t i = 0; i<row_count; ++i)
        M[i].resize(column_count);

}

template <typename T>
matrix<T>::matrix(size_t row_count, size_t column_count, T& value)
{
    if(!(row_count && column_count))
        throw matrix_error::size_error();

    this->_column_count = column_count;
    this->_row_count = row_count;

    M.resize(row_count);
    for(size_t i = 0; i<row_count; ++i)
        M[i].resize(column_count);

    for(size_t i = 0; i<this->_row_count; ++i)
        for(size_t j = 0; j<this->_column_count; ++j)
            M[i][j] = value;
}

template <typename T>
matrix<T>::matrix(size_t row_count, size_t column_count, T value)
{
    if(!(row_count && column_count))
        throw matrix_error::size_error();

    this->_column_count = column_count;
    this->_row_count = row_count;

    M.resize(row_count);
    for(size_t i = 0; i<row_count; ++i)
        M[i].resize(column_count);

    for(size_t i = 0; i<this->_row_count; ++i)
        for(size_t j = 0; j<this->_column_count; ++j)
            M[i][j] = value;
}

template <typename T>
void matrix<T>::add_column(vector<T> &vec)
{
    if(vec.length() != this->_row_count)
        throw matrix_error::size_error();

    for(size_t i = 0; i<this->_row_count; ++i)
    {
        M[i].resize(this->_column_count+1);
        M[i][this->_column_count] = vec[i];
    }
    this->_column_count++;
}

template <typename T>
void matrix<T>::add_row(vector<T> &vec)
{
    if(vec.length() != this->_column_count)
        throw matrix_error::size_error();

    this->M.resize(this->_row_count+1);

    for(size_t i = 0; i<this->_column_count; ++i)
        M[this->_row_count][i] = vec[i];

    this->_row_count++;
}

template <typename T>
void matrix<T>::set_row(size_t index, vector<T> vec)
{
    if( index>=this->_row_count)
        throw matrix_error::index_error();

    if(vec.length() != this->_column_count)
        throw matrix_error::size_error();

    for(size_t i = 0; i<this->_column_count; ++i)
        M[index][i] = vec[i];
}


template <typename T>
void matrix<T>::set_column(size_t index, vector<T> vec)
{
    if( index>=this->_row_count)
        throw matrix_error::index_error();

    if(vec.length() != this->_row_count)
        throw matrix_error::size_error();

    for(size_t i = 0; i<this->_row_count; ++i)
        M[i][index] = vec[i];
}

template <typename T>
void matrix<T>::set_row_count(size_t row_count)
{

    if(row_count == 0)
        throw matrix_error::size_error();
    M.resize(row_count);
    for(size_t i = this->_row_count; i<row_count; ++i)
        M[i].resize(this->_column_count);
    this->_row_count = row_count;
}

template <typename T>
void matrix<T>::set_column_count(size_t column_count)
{
    if(column_count == 0)
        throw matrix_error::size_error();
    for(size_t i = 0; i<this->_row_count; ++i)
        M[i].resize(column_count);
    this->_column_count = column_count;
}

template <typename T>
matrix<T> &matrix<T>::operator=(matrix<T> &other)
{
    M.resize(other._row_count);
    for(size_t i = 0; i<other._row_count; ++i)
        M[i].resize(other._column_count);

    this->_row_count = other._row_count;
    this->_column_count = other._column_count;

    for(size_t i = 0; i<this->_row_count; ++i)
        for(size_t j = 0; j<this->_column_count; ++j)
            M[i][j] = other[i][j];
    return *this;
}


template <typename T>
matrix<T> &matrix<T>::operator=(matrix<T> &&other)
{
    M.resize(other._row_count);
    for(size_t i = 0; i<other._row_count; ++i)
        M[i].resize(other._column_count);

    this->_row_count = other._row_count;
    this->_column_count = other._column_count;

    for(size_t i = 0; i<this->_row_count; ++i)
        for(size_t j = 0; j<this->_column_count; ++j)
            M[i][j] = other[i][j];
    return *this;
}

template <typename T>
vector<T> &matrix<T>::operator[](const size_t index)
{
    return M[index];
}

template <typename T>
matrix<T>::~matrix()
{

}

template <typename T>
matrix<T> matrix<T>::transposition()
{
    matrix<T> res(this->_column_count,this->_row_count);
    for(size_t i = 0; i<this->_row_count;++i)
        for(size_t j = 0; j<this->_column_count;++j)
            res[j][i] = M[i][j];
    return res;
}

template <typename T>
const vector<T> matrix<T>::get_row(size_t index)
{
    vector<T> res(M[index]);
    return res;
}

template<typename T>
const vector<T> matrix<T>::get_column(size_t index)
{
    vector<T> res(this->_row_count);
    for(size_t i = 0; i<this->_row_count; ++i)
        res[i] = M[i][index];
    return res;
}

template <typename T>
const vector<T> matrix<T>::get_row(size_t index) const
{
    vector<T> res(M[index]);
    return res;
}

template<typename T>
const vector<T> matrix<T>::get_column(size_t index) const
{
    vector<T> res(this->_row_count);
    for(size_t i = 0; i<this->_row_count; ++i)
        res[i] = M[i][index];
    return res;
}

template <typename T>
matrix<T> matrix<T>::operator+()
{
    return *this;
}

template <typename T>
matrix<T> matrix<T>::operator-()
{
    return *this *(-1);
}

template <typename T>
matrix<T> matrix<T>::operator+(const matrix<T> &other)
{
    if(!check_size(other))
        throw matrix_error::different_size_error();

    matrix res(*this);
    for(size_t i = 0; i<this->_row_count;++i)
        for(size_t j = 0; j<this->_column_count;++j)
            res[i][j] += other[i][j];
    return res;
}

template <typename T>
matrix<T> matrix<T>::operator+(const T &value)
{
    matrix res(*this);
    for(size_t i = 0; i<this->_row_count;++i)
        for(size_t j = 0; j<this->_column_count;++j)
            res[i][j] += value;
    return res;
}

template <typename T>
matrix<T> &matrix<T>::operator+=(const T &value)
{
    for(size_t i = 0; i<this->_row_count;++i)
        for(size_t j = 0; j<this->_column_count;++j)
            M[i][j] += value;
    return *this;
}

template <typename T>
matrix<T> &matrix<T>::operator+=(const matrix<T> &other)
{
    if(!check_size(other))
        throw matrix_error::different_size_error();

    for(size_t i = 0; i<this->_row_count;++i)
        for(size_t j = 0; j<this->_column_count;++j)
            M[i][j] += other[i][j];
    return *this;
}

template <typename T>
matrix<T> &matrix<T>::operator-=(const matrix<T> &other)
{
    if(!check_size(other))
        throw matrix_error::different_size_error();

    for(size_t i = 0; i<this->_row_count;++i)
        for(size_t j = 0; j<this->_column_count;++j)
            M[i][j] -= other[i][j];
    return *this;
}

template <typename T>
matrix<T> matrix<T>::operator*(const matrix<T> &other)
{
    if(this->_column_count != other._row_count)
        throw matrix_error::incorrect_multiplication();

    matrix<T> res(this->_row_count,other._column_count);
    for(size_t i = 0; i<res._row_count;++i)
        for(size_t j = 0; j<res._column_count;++j)
        {
            vector<T> row = this->get_row(i);
            vector<T> column = other.get_column(j);
            T sum = 0;
            for(size_t k = 0; k<this->_row_count; ++k)
                sum += row[k]*column[k];
            res[i][j] = sum;
        }
    return res;
}

template <typename T>
matrix<T> matrix<T>::operator*(const T &value)
{
    matrix<T> res(*this);
    for(size_t i = 0; i<res._row_count;++i)
        for(size_t j = 0; j<res._column_count;++j)
            res[i][j] *= value;
    return res;
}

template <typename T>
matrix<T> &matrix<T>::operator*=(const T &value)
{
    for(size_t i = 0; i<this->_row_count;++i)
        for(size_t j = 0; j<this->_column_count;++j)
            M[i][j] *= value;
    return *this;
}

template <typename T>
matrix<T> &matrix<T>::operator*=(const matrix<T> &other)
{
    if(this->_column_count != other._row_count)
        throw matrix_error::incorrect_multiplication();

    matrix<T> tmp = *this;

    M.resize(tmp._row_count);
    for(size_t i = 0; i<tmp._row_count; ++i)
        M[i].resize(other._column_count);

    this->_row_count = tmp._row_count;
    this->_column_count = other._column_count;

    for(size_t i = 0; i<this->_row_count;++i)
        for(size_t j = 0; j<this->_column_count;++j)
        {
            vector<T> row = tmp.get_row(i);
            vector<T> column = other.get_column(j);
            T sum = 0;
            for(size_t k = 0; k<this->_row_count; ++k)
                sum += row[k]*column[k];
            M[i][j] = sum;
        }
    return *this;
}

template <typename T>
bool matrix<T>::operator==(const matrix<T> &other)
{
    if(!check_size(other))
        throw matrix_error::different_size_error();

    for(size_t i = 0; i<this->_row_count;++i)
        for(size_t j = 0; j<this->_column_count;++j)
            if(M[i][j] != other[i][j])
                return false;
    return true;
}

template <typename T>
bool matrix<T>::operator!=(const matrix<T> &other)
{
    return !(*this == other);
}

template <typename T>
matrix<T> &matrix<T>::operator/=(const T &value)
{
    for(size_t i = 0; i<this->_row_count;++i)
        for(size_t j = 0; j<this->_column_count;++j)
            M[i][j] /= value;
    return *this;
}

template <typename T>
matrix<T> matrix<T>::operator/(const T &value)
{
    matrix res(*this);
    for(size_t i = 0; i<res._row_count;++i)
        for(size_t j = 0; j<res._column_count;++j)
            res[i][j] /= value;
    return res;
}

template <typename T>
matrix<T> &matrix<T>::operator-=(const T &value)
{
    for(size_t i = 0; i<this->_row_count;++i)
        for(size_t j = 0; j<this->_column_count;++j)
            M[i][j] -= value;
    return *this;
}

template <typename T>
matrix<T> matrix<T>::operator-(const T &value)
{
    matrix res(*this);
    for(size_t i = 0; i<res._row_count;++i)
        for(size_t j = 0; j<res._column_count;++j)
            res[i][j] -= value;
    return res;
}

template <typename T>
matrix<T> matrix<T>::operator-(const matrix<T> &other)
{
    if(!check_size(other))
        throw matrix_error::different_size_error();

    matrix res(*this);
    for(size_t i = 0; i<this->_row_count;++i)
        for(size_t j = 0; j<this->_column_count;++j)
            res[i][j] -= other[i][j];
    return res;
}

template <typename T>
bool matrix<T>::check_size(const matrix<T> &other)
{
    if((this->_row_count != other._row_count) ||
            (this->_column_count != other._column_count))
        return false;
    return true;
}


