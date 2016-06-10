#ifndef MODEL_H
#define MODEL_H
#include "object/visible_object.h"
#include "point/_point.h"
#include "line/line.h"
#include "model_error.h"
#include "base_model.h"
#include "matrix/matrix.h"
#include "geometric_transformations/geometric_transformations.h"

class model : public base_model
{
public:
    model();
    size_t vertex_count() override;
    size_t line_count() override;
    void add_vertex(const point& vertex) override;
    void add_line(size_t start_index,size_t end_index) override;

    void transform_model(matrix<double> transform);

    void transform(base_transformations *transform) override;

    void init_centre() override;
    point get_centre() override;
    void set_centre(point &center) override;

    point& get_vertex(size_t index) override;
    void set_vertex(size_t index, point vertex) override;
    line get_line(size_t index) override;
    
    void set_name(const char* name) override {this->_name = name;}
    const char* get_name() override {return this->_name;}
protected:
    double _get_max_x();
    double _get_max_y();
    double _get_max_z();

    double _get_min_x();
    double _get_min_y();
    double _get_min_z();
};

#endif // MODEL_H
