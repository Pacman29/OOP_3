#include "loader.h"

loader::loader()
{
    this->FileLoader = NULL;
}

bool loader::Load(model &Unit, const char *Name)
{
    try
    {
        _Open_File(Name);
        size_t point_count = _Check_Load_Count_Points();
        _Load_Points(Unit,point_count);

        Unit.init_centre();
    
        size_t line_count = _Check_Load_Count_Lines();
        _Load_Lines(Unit,line_count);

        Unit.set_name(Name);
        _Close_File(this->FileLoader);
    }
    catch(base_error& er)
    {
        return false;
    }
    return true;
}

loader::~loader()
{
    _Close_File(this->FileLoader);
}


void loader::_Open_File(const char *Name)
{
    FILE* f = NULL;
    if(! (f = fopen(Name,"r")))
        throw loader_error::open_error();
    this->FileLoader = f;
}

size_t loader::_Check_Load_Count_Lines()
{
    size_t count;
    if( fscanf(this->FileLoader,"%u",&count) != 1)
        throw loader_error::file_error();
    return count;
}

size_t loader::_Check_Load_Count_Points()
{
    size_t count;
    if( fscanf(this->FileLoader,"%u",&count) != 1)
        throw loader_error::file_error();
    return count;
}

point loader::_Get_Point()
{
    double x,y,z;
    if(feof(this->FileLoader))
        throw loader_error::file_error();
    if( fscanf(this->FileLoader,"%lf %lf %lf",&x,&y,&z) != 3)
        throw loader_error::file_error();
    return point(x,y,z);
}

void loader::_Get_Line(size_t &start, size_t &end)
{
    if(feof(this->FileLoader))
        throw loader_error::file_error();
    if( fscanf(this->FileLoader,"%u %u",&start,&end) != 2)
        throw loader_error::file_error();
}

void loader::_Load_Points(model &Unit, size_t count_points)
{
    for(size_t i = 0; i<count_points; ++i)
        Unit.add_vertex(_Get_Point());
}

void loader::_Load_Lines(model &Unit, size_t count_line)
{
    for(size_t i = 0; i<count_line; ++i)
    {
        size_t start = 0, end = 0;
        _Get_Line(start,end);
        Unit.add_line(start,end);
    }
}

void loader::_Close_File(FILE *f)
{
    fclose(f);
}

