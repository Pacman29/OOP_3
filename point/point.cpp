#include "_point.h"
#include "point_transform.cpp"
point::point()
{
    this->_x = this->_y = this->_z = 0;
}

point::point(double &x, double &y, double &z)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
}


point::point(vector<double> &vec)
{
    if(vec.length() != 4)
        throw point_error::vector_error();

    this->_x = vec[0];
    this->_y = vec[1];
    this->_z = vec[2];
}

point::point(const point &pnt)
{
    this->_x = pnt._x;
    this->_y = pnt._y;
    this->_z = pnt._z;
}

point::point(point &&pnt)
{
    this->_x = pnt._x;
    this->_y = pnt._y;
    this->_z = pnt._z;
}

point &point::operator=(const point &pnt)
{
    this->_x = pnt._x;
    this->_y = pnt._y;
    this->_z = pnt._z;
    return *this;
}

point &point::operator=(point &&pnt)
{
    this->_x = pnt._x;
    this->_y = pnt._y;
    this->_z = pnt._z;
    return *this;
}

point point::operator-(const point &pnt) const
{
    point res(*this);
    res._x -= pnt._x;
    res._y -= pnt._y;
    res._z -= pnt._z;
    return res;
}

bool point::operator==(const point &pnt) const
{
    if(this->_x != pnt._x)
        return false;
    if(this->_y != pnt._y)
        return false;
    if(this->_z != pnt._z)
        return false;
    return true;
}

bool point::operator!=(const point &pnt) const
{
    return !(*this == pnt);
}

void point::set_X(const double &x)
{
    this->_x = x;
}

void point::set_Y(const double &y)
{
    this->_y = y;
}

void point::set_Z(const double &z)
{
    this->_z = z;
}

void point::transform(base_transformations *transform)
{
    ((point_transform*)transform)->change_point(this);
}


vector<double> point::to_vector()
{
    vector<double> vec(4);
    vec[0] = this->_x;
    vec[1] = this->_y;
    vec[2] = this->_z;
    vec[3] = 1;
    return vec;
}

double point::X()
{
    return _x;
}

double point::Y()
{
    return _y;
}

double point::Z()
{
    return _z;
}
