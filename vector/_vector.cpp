#include "vector.h"

template <typename T>
vector<T>::vector()
{
    this->_ptr = NULL;
    this->_length = 0;
}

template <typename T>
vector<T>::vector(size_t size)
{
    this->_ptr = new T [size]();
    if(!this->_ptr)
        throw vector_error::memory_error();
    this->_length = size;
}

template <typename T>
vector<T>::vector(size_t size, const T value)
{
    this->_ptr = new T [size](value);
    if(!this->_ptr)
        throw vector_error::memory_error();
    this->_length = size;
}

template <typename T>
vector<T>::vector(const vector<T> &other)
{
    this->_length = other._length;
    this->_ptr = new T [this->_length];
    if(!this->_ptr)
        throw vector_error::memory_error::memory_error();
    for(size_t i = 0; i<this->_length; ++i)
        this->_ptr[i] = other._ptr[i];
}

//template <typename T>
//vector<T>::vector(vector<T> &&other)
//{
//    this->_ptr = other._ptr;
//    this->_length = other._length;
//    other._ptr = NULL;
//    other._length = 0;
//}

template <typename T>
vector<T>::~vector()
{
    delete []_ptr;
}

template <typename T>
vector<T> &vector<T>::operator=(const vector<T> &other)
{
    T* new_ptr = new T[other._length];
    if(!new_ptr)
        throw vector_error::memory_error();

    _delete_vector();

    this->_ptr = new_ptr;
    this->_length = other._length;
    for(size_t i = 0; i< this->_length; ++i)
        this->_ptr[i] = other._ptr[i];
    return *this;
}

//template <typename T>
//vector<T> &vector<T>::operator=(vector<T> &&other)
//{
//    _delete_vector();

//    this->_ptr = other._ptr;
//    this->_length = other._length;
//    other._ptr = NULL;
//    other._length = 0;
//    return *this;
//}

template <typename T>
vector<T> &vector<T>::operator+=(const vector<T> &other)
{
    if(this->_length != other._length)
        throw vector_error::length_error();
    for(size_t i = 0; i<this->_length; ++i)
        this->_ptr[i] += other._ptr[i];
    return *this;
}

template <typename T>
vector<T> vector<T>::operator*(const T &value) const
{
    vector<T> tmp(*this);
    for(size_t i = 0; i<tmp._length; ++i)
        tmp._ptr[i]*=value;
    return tmp;
}

template <typename T>
const size_t vector<T>::length() const
{
    return this->_length;
}

template <typename T>
void vector<T>::resize(const size_t new_size)
{
    size_t len = (this->_length < new_size)? (this->_length) : (new_size);
    vector<T> tmp = *this;
    delete []this->_ptr;
    this->_length = new_size;
    this->_ptr = new T[new_size]();
    if(!this->_ptr)
        throw vector_error::memory_error::memory_error();
    for(size_t i = 0; i<len; ++i)
        this->_ptr[i] = tmp._ptr[i];
}

template <typename T>
void vector<T>::push_back(const T &value)
{
    this->resize(this->_length+1);
    this->_ptr[this->_length-1] = value;
}


template <typename T>
void vector<T>::clear()
{
    delete this->_ptr;
    this->_length = 0;
}

template <typename T>
bool vector<T>::isEmpty()
{
    return (!this->_length) ? (true):(false);
}

template <typename T>
const T *vector<T>::get_ptr_from_object(size_t index)
{
    if(index >= _length)
        throw vector_error::length_error();
    return this->_ptr+index;
}

template <typename T>
T& vector<T>::take(size_t index)
{
    if(index >= _length)
        throw vector_error::length_error();
    T& tmp = this->_ptr[index];
    for(size_t i = index; i<this->_length-1; ++i)
        this->_ptr[i] = this->_ptr[i+1];
    this->resize(this->_length-1);
    return tmp;
}

template <typename T>
T &vector<T>::operator[](const size_t& index)
{
    if(index >= _length)
        throw vector_error::length_error();
    return _ptr[index];
}

template <typename T>
const T &vector<T>::operator [](const size_t &index) const
{
    if(index >= _length)
        throw vector_error::length_error();
    return _ptr[index];
}

template <typename T>
bool vector<T>::operator!()
{
    return !this->_ptr;
}

template <typename T>
void vector<T>::_delete_vector()
{
    if(this->_ptr)
        delete this->_ptr;
}

