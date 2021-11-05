
#include "types.hh"

#ifndef UTILS_HH_INCL
#define UTILS_HH_INCL

namespace CPUSimulation
{

template <size_t HIGH, size_t LOW>
inline bitField_t getBits( bitField_t value )
{
    static_assert (HIGH < FIELDS_BITS_NUM);
    static_assert (HIGH >= LOW);

    return (value << (FIELDS_BITS_NUM - HIGH - 1)) >>
           (FIELDS_BITS_NUM - HIGH - 1 + LOW);
}

template <size_t SIGN_POS>
inline bitField_t signExtend( bitField_t value )
{
    static_assert (FIELDS_BITS_NUM > SIGN_POS);

    constexpr bitField_t MASK = 1U << (SIGN_POS);
    return (value ^ MASK) - MASK;
}

} // namespace CPUSimulation

#endif // #ifndef UTILS_HH_INCL
