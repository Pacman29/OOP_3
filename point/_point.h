#ifndef _point_h
#define _point_h
#include "vector/vector.h"
#include "error_point.h"
#include "object/visible_object.h"
//#include "transformations/transformations.h"

class base_transformations;

class point : public visible_object
{
public:
    point();
    point(double &x, double &y, double &z);
    point(vector<double>& vec);
    point(const point& pnt);
    point(point&& pnt);

    point& operator= (const point& pnt);
    point& operator= (point&& pnt);
    point  operator- (const point& pnt) const;

    bool operator== (const point& pnt) const;
    bool operator!= (const point& pnt) const;

    void set_X(const double &x);
    void set_Y(const double &y);
    void set_Z(const double &z);

    void transform(base_transformations *transform) override;

    vector<double> to_vector();

    double X();
    double Y();
    double Z();

    bool is_display() override{return true;}
    bool add(base_object *) override{return false;}

private:
    double _x;
    double _y;
    double _z;
};

#endif
