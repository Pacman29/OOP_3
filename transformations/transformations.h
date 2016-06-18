#ifndef TRANSFORMATIONS
#define TRANSFORMATIONS
class base_transformations
{
public:
    virtual ~base_transformations(){}
    virtual bool is_visible() = 0;
};

class invisible_transformations : public base_transformations
{
public:
    virtual ~invisible_transformations(){}
    bool is_visible() override
    {
        return false;
    }
};

class visible_transformations : public base_transformations
{
public:
    virtual ~visible_transformations(){}
    bool is_visible() override
    {
        return true;
    }
};

#endif // TRANSFORMATIONS

