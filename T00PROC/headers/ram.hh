
#include <vector>
#include <fstream>

#include "types.hh"
#include "utils.hh"

#ifndef RAM_HH_INCL
#define RAM_HH_INCL

namespace CPUSimulation
{

class Ram
{
    using data_t = char;

    std::vector<data_t> data_;

    static constexpr size_t MAX_RW_SIZE =
        sizeof (regValue_t) / sizeof (data_t);

public:
    Ram( size_t size ) : data_ (size, 0) {}

    size_t size() const
        { return data_.size (); }

    data_t* data()
        { return data_.data (); }

private:
    bool isValidRW( size_t addr, size_t size ) const
    {
        return addr + size <= data_.size () && size != 0 && size <= MAX_RW_SIZE;
    }

public:
    execStatus_t read( size_t addr, size_t size, regValue_t& dest ) const
    {
        if (!isValidRW (addr, size))
            return execStatus_t::SEGFAULT;

        dest = (dest << (size * 8)) >> (size * 8);

        for (size_t i = 0; i < size; ++i)
            dest |= static_cast<uint8_t> (data_[addr + size - 1 - i]) << (i * 8);

        return execStatus_t::OK;
    }

    execStatus_t write( size_t addr, size_t size, regValue_t src )
    {
        if (!isValidRW (addr, size))
            return execStatus_t::SEGFAULT;

        for (size_t i = 0; i < size; ++i)
            data_[addr + size - 1 - i] = static_cast<uint8_t> (src >> (i * 8));

        return execStatus_t::OK;
    }
};

} // namespace CPUSimulation

#endif // #ifndef RAM_HH_INCL
