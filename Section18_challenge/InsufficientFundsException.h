#ifndef _INSUFFICIENT_FUNDS_EXCEPTION
#define _INSUFFICIENT_FUNDS_EXCEPTION
#include <exception>

class InsufficientFundsException: public std::exception
{
public:
    InsufficientFundsException() noexcept = default;
    ~InsufficientFundsException() = default;
    virtual const char *what() const noexcept
    {
        return "Insuficcient funds exception";
    }
};

#endif
