#include "line.h"

line::line()
{
    this->_start = NULL;
    this->_end = NULL;
}

line::line(const line &other)
{
    this->_start = other._start;
    this->_end = other._end;
}

line::line(line &&other)
{
    this->_start = other._start;
    this->_end = other._end;
}

line::line(size_t start,size_t end)
{
    this->_start = start;
    this->_end = end;
}

line& line::operator=(const line &other)
{
    this->_start = other._start;
    this->_end = other._end;
    return *this;
}

line& line::operator=  (line &&other)
{
    this->_start = other._start;
    this->_end = other._end;
    return *this;
}

size_t line::start()
{
    return this->_start;
}


size_t line::end()
{
    return this->_end;
}


void line::set_start(size_t start)
{
    this->_start = start;
}

void line::set_end(size_t end)
{
    this->_end = end;
}


void line::swap()
{
    size_t  tmp = this->_start;
    this->_start = this->_end;
    this->_end = tmp;
}

