#ifndef GEOMERTIC_TRANSFORMATIONS_H
#define GEOMERTIC_TRANSFORMATIONS_H
#include "matrix/matrix.h"
#include "point/point.h"
#include <cmath>
namespace transform_matrix {

class rotationOX : public matrix<double>
{
public:
    rotationOX(double angle);
};

class rotationOY : public matrix<double>
{
public:
    rotationOY(double angle);
};

class rotationOZ : public matrix<double>
{
public:
    rotationOZ(double angle);
};

class rotation : public matrix<double>
{
public:
    rotation(double x,double y,double z,double angle);
};

class move: public matrix<double>
{
public:
    move(double x,double y,double z);
};

class moveOX: public move
{
public:
    moveOX(double x) : move(x,0,0){}
};

class moveOY: public move
{
public:
    moveOY(double y) : move(0,y,0){}
};

class moveOZ: public move
{
public:
    moveOZ(double z) : move(0,0,z){}
};

class scale: public matrix<double>
{
public:
    scale(double s);
};
}


#endif // geometric_transformations_H
