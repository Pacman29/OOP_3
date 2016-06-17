#include "geometric_transformations.h"
#include "QDebug"

transform_matrix::rotationOX::rotationOX(double angle) :
    matrix<double>(4,4)
{
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

transform_matrix::rotationOY::rotationOY(double angle) :
    matrix<double>(4,4)
{
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

transform_matrix::rotationOZ::rotationOZ(double angle) :
    matrix<double>(4,4)
{
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

transform_matrix::rotation::rotation(double x, double y, double z, double angle) :
    matrix<double>(4,4)
{
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

transform_matrix::move::move(double x, double y, double z) :
    matrix<double>(4,4)
{
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


transform_matrix::scale::scale(double s) :
    matrix<double>(4,4)
{
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
