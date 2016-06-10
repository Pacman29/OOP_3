#ifndef POINT_TRANSFORM_H
#define POINT_TRANSFORM_H
#include "transformations/transformations.h"
#include "point/_point.h"
#include "geometric_transformations/geometric_transformations.h"
class point_transform : public base_transformations
{
public:
    virtual void change_point(point* const p) = 0;
};


class change : public point_transform
{
private:

    matrix<double> tr;

public:
    change(matrix<double> transform) : tr(transform){}
    void change_point(point* const p) override;
};


#endif // POINT_TRANSFORM_H
