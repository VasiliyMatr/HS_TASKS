
#include <vector>
#include <array>

#include "types.hh"
#include "utils.hh"
#include "ram.hh"

#ifndef CORE_HH_INCL
#define CORE_HH_INCL

namespace CPUSimulation
{

class Core
{
    struct Instruction
    {
        instCode_t code_;
        regId_t dest_;
        regId_t src1_;
        regId_t src2_;
        instClass_t iClass_;

    public:
        instCode_t code() const { return code_; }
        regId_t dest() const { return dest_; }
        regId_t src1_() const { return src1_; }
        regId_t src2_() const { return src2_; }
        instClass_t iClass() const { return iClass_; }

        Instruction (instCode_t code) :
            code_ (code),
            iClass_ (instClass_t {getBits<6, 0> (code)}),
            dest_ (regId_t {getBits<11, 7> (code)}),
            src1_ (regId_t {getBits<19, 15> (code)}),
            src2_ (regId_t {getBits<24, 20> (code)}) {}
    };

    regValue_t pc_ = 0;
    std::array<regValue_t, REGS_NUM> regs_ {0};

    static constexpr size_t RAM_SIZE = 4*1024*1024*1024;
    Ram ram_ {RAM_SIZE};

    // Loads binary to RAM - for further execution.
    loadStatus_t load( const char* binaryName );
    // Executes loaded binary.
    execStatus_t exec();
    // Executes fetched instruction.
    execStatus_t execInstr( const Instruction& );

private:
    execStatus_t execRType( const Instruction& );
    execStatus_t execIType( const Instruction& );
    execStatus_t execSType( const Instruction& );
    execStatus_t execBType( const Instruction& );
    execStatus_t execUType( const Instruction& );
    execStatus_t execJType( const Instruction& );
};

} // namespace CPUSimulation

#endif // #ifnder CORE_HH_INCL
