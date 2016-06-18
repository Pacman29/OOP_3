#include "model.h"
#include "QDebug"
model::model()
{
}

size_t model::vertex_count()
{
    return this->_vertex.length();
}

size_t model::line_count()
{
    return this->_line.length();
}

void model::add_vertex(const point &vertex)
{
    this->_vertex.push_back(vertex);
}

void model::add_line(size_t start_index, size_t end_index)
{
    if(start_index >= this->_vertex.length() ||
            end_index >= this->_vertex.length())
        throw model_error::index_error();

    this->_line.push_back(line(start_index,end_index));
}

void model::transform_model(matrix<double> transform)
{
    matrix<double> to_centre = transform_matrix::move(this->_centre.X(),this->_centre.Y(),this->_centre.Z());
    matrix<double> un_to_centre = transform_matrix::move(-this->_centre.X(),-this->_centre.Y(),-this->_centre.Z());
    transform = un_to_centre * transform * to_centre;

    for(size_t i = 0; i<this->_vertex.length(); ++i)
    {
        vector<double> vertex = this->_vertex[i].to_vector();
        vertex = vertex * transform;
        this->_vertex[i] = point(vertex);
    }
    vector<double> centre = this->_centre.to_vector() * transform;
    this->_centre = point(centre);

}

void model::transform(base_transformations *transform)
{
    if(transform->is_visible())
        for(size_t i = 0; i<this->_vertex.length(); ++i)
            this->_vertex[i].transform(transform);
}

void model::init_centre()
{
    double x_max = _get_max_x();
    double y_max = _get_max_y();
    double z_max = _get_max_z();

    double x_min = _get_min_x();
    double y_min = _get_min_y();
    double z_min = _get_min_z();

    this->_centre.set_X((x_max + x_min)/2.);
    this->_centre.set_Y((y_max + y_min)/2.);
    this->_centre.set_Z((z_max + z_min)/2.);
}

point model::get_centre()
{
    return this->_centre;
}

void model::set_centre(point& center)
{
    this->_centre = center;
}

point &model::get_vertex(size_t index)
{
    if(index >= this->_vertex.length())
        throw model_error::index_error();
    return this->_vertex[index];
}

void model::set_vertex(size_t index, point vertex)
{
    this->_vertex[index] = vertex;
}

line model::get_line(size_t index)
{
    if(index >= this->_line.length())
        throw model_error::index_error();
    return this->_line[index];
}

double model::_get_max_x()
{
    double tmp = 0;
    double max = this->_vertex[0].X();
    for(size_t i = 1; i<this->_vertex.length(); ++i)
    {
        tmp = this->_vertex[i].X();
        if(max < tmp)
            max = tmp;
    }
    return max;
}

double model::_get_max_y()
{
    double tmp = 0;
    double max = this->_vertex[0].Y();
    for(size_t i = 0; i<this->_vertex.length(); ++i)
    {
        tmp = this->_vertex[i].Y();
        if(max < tmp)
            max = tmp;
    }
    return max;
}

double model::_get_max_z()
{
    double tmp = 0;
    double max = this->_vertex[0].Z();
    for(size_t i = 0; i<this->_vertex.length(); ++i)
    {
        tmp = this->_vertex[i].Z();
        if(max < tmp)
            max = tmp;
    }
    return max;
}

double model::_get_min_x()
{
    double tmp = 0;
    double min = this->_vertex[0].X();
    for(size_t i = 0; i<this->_vertex.length(); ++i)
    {
        tmp = this->_vertex[i].X();
        if(min > tmp )
            min = tmp;
    }
    return min;
}

double model::_get_min_y()
{
    double tmp = 0;
    double min = this->_vertex[0].Y();
    for(size_t i = 0; i<this->_vertex.length(); ++i)
    {
        tmp = this->_vertex[i].Y();
        if(min > tmp )
            min = tmp;
    }
    return min;
}

double model::_get_min_z()
{
    double tmp = 0;
    double min = this->_vertex[0].Z();
    for(size_t i = 0; i<this->_vertex.length(); ++i)
    {
        tmp = this->_vertex[i].Z();
        if(min > tmp )
            min = tmp;
    }
    return min;
}
