
#include <array>
#include <cassert>
#include "types.hh"

#ifndef REG_HH_INCL
#define REG_HH_INCL

namespace CPUSimulation
{

class RegFile
{
    std::array<regValue_t, MAX_REG_ID + 1> regs_ {0};

public:
    regValue_t get( regId_t regId ) const
    {
        assert (MAX_REG_ID >= regId);
        if (regId == regId_t::R00)
            return 0;

        return regs_[regId];
    }

    void set( regId_t regId, regValue_t value )
    {
        assert (MAX_REG_ID >= regId);

        regs_[regId] = value;
    }
};

} // namespace CPUSimulation

#endif // #ifndef REG_HH_INCL
