#include "cstddef"
#include "base_vector.h"
#include "error_vector.h"
using namespace vector_error;

template <typename T>
class iterator;

template <typename T>
class vector : private base_vector
{
public:
    vector();
    vector(size_t size);
    vector(size_t size,const T value);
    vector(const vector<T>& other);
    ~vector();

    vector<T>& operator=  (const vector<T>& other);
    vector<T>& operator+= (const vector<T>& other);
    vector<T>  operator*  (const T& value) const;

    const size_t length() const override;
    void resize(const size_t new_size);
    void push_back(const T& value);
    void clear();
    bool isEmpty() const;
    const T* get_ptr_from_object(size_t index);
    T &take(size_t index);

    T& operator[] (const size_t& index);
    const T& operator [](const size_t& index) const;

    bool operator! ();

    friend class iterator<T>;

    iterator<T> begin() const;
    iterator<T> end() const;

private:
    void _delete_vector();
    T* _ptr;
};

template<typename T>
std::ostream& operator<<(std::ostream& stream, vector<T>& vec)
{
    stream <<"( ";
    size_t i = 0;
    for(; i<vec.length()-1; ++i)
        stream << vec[i] << ", ";
    stream << vec[i] << " )";
    return stream;
}

#include "_vector.cpp"
