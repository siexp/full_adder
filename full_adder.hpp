#pragma once

#include <stdexcept>
#include <limits>

int add(int rhs, int lhs)
{
    constexpr int negative_bit_mask = 1 << std::numeric_limits<int>::digits;

    const bool sum_is_negative = (rhs & negative_bit_mask) && (lhs & negative_bit_mask);
    const bool sum_is_positive = !(rhs & negative_bit_mask) && !(lhs & negative_bit_mask);

    while (lhs != 0)
    {
        // holds which bits are overflowed
        const int carry = rhs & lhs;

        // half-sum
        rhs = rhs ^ lhs;

        lhs = carry << 1;
    }

    const bool negative_oveflow = sum_is_negative && !(rhs & negative_bit_mask);
    const bool positive_oveflow = sum_is_positive && (rhs & negative_bit_mask);
    if( negative_oveflow || positive_oveflow )
    {
        throw std::runtime_error{"overflow"};
    }

    return rhs;
}