#pragma once

int add(int rhs, int lhs)
{
    while (lhs != 0)
    {
        // holds which bits are overflowed
        const int carry = rhs & lhs;

        // half-sum
        rhs = rhs ^ lhs;
        
        lhs = carry << 1;
    }

    return rhs;
}