#ifndef __Assistant_H
#define __Assistant_H
#include"Student.h"
#include"Teacher.h"
class Assistant:public Student, public Teacher 
{
public:
    Assistant();
    Assistant(char* , int , double );
    Assistant(const Assistant& );
    Assistant& operator=(const Assistant& );
    ~Assistant();



};


#endif