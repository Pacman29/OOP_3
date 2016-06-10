#include "g_vector.h"

G_vector::G_vector()
{
    this->resize(4);
    (*this)[3] = 1;
}

G_vector::G_vector(double x, double y, double z)
{
    this->resize(4);
    (*this)[0] = x;
    (*this)[1] = y;
    (*this)[2] = z;
    (*this)[3] = 1;
}

double G_vector::calc_lenght()
{
    if((*this).length() != 4)
        throw vector_error::length_error();
    double x = (*this)[0];
    double y = (*this)[1];
    double z = (*this)[2];
    return sqrt(x*x + y*y + z*z);
}

double G_vector::scalar(G_vector vec1, G_vector vec2)
{
    if(vec1.length() != 4 || vec2.length() != 4)
        throw vector_error::length_error();

    return vec1[0]*vec2[0] + vec1[1]*vec2[1] + vec1[2]*vec2[2];
}

double G_vector::angle(G_vector vec1, G_vector vec2)
{
    if(vec1.length() != 4 || vec2.length() != 4)
        throw vector_error::length_error();
    return scalar(vec1,vec2) / (vec1.calc_lenght() * vec2.calc_lenght());
}

G_vector G_vector::normalize_vector()
{
    if((*this).length() != 4)
        throw vector_error::length_error();
    double norm = 1/(*this).calc_lenght();
    for(size_t i = 0; i<(*this).length()-1; ++i)
       (*this)[i] *= norm;
    return (*this);
}

G_vector G_vector::cross(G_vector vec1, G_vector vec2)
{
    if(vec1.length() != 4 || vec2.length() != 4)
        throw vector_error::length_error();

    G_vector tmp;
    tmp[0] = vec1[2]*vec2[1] - vec1[1]*vec2[2];
    tmp[1] = vec1[0]*vec2[2] - vec1[2]*vec2[0];
    tmp[2] = vec1[1]*vec2[0] - vec1[0]*vec2[1];
    tmp[3] = 1;
    return tmp;
}

G_vector &G_vector::operator=(vector<double> &other)
{
    if(other.length() != 4)
        throw vector_error::length_error();
    for(size_t i = 0; i<4; ++i)
        (*this)[i] = other[i];
    return (*this);
}

G_vector &G_vector::operator=(vector<double> &&other)
{
    if(other.length() != 4)
        throw vector_error::length_error();
    for(size_t i = 0; i<4; ++i)
        (*this)[i] = other[i];
    return (*this);
}

