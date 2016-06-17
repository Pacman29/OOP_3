#ifndef LOADER_H
#define LOADER_H
#include "base_loader.h"
#include "loader_error.h"
class file_loaderImpl : public base_loaderImpl
{
public:
    bool Load(base_model &Unit, const char *Name);
private:
    void _Open_File(FILE*& FileLoader, const char *Name);
    size_t _Check_Load_Count_Lines(FILE*& FileLoader);
    size_t _Check_Load_Count_Points(FILE*& FileLoader);

    // Get_Data
    point _Get_Point(FILE*& FileLoader);
    void _Get_Line(FILE*& FileLoader, size_t &start, size_t &end);

    // Load_Operation
    void _Load_Points(FILE*& FileLoader, base_model &Unit, size_t count_points);
    void _Load_Lines(FILE*& FileLoader, base_model &Unit, size_t count_line);
    void _Close_File(FILE*& f);
};

class file_loader : public base_loader
{
public:
    file_loader() : base_loader(new file_loaderImpl){}
    bool Load(base_model &Unit, const char *Name)
    {
        return this->ldImpl->Load(Unit,Name);
    }
};

#endif // LOADER_H
