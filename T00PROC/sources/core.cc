
#include <fstream>

#include "core.hh"

namespace CPUSimulation
{

loadStatus_t Core::load( const char* binaryName )
{
    std::ifstream binary (binaryName, std::ios::binary);

    binary.seekg (0, std::ios_base::seekdir::_S_end);
    size_t binarySize = binary.tellg ();
    binary.seekg (0, std::ios_base::seekdir::_S_beg);

    if (binarySize > ram_.size ())
        return loadStatus_t::TO_BIG_FILE;

    binary.read (ram_.data (), binarySize);
}

execStatus_t Core::exec()
{
    while (true)
    {
        // Fetch
        instCode_t instCode = 0;
        execStatus_t fetchStatus = ram_.read (pc_, sizeof (instCode_t), instCode);
        if (fetchStatus != execStatus_t::OK)
            return fetchStatus;

        // Partial decode
        Instruction instr {instCode};

        // Execution
        execStatus_t execStatus = execInstr (instr);
        if (execStatus != execStatus_t::OK)
            return execStatus;

        // No separate memory & WB stages for now.
    }
}

execStatus_t Core::execInstr( const Instruction& instr )
{
    switch (instr.iClass ())
    {
        case R: return execRType (instr);
        case I: return execIType (instr);
        case S: return execSType (instr);
        case B: return execBType (instr);
        case U: return execUType (instr);
        case J: return execJType (instr);

        default: return execStatus_t::UNKNOWN_INSTR;
    }
}

execStatus_t Core::execRType( const Instruction& instr )
{
    return execStatus_t::UNKNOWN_INSTR;
}

execStatus_t Core::execIType( const Instruction& instr )
{
    return execStatus_t::UNKNOWN_INSTR;
}

execStatus_t Core::execSType( const Instruction& instr )
{
    return execStatus_t::UNKNOWN_INSTR;
}

execStatus_t Core::execBType( const Instruction& instr )
{
    return execStatus_t::UNKNOWN_INSTR;
}

execStatus_t Core::execUType( const Instruction& instr )
{
    return execStatus_t::UNKNOWN_INSTR;
}

execStatus_t Core::execJType( const Instruction& instr )
{
    return execStatus_t::UNKNOWN_INSTR;
}

} // namespace CPUSimulation