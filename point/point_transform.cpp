#include "point_transform.h"

void change::change_point(point * const p)
{
    vector<double> vec = p->to_vector() * tr;
    p->set_X(vec[0]);
    p->set_Y(vec[1]);
    p->set_Z(vec[2]);
}

