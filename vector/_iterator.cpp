#include "iterator.h"

template <typename T>
iterator<T>::iterator(const vector<T> &v)
{
    if(v.isEmpty())
        throw iterator_error::length_error();
    this->v = &v;
    this->pos = 0;
}

template <typename T>
iterator<T>::iterator(const iterator<T> &it)
{
    this->pos = it.pos;
    this->v = it.v;
}

template <typename T>
iterator<T>::~iterator()
{
    this->pos = 0;
    this->v = NULL;
}

template <typename T>
size_t iterator<T>::position()
{
    return this->pos;
}

template <typename T>
size_t iterator<T>::distance(const iterator<T> &it)
{
    if(!check_one(it))
        throw iterator_error::different_error();

    if(it.pos < this->pos)
        return this->pos - it.pos;
    return it.pos - this->pos;
}

template <typename T>
void iterator<T>::swap(iterator<T> &it)
{
    if(!check_one(it))
        throw iterator_error::different_error();

    unsigned tmp = this->pos;
    this->pos = it.pos;
    it.pos = tmp;
}

template <typename T>
void iterator<T>::advance(const int &i)
{
    if(i+this->pos > this->v->count-1 ||  i+this->pos < 0)
        throw iterator_error::index_error();
    this->pos += i;
}

template <typename T>
bool iterator<T>::check_one(const iterator<T> &it)
{
    return (this->v == it.v);
}

template <typename T>
T iterator<T>::value()
{
    return this->v->coord[pos];
}

template <typename T>
void iterator<T>::next()
{
    this->pos++;
}

template <typename T>
void iterator<T>::prev()
{
    this->pos--;
}

template <typename T>
void iterator<T>::first()
{
    this->pos = 0;
}

template <typename T>
void iterator<T>::last()
{
    this->pos = this->v->_length-1;
}

template <typename T>
iterator<T> &iterator<T>::operator =(const iterator<T> &it)
{
    this->v = it.v;
    this->pos = it.pos;

    return *this;
}

template <typename T>
iterator<T> &iterator<T>::operator ++()
{
    this->next();
    return *this;
}

template <typename T>
iterator<T> &iterator<T>::operator --()
{
    this->prev();
    return *this;
}

template <typename T>
iterator<T> iterator<T>::operator ++(int)
{
    iterator<T> it(*this);
    ++(*this);
    return it;
}

template <typename T>
iterator<T> iterator<T>::operator --(int)
{
    iterator<T> it(*this);
    --(*this);
    return it;
}

template <typename T>
iterator<T> &iterator<T>::operator +=(const unsigned &n)
{
    advance(n);
    return *this;
}

template <typename T>
iterator<T> &iterator<T>::operator -=(const unsigned &n)
{
    int i = n;
    i *= -1;
    advance(i);
    return *this;
}

template <typename T>
iterator<T> iterator<T>::operator +(const unsigned &n)
{
    iterator<T> it(*this);
    it+=n;
    return it;
}

template <typename T>
iterator<T> iterator<T>::operator -(const unsigned &n)
{
    iterator<T> it(*this);
    it-=n;
    return it;
}

template <typename T>
T iterator<T>::operator *()
{
    return this->v->operator [](pos);
}

template <typename T>
T iterator<T>::operator [](const unsigned &i)
{
    if(i >= this->v->count)
        throw iterator_error::index_error();
    return this->v->coord[i];
}

template <typename T>
bool iterator<T>::operator ==(const iterator<T> &it)
{
    if(!check_one(it))
        throw iterator_error::different_error();

    return this->pos == it.pos;
}

template <typename T>
bool iterator<T>::operator !=(const iterator<T> &it)
{
//    if(!check_one(it))
//        throw iterator_error::different_error();

    return this->pos != it.pos;
}

template <typename T>
bool iterator<T>::operator >(const iterator<T> &it)
{
    if(!check_one(it))
        throw iterator_error::different_error();

    return this->pos > it.pos;
}

template <typename T>
bool iterator<T>::operator >=(const iterator<T> &it)
{
    if(!check_one(it))
        throw iterator_error::different_error();

    return this->pos >= it.pos;
}

template <typename T>
bool iterator<T>::operator <(const iterator<T> &it)
{
    if(!check_one(it))
        throw iterator_error::different_error();

    return this->pos < it.pos;
}

template <typename T>
bool iterator<T>::operator <=(const iterator<T> &it)
{
    if(!check_one(it))
        throw iterator_error::different_error();

    return this->pos <= it.pos;
}
