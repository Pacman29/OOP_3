#ifndef _ITERATOR_H
#define _ITERATOR_H
#include "base_iterator.h"
#include "vector.h"
#include "error_iterator.h"

template <typename T>
class iterator : public base_iterator
{
public:
    iterator(const vector<T> &v);
    iterator(const iterator<T> & it);
    ~iterator();

    size_t position();
    size_t distance(const iterator<T> &it);
    void swap(iterator<T> &it);
    void advance(const int& i);
    bool check_one(const iterator<T> &it);
    T value();

    iterator<T>& operator = (const iterator<T>& it);
    void next() override;
    void prev() override;
    void first() override;
    void last() override;

    iterator<T>& operator ++();
    iterator<T>& operator --();
    iterator<T>& operator +=(const unsigned &n);
    iterator<T>& operator -=(const unsigned &n);
    iterator<T>  operator ++(int);
    iterator<T>  operator --(int);
    iterator<T>  operator + (const unsigned &n);
    iterator<T>  operator - (const unsigned &n);

    T operator *();
    T operator [](const unsigned& i);

    bool operator ==(const iterator<T> &itr);
    bool operator !=(const iterator<T> &itr);
    bool operator > (const iterator<T> &itr);
    bool operator >=(const iterator<T> &itr);
    bool operator < (const iterator<T> &itr);
    bool operator <=(const iterator<T> &itr);

private:
    const vector<T> *v;
};

#include "_iterator.cpp"
#endif
