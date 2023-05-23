// Simple Account 
#ifndef _I_PRINT_H_
#define _I_PRINT_H_
#include <iostream>

class I_Print
{
    friend std::ostream &operator<<(std::ostream &os, const I_Print &obj);
public:
    virtual void print(std::ostream &os) const = 0; //pure virtual f-n
    virtual ~I_Print(){};
};
#endif
