#ifndef __SURFANDTURF_H
#define __SURFANDTURF_H
#include"SeafoodDish.h"
#include"MeatDish.h"
class SurfAndTurf: public MeatDish, public SeafoodDish
{
public:
    SurfAndTurf();
    SurfAndTurf(size_t , char** , double , char* , char* );
    SurfAndTurf(const SurfAndTurf& );
    SurfAndTurf& operator=(const SurfAndTurf& );
    ~SurfAndTurf();

    void print();
};

#endif