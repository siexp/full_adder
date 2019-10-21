#include "full_adder.hpp"

#include <iostream>
#include <limits>
#include <stdexcept>

void positive_plus_positive_no_overflow_test()
{
    std::cout << __FUNCTION__ << std::endl;

    if (add(5, 10) != 15)
    {
        throw std::logic_error{"5 + 10 != 15"};
    }
}

void positive_plus_negative_no_overflow_test()
{
    std::cout << __FUNCTION__ << std::endl;

    if (add(5, -10) != -5)
    {
        throw std::logic_error{"5 + (-10) != -5"};
    }
}

void negative_plus_positive_no_overflow_test()
{
    std::cout << __FUNCTION__ << std::endl;

    if (add(-5, 10) != 5)
    {
        throw std::logic_error{"(-5) + 10 != 5"};
    }
}

void negative_plus_negative_no_overflow_test()
{
    std::cout << __FUNCTION__ << std::endl;

    if (add(-5, -10) != -15)
    {
        throw std::logic_error{"(-5) + (-10) != -15"};
    }
}


void positive_plus_positive_overflow_test()
{
    std::cout << __FUNCTION__ << std::endl;

    try
    {
        add(5, std::numeric_limits< int >::max() );
        throw std::logic_error{"no overflow 5 + std::numeric_limits< int >::max()"};
    }
    catch(const std::runtime_error&)
    {
        // expected exception
    }
}


void negative_plus_negative_overflow_test()
{
    std::cout << __FUNCTION__ << std::endl;

    try
    {
        add(-5, std::numeric_limits< int >::min() );
        throw std::logic_error{"no overflow (-5) + std::numeric_limits< int >::min()"};
    }
    catch(const std::runtime_error&)
    {
        // expected exception
    }
}

int main()
{
    try
    {
        positive_plus_positive_no_overflow_test();
        positive_plus_negative_no_overflow_test();
        negative_plus_positive_no_overflow_test();
        negative_plus_negative_no_overflow_test();

        positive_plus_positive_overflow_test();
        negative_plus_negative_overflow_test();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}