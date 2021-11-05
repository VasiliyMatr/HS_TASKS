
#include <vector>
#include <array>
#include <functional>
#include <iostream>
#include <iomanip>

#include "types.hh"
#include "utils.hh"
#include "ram.hh"
#include "reg.hh"

#ifndef CORE_HH_INCL
#define CORE_HH_INCL

namespace CPUSimulation
{

struct Core
{
    struct Instruction
    {
        using ExecFunc = std::function<execStatus_t ( Core*, const Instruction* )>;

    private:
        regId_t dest_ = regId_t::R00;
        regId_t src1_ = regId_t::R00;
        regId_t src2_ = regId_t::R00;
        bitField_t imm_ = 0;

        ExecFunc execFunc_ = nullptr;

    public:
        regId_t dest() const { return dest_; }
        regId_t src1() const { return src1_; }
        regId_t src2() const { return src2_; }
        bitField_t imm() const { return imm_; }

        static Instruction decode( bitField_t );

        execStatus_t exec( Core* controlledCore ) const
        {
            if (execFunc_ == nullptr)
                return execStatus_t::UNKNOWN_INSTR;
            return execFunc_ (controlledCore, this);
        }
    };

private:
    static constexpr size_t RAM_SIZE = static_cast<size_t> (4)*1024*1024*1024;

    regValue_t pc_ = 0;
    regValue_t newPc_ = 0;
    RegFile regFile_ {};
    Ram ram_ {RAM_SIZE};

    // loaded code size - to stop execution.
    size_t codeSize_ = 0;

public:
    // Loads binary to RAM - for further execution.
    loadStatus_t load( const char* binaryName );
    // Executes loaded binary.
    execStatus_t exec();

    void dumpState() const
    {
        std::cout << "Proc state dump:" << std::endl;
        std::cout << "    pc = " << pc_ << std::endl;
        std::cout << std::hex;
        for (int i = 0; i <= MAX_REG_ID; ++i)
        {
            std::cout <<
                "    R" << std::setfill('0') << std::setw(2) << i << " = " <<
                regFile_.get (static_cast<regId_t> (i)) << std::endl;
        }
    }

    void setNewPc( regValue_t value ) { newPc_ = value; }
    regValue_t getPc() const { return pc_; }

    void setReg( regId_t regId, regValue_t value )
        { regFile_.set (regId, value); }
    regValue_t getReg( regId_t regId ) const
        { return regFile_.get (regId); }

    execStatus_t rdMem( size_t addr, size_t size, regValue_t &dest )
        { return ram_.read (addr, size, dest); }
    execStatus_t wrMem( size_t addr, size_t size, regValue_t value )
        { return ram_.write (addr, size, value); }
};

} // namespace CPUSimulation

#endif // #ifnder CORE_HH_INCL
