#include <cstddef>
#include "base_matrix.h"
#include "error_matrix.h"
#include "vector/vector.h"
using namespace matrix_error;
template <typename T>
class matrix : private base_matrix
{
public:
    matrix();
    matrix(matrix<T>& other);
    matrix(matrix<T>&& other);
    matrix(size_t row_count, size_t column_count);
    matrix(size_t row_count, size_t column_count, T &value);
    matrix(size_t row_count, size_t column_count, T value);
    const size_t row_count() override   {return _row_count;}
    const size_t column_count() override {return _column_count;}

    void add_column(vector<T>& vec);
    void add_row(vector<T>& vec);

    void set_row(size_t index, vector<T> vec);
    void set_column(size_t index, vector<T> vec);

    void set_row_count(size_t row_count);
    void set_column_count(size_t column_count);

    const size_t row_count() const override   {return _row_count;}
    const size_t column_count() const override {return _column_count;}

    matrix<T>& operator=  (matrix<T>& other);
    matrix<T>& operator=  (matrix<T> &&other);

    vector<T>& operator[] (const size_t index);

    ~matrix();

    matrix<T> transposition();
    const vector<T> get_row(size_t index);
    const vector<T> get_column(size_t index);

    const vector<T> get_row(size_t index) const;
    const vector<T> get_column(size_t index) const;


    matrix<T>  operator+  ();
    matrix<T>  operator+  (const matrix<T>& other);
    matrix<T>  operator+  (const T& value);
    matrix<T>& operator+= (const T& value);
    matrix<T>& operator+= (const matrix<T>& other);
    matrix<T>  operator-  ();
    matrix<T>  operator-  (const matrix<T>& other);
    matrix<T>  operator-  (const T& value);
    matrix<T>& operator-= (const T& value);
    matrix<T>& operator-= (const matrix<T>& other);

    matrix<T>  operator*  (const matrix<T>& other);
    matrix<T>  operator*  (const T& value);

    matrix<T>& operator*= (const T& value);
    matrix<T>& operator*= (const matrix<T>& other);
    matrix<T>  operator/  (const T& value);
    matrix<T>& operator/= (const T& value);

    bool            operator== (const matrix<T>& other);
    bool            operator!= (const matrix<T>& other);

private:
    vector<vector<T>> M;
    bool check_size(const matrix<T>& other);
};

template <typename t1>
matrix<t1> operator*(const t1 &value, const matrix<t1> &other)
{
    matrix<t1> res(other);
    for(size_t i = 0; i<res.row_count();++i)
        for(size_t j = 0; j<res.column_count();++j)
            res[i][j] *= value;
    return res;
}

template <typename t1>
vector<t1> operator*(vector<t1> vec, matrix<t1> other)
{
    if(vec.length() != other.row_count())
        throw matrix_error::incorrect_multiplication();

    vector<t1> res(other.column_count());
    for(size_t i = 0; i<res.length();++i)
        for(size_t j = 0; j<other.row_count();++j)
            res[i] += other[j][i]*vec[j];
    return res;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, matrix<T>& M)
{
    for(size_t j = 0; j<M.row_count(); ++j)
        stream << M[j] << std::endl;

    return stream;
}
#include "_matrix.cpp"
