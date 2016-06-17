#include "loader.h"


bool file_loaderImpl::Load(base_model &Unit, const char *Name)
{
    try
    {
        FILE* tmp = NULL;
        _Open_File(tmp, Name);
        size_t point_count = _Check_Load_Count_Points(tmp);
        _Load_Points(tmp, Unit,point_count);

        Unit.init_centre();
    
        size_t line_count = _Check_Load_Count_Lines(tmp);
        _Load_Lines(tmp, Unit,line_count);

        Unit.set_name(Name);
        _Close_File(tmp);
    }
    catch(base_error& er)
    {
        return false;
    }
    return true;
}


void file_loaderImpl::_Open_File(FILE*& FileLoader, const char *Name)
{
    if(! (FileLoader = fopen(Name,"r")))
        throw loader_error::open_error();
}

size_t file_loaderImpl::_Check_Load_Count_Lines(FILE*& FileLoader)
{
    size_t count;
    if( fscanf(FileLoader,"%u",&count) != 1)
        throw loader_error::file_error();
    return count;
}

size_t file_loaderImpl::_Check_Load_Count_Points(FILE*& FileLoader)
{
    size_t count;
    if( fscanf(FileLoader,"%u",&count) != 1)
        throw loader_error::file_error();
    return count;
}

point file_loaderImpl::_Get_Point(FILE*& FileLoader)
{
    double x,y,z;
    if(feof(FileLoader))
        throw loader_error::file_error();
    if( fscanf(FileLoader,"%lf %lf %lf",&x,&y,&z) != 3)
        throw loader_error::file_error();
    return point(x,y,z);
}

void file_loaderImpl::_Get_Line(FILE*& FileLoader, size_t &start, size_t &end)
{
    if(feof(FileLoader))
        throw loader_error::file_error();
    if( fscanf(FileLoader,"%u %u",&start,&end) != 2)
        throw loader_error::file_error();
}

void file_loaderImpl::_Load_Points(FILE*& FileLoader, base_model &Unit, size_t count_points)
{
    for(size_t i = 0; i<count_points; ++i)
        Unit.add_vertex(_Get_Point(FileLoader));
}

void file_loaderImpl::_Load_Lines(FILE*& FileLoader, base_model &Unit, size_t count_line)
{
    for(size_t i = 0; i<count_line; ++i)
    {
        size_t start = 0, end = 0;
        _Get_Line(FileLoader,start,end);
        Unit.add_line(start,end);
    }
}

void file_loaderImpl::_Close_File(FILE*& f)
{
    fclose(f);
}

