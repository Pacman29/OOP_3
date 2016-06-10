#ifndef LOADER_H
#define LOADER_H
#include "base_loader.h"
#include "loader_error.h"

class loader : public base_loader
{
public:
    loader();
    bool Load(model &Unit, const char *Name);
    ~loader();
    

private:
    // Check_Data
    void _Open_File(const char *Name);
    size_t _Check_Load_Count_Lines();
    size_t _Check_Load_Count_Points();

    // Get_Data
    point _Get_Point();
    void _Get_Line(size_t &start, size_t &end);

    // Load_Operation
    void _Load_Points(model &Unit, size_t count_points);
    void _Load_Lines(model &Unit, size_t count_line);
    void _Close_File(FILE* f);
};

#endif // LOADER_H
