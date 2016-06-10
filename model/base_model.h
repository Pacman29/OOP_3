#ifndef BASE_MODEL_H
#define BASE_MODEL_H
#include "point/point.h"
#include "line/line.h"
#include "vector/vector.h"

class base_model : public visible_object
{
public:
    virtual size_t vertex_count() = 0;
    virtual size_t line_count() = 0;
    virtual void add_vertex(const point& vertex) = 0;
    virtual void add_line(size_t start_index,size_t end_index) = 0;

    virtual point& get_vertex(size_t index) = 0;
    virtual void set_vertex(size_t index, point vertex) = 0;
    virtual line get_line(size_t index) = 0;

    virtual void init_centre() = 0;
    virtual point get_centre() = 0;
    virtual void set_centre(point& center) = 0;

    virtual void transform(base_transformations *transform) = 0;

    virtual void set_name(const char* name) = 0;
    virtual const char* get_name() = 0;

protected:
    vector<point> _vertex;
    vector<line> _line;
    point _centre;
    const char* _name;
};

#endif // BASE_MODEL_H
