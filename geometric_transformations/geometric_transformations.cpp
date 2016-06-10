#include "geometric_transformations.h"
#include "QDebug"

transform_matrix::rotationOX::rotationOX(double angle)
{
    this->set_row_count(4);
    this->set_column_count(4);

    double cos_alpha = cos(angle);
    double sin_alpha = sin(angle);

    (*this)[0][0] = 1;
    (*this)[1][0] = 0;
    (*this)[2][0] = 0;
    (*this)[3][0] = 0;

    (*this)[0][1] = 0;
    (*this)[1][1] = cos_alpha;
    (*this)[2][1] = -sin_alpha;
    (*this)[3][1] = 0;

    (*this)[0][2] = 0;
    (*this)[1][2] = sin_alpha;
    (*this)[2][2] = cos_alpha;
    (*this)[3][2] = 0;

    (*this)[0][3] = 0;
    (*this)[1][3] = 0;
    (*this)[2][3] = 0;
    (*this)[3][3] = 1;
}

transform_matrix::rotationOY::rotationOY(double angle)
{
    this->set_row_count(4);
    this->set_column_count(4);

    double cos_alpha = cos(angle);
    double sin_alpha = sin(angle);

    (*this)[0][0] = cos_alpha;
    (*this)[1][0] = 0;
    (*this)[2][0] = sin_alpha;
    (*this)[3][0] = 0;

    (*this)[0][1] = 0;
    (*this)[1][1] = 1;
    (*this)[2][1] = 0;
    (*this)[3][1] = 0;

    (*this)[0][2] = -sin_alpha;
    (*this)[1][2] = 0;
    (*this)[2][2] = cos_alpha;
    (*this)[3][2] = 0;

    (*this)[0][3] = 0;
    (*this)[1][3] = 0;
    (*this)[2][3] = 0;
    (*this)[3][3] = 1;
}

transform_matrix::rotationOZ::rotationOZ(double angle)
{
    this->set_row_count(4);
    this->set_column_count(4);

    double cos_alpha = cos(angle);
    double sin_alpha = sin(angle);

    (*this)[0][0] = cos_alpha;
    (*this)[1][0] = -sin_alpha;
    (*this)[2][0] = 0;
    (*this)[3][0] = 0;

    (*this)[0][1] = sin_alpha;
    (*this)[1][1] = cos_alpha;
    (*this)[2][1] = 0;
    (*this)[3][1] = 0;

    (*this)[0][2] = 0;
    (*this)[1][2] = 0;
    (*this)[2][2] = 1;
    (*this)[3][2] = 0;

    (*this)[0][3] = 0;
    (*this)[1][3] = 0;
    (*this)[2][3] = 0;
    (*this)[3][3] = 1;
}

transform_matrix::rotation::rotation(double x, double y, double z, double angle)
{
    this->set_row_count(4);
    this->set_column_count(4);

    double cos_alpha = cos(angle);
    double sin_alpha = sin(angle);

    (*this)[0][0] = cos_alpha + (1-cos_alpha)*x*x;
    (*this)[1][0] = (1-cos_alpha)*x*y - sin_alpha*z;
    (*this)[2][0] = (1-cos_alpha)*x*z + sin_alpha*y;
    (*this)[3][0] = 0;

    (*this)[0][1] = (1-cos_alpha)*y*x + sin_alpha*z;
    (*this)[1][1] = cos_alpha + (1-cos_alpha)*y*y;
    (*this)[2][1] = (1-cos_alpha)*y*z - sin_alpha*x;
    (*this)[3][1] = 0;

    (*this)[0][2] = (1-cos_alpha)*z*x - sin_alpha*y;
    (*this)[1][2] = (1-cos_alpha)*z*y + sin_alpha*x;
    (*this)[2][2] = cos_alpha + (1-cos_alpha)*z*z;
    (*this)[3][2] = 0;

    (*this)[0][3] = 0;
    (*this)[1][3] = 0;
    (*this)[2][3] = 0;
    (*this)[3][3] = 1;
}

transform_matrix::move::move(double x, double y, double z)
{
    this->set_row_count(4);
    this->set_column_count(4);

    (*this)[0][0] = 1;
    (*this)[0][1] = 0;
    (*this)[0][2] = 0;
    (*this)[0][3] = 0;

    (*this)[1][0] = 0;
    (*this)[1][1] = 1;
    (*this)[1][2] = 0;
    (*this)[1][3] = 0;

    (*this)[2][0] = 0;
    (*this)[2][1] = 0;
    (*this)[2][2] = 1;
    (*this)[2][3] = 0;

    (*this)[3][0] = x;
    (*this)[3][1] = y;
    (*this)[3][2] = z;
    (*this)[3][3] = 1;
}


transform_matrix::scale::scale(double s)
{
    this->set_row_count(4);
    this->set_column_count(4);

    (*this)[0][0] = s;
    (*this)[1][0] = 0;
    (*this)[2][0] = 0;
    (*this)[3][0] = 0;

    (*this)[0][1] = 0;
    (*this)[1][1] = s;
    (*this)[2][1] = 0;
    (*this)[3][1] = 0;

    (*this)[0][2] = 0;
    (*this)[1][2] = 0;
    (*this)[2][2] = s;
    (*this)[3][2] = 0;

    (*this)[0][3] = 0;
    (*this)[1][3] = 0;
    (*this)[2][3] = 0;
    (*this)[3][3] = 1;
}

//double G_vector::calc_lenght(vector<double> vec)
//{
//    if(vec.length() != 4)
//        throw vector_error::length_error();
//    double x = vec[0];
//    double y = vec[1];
//    double z = vec[2];
//    return sqrt(x*x + y*y + z*z);
//}

//double G_vector::scalar(vector<double>  vec1, vector<double>  vec2)
//{
//    if(vec1.length() != 4 || vec2.length() != 4)
//        throw vector_error::length_error();

//    return vec1[0]*vec2[0] + vec1[1]*vec2[1] + vec1[2]*vec2[2];
//}

//double G_vector::angle(vector<double> vec1, vector<double> vec2)
//{
//    if(vec1.length() != 4 || vec2.length() != 4)
//        throw vector_error::length_error();
//    return scalar(vec1,vec2) / (calc_lenght(vec1) * calc_lenght(vec1));
//}

//vector<double> G_vector::normalize_vector(vector<double> vec)
//{
//    if(vec.length() != 4)
//        throw vector_error::length_error();
//    double norm = 1/calc_lenght(vec);
//    for(size_t i = 0; i<vec.length()-1; ++i)
//        vec[i] *= norm;
//    return vec;
//}

//vector<double> G_vector::cross(vector<double> vec1, vector<double> vec2)
//{
//    if(vec1.length() != 4 || vec2.length() != 4)
//        throw vector_error::length_error();

//    vector<double> tmp(4);
//    tmp[0] = vec1[2]*vec2[1] - vec1[1]*vec2[2];
//    tmp[1] = vec1[0]*vec2[2] - vec1[2]*vec2[0];
//    tmp[2] = vec1[1]*vec2[0] - vec1[0]*vec2[1];
//    tmp[3] = 1;
//    return tmp;
//}


