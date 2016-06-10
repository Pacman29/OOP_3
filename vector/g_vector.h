#ifndef G_VECTOR_H
#define G_VECTOR_H
#include "vector/vector.h"
#include <cmath>

class G_vector : public vector<double>
{
public:
    G_vector();
    G_vector(double x,double y, double z);
    double calc_lenght();
    static double scalar(G_vector vec1, G_vector vec2);
    static double angle(G_vector  vec1, G_vector  vec2);
    G_vector normalize_vector();
    static G_vector cross(G_vector  vec1, G_vector vec2);

    G_vector& operator=  (vector<double>& other);
    G_vector& operator=  (vector<double> &&other);
};

#endif // G_VECTOR_H
