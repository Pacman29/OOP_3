#ifndef LINE_H
#define LINE_H
#include "object/visible_object.h"
#include "point/_point.h"
#include "line_error.h"
#include "base_line.h"
#include <cstddef>

class line : public base_line
{
public:
    line();
    line(const line& other);
    line(line &&other);
    line(size_t start,size_t end);

    line& operator=  (const line& other);
    line& operator=  (line &&other);

    size_t start() override;
    size_t end() override;

    void set_start(size_t start) override;
    void set_end(size_t  end) override;

    void swap();
    void transform(base_transformations *transform) {}

};
#endif // _LINE_H
