
#include "types.hh"

#ifndef UTILS_HH_INCL
#define UTILS_HH_INCL

namespace CPUSimulation
{

template <size_t HIGH, size_t LOW>
bitField_t getBits( bitField_t code )
{
    static_assert (HIGH < CMD_BITS_NUM);
    static_assert (HIGH >= LOW);

    return (code << (CMD_BITS_NUM - HIGH)) >>
           (CMD_BITS_NUM - HIGH + LOW);
}

} // namespace CPUSimulation

#endif // #ifndef UTILS_HH_INCL
