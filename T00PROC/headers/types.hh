
#include <cstddef>
#include <cstdint>

#ifndef TYPES_HH_INCL
#define TYPES_HH_INCL

namespace CPUSimulation
{

using regValue_t = uint32_t;
using bitField_t = uint32_t;

constexpr size_t FIELDS_BITS_NUM = 32;

enum regId_t : char
{
    R00, R01, R02, R03, R04, R05, R06, R07,
    R08, R09, R0A, R0B, R0C, R0D, R0E, R0F,
    R10, R11, R12, R13, R14, R15, R16, R17,
    R18, R19, R1A, R1B, R1C, R1D, R1E, R1F
};

constexpr regId_t MAX_REG_ID = regId_t::R1F;

enum class loadStatus_t : char
{
    OK,

    CANT_OPEN_FILE,
    TO_BIG_FILE
};

enum class execStatus_t : char
{
    OK,

    UNKNOWN_INSTR,
    SEGFAULT
};

} // namespace CPUSimulation

#endif // #ifndef TYPES_HH_INCL
