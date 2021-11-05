
#include <fstream>

#include "core.hh"

namespace CPUSimulation
{

loadStatus_t Core::load( const char* binaryName )
{
    std::ifstream binary (binaryName, std::ios::binary);

    binary.seekg (0, std::ios_base::end);
    size_t binarySize = binary.tellg ();
    binary.seekg (0, std::ios_base::beg);

    if (binarySize > ram_.size ())
        return loadStatus_t::TO_BIG_FILE;

    binary.read (ram_.data (), binarySize);

    pc_ = 0;
    codeSize_ = binarySize;

    return loadStatus_t::OK;
}

execStatus_t Core::exec()
{
    while (true)
    {
        if (pc_ >= codeSize_)
            return execStatus_t::OK;

        // Fetch
        bitField_t instCode = 0;
        execStatus_t fetchStatus = ram_.read (pc_, sizeof (bitField_t), instCode);
        if (fetchStatus != execStatus_t::OK)
            return fetchStatus;

        // Decode
        Instruction instr  = Instruction::decode (instCode);

        // Execution
        newPc_ = pc_ + 4;
        execStatus_t execStatus = instr.exec (this);
        if (execStatus != execStatus_t::OK)
            return execStatus;
        pc_ = newPc_;

        // No separate memory & WB stages for now.
    }
}

} // namespace CPUSimulation