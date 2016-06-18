#ifndef COMPOSIT_OBJECT_H
#define COMPOSIT_OBJECT_H
#include "object/base_object.h"
#include "vector/vector.h"
class composit_object : public base_object
{
public:

    typedef iterator<base_object*> it;

    composit_object(){}
    void transform(base_transformations* transform)
    {
        for(iterator<base_object*> it = arr.begin(); it <= arr.end(); ++it)
            (*it)->transform(transform);
    }
    base_object* operator [](size_t index);
    bool add(base_object * obj) override
    {
        if(obj)
        {
            arr.push_back(obj);
            return true;
        }
        return false;
    }
    void del(size_t index)
    {
        arr.take(index);
    }
    bool is_display()
    {
        return false;
    }

    it begin()
    {
        return this->arr.begin();
    }

    it end()
    {
        return this->arr.end();
    }

    size_t length();

private:
    vector<base_object*> arr;
};

#endif // COMPOSIT_OBJECT_H
