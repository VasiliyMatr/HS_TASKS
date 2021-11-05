
#include "core.hh"

#ifndef EXEC_HH_INCL
#define EXEC_HH_INCL

namespace CPUSimulation
{

// beq
inline execStatus_t execF1( Core* core, const Core::Instruction* inst )
{
    if (core->getReg (inst->src1()) == core->getReg (inst->src2()))
        core->setNewPc (core->getPc() + ((inst->imm() >> 1) << 1));
    return execStatus_t::OK;
} 

// bne
inline execStatus_t execF2( Core* core, const Core::Instruction* inst )
{
    if (core->getReg (inst->src1()) != core->getReg (inst->src2()))
        core->setNewPc (core->getPc() + ((inst->imm() >> 1) << 1));
    return execStatus_t::OK;
}

// blt
inline execStatus_t execF3( Core* core, const Core::Instruction* inst )
{
    if (static_cast<int32_t> (core->getReg (inst->src1())) <
        static_cast<int32_t> (core->getReg (inst->src2())))
        core->setNewPc (core->getPc() + ((inst->imm() >> 1) << 1));
    return execStatus_t::OK;
}

// bge
inline execStatus_t execF4( Core* core, const Core::Instruction* inst )
{
    if (static_cast<int32_t> (core->getReg (inst->src1())) >=
        static_cast<int32_t> (core->getReg (inst->src2())))
        core->setNewPc (core->getPc() + ((inst->imm() >> 1) << 1));
    return execStatus_t::OK;
}

// bltu
inline execStatus_t execF5( Core* core, const Core::Instruction* inst )
{
    if (core->getReg (inst->src1()) < core->getReg (inst->src2()))
        core->setNewPc (core->getPc() + ((inst->imm() >> 1) << 1));
    return execStatus_t::OK;
}

// bgeu
inline execStatus_t execF6( Core* core, const Core::Instruction* inst )
{
    if (core->getReg (inst->src1()) >= core->getReg (inst->src2()))
        core->setNewPc (core->getPc() + ((inst->imm() >> 1) << 1));
    return execStatus_t::OK;
}

// jalr
inline execStatus_t execF7( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(), core->getPc() + 4);
    core->setNewPc (
        ((core->getReg (inst->src1()) + inst->imm()) >> 1) << 1);
    return execStatus_t::OK;
}

// jal
inline execStatus_t execF8( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(), core->getPc() + 4);
    core->setNewPc (core->getPc() + inst->imm());
    return execStatus_t::OK;
}

// lui
inline execStatus_t execF9( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(), inst->imm() << 12);
    return execStatus_t::OK;
}

// auipc
inline execStatus_t execF10( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(), core->getPc () + (inst->imm() << 12));
    return execStatus_t::OK;
}

// addi
inline execStatus_t execF11( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(), core->getReg (inst->src1()) + inst->imm());
    return execStatus_t::OK;
}

// slli
inline execStatus_t execF12( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(), core->getReg (inst->src1()) << inst->imm());
    return execStatus_t::OK;
}

// slti
inline execStatus_t execF13( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(),
        static_cast<int32_t> (core->getReg (inst->src1())) <
        static_cast<int32_t> (inst->imm()));
    return execStatus_t::OK;
}

// sltiu
inline execStatus_t execF14( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(), core->getReg (inst->src1()) < inst->imm());
    return execStatus_t::OK;
}

// xori
inline execStatus_t execF15( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(), core->getReg (inst->src1()) ^ inst->imm());
    return execStatus_t::OK;
}

// srli
inline execStatus_t execF16( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(), core->getReg (inst->src1()) >> inst->imm());
    return execStatus_t::OK;
}

// srai
inline execStatus_t execF17( Core* core, const Core::Instruction* inst )
{
    bitField_t mask = 1U << (FIELDS_BITS_NUM - inst->imm() - 1);

    core->setReg (inst->dest(),
        ((core->getReg (inst->src1()) >> inst->imm()) ^ mask) - mask);
    return execStatus_t::OK;
}

// ori
inline execStatus_t execF18( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(), core->getReg (inst->src1()) | inst->imm());
    return execStatus_t::OK;
}

// andi
inline execStatus_t execF19( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(), core->getReg (inst->src1()) & inst->imm());
    return execStatus_t::OK;
}

// add
inline execStatus_t execF20( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(),
        core->getReg (inst->src1()) + core->getReg (inst->src2()));
    return execStatus_t::OK;
}

// sll
inline execStatus_t execF21( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(),
        core->getReg (inst->src1()) << (inst->src2() & 0x1f));
    return execStatus_t::OK;
}

// slt
inline execStatus_t execF22( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(),
        static_cast<int32_t> (core->getReg (inst->src1())) <
        static_cast<int32_t> (core->getReg (inst->src2())));
    return execStatus_t::OK;
}

// sltu
inline execStatus_t execF23( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(),
        core->getReg (inst->src1()) < core->getReg (inst->src2()));
    return execStatus_t::OK;
}

// xor
inline execStatus_t execF24( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(),
        core->getReg (inst->src1()) ^ core->getReg (inst->src2()));
    return execStatus_t::OK;
}

// srl
inline execStatus_t execF25( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(),
        core->getReg (inst->src1()) >> (inst->src2() & 0x1f));
    return execStatus_t::OK;
}

// or
inline execStatus_t execF26( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(),
        core->getReg (inst->src1()) | core->getReg (inst->src2()));
    return execStatus_t::OK;
}

// and
inline execStatus_t execF27( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(),
        core->getReg (inst->src1()) & core->getReg (inst->src2()));
    return execStatus_t::OK;
}

// sub
inline execStatus_t execF28( Core* core, const Core::Instruction* inst )
{
    core->setReg (inst->dest(),
        core->getReg(inst->src1()) - core->getReg(inst->src2()));
    return execStatus_t::OK;
}

// sra
inline execStatus_t execF29( Core* core, const Core::Instruction* inst )
{
    bitField_t mask = 1U << (FIELDS_BITS_NUM - inst->imm() - 1);

    core->setReg (inst->dest(),
        ((core->getReg (inst->src1()) >> (core->getReg (inst->src2()) & 0x1f) ^ mask) -
        mask));
    return execStatus_t::OK;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

inline execStatus_t execF30( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF31( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF32( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF33( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF34( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF35( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF36( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF37( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF38( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF39( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF40( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF41( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF42( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF43( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF44( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF45( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF46( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF47( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF48( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF49( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF50( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF51( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF52( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF53( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF54( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF55( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF56( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF57( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF58( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF59( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF60( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF61( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF62( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF63( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF64( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF65( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF66( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF67( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF68( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF69( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF70( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF71( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF72( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF73( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF74( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF75( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF76( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF77( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF78( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF79( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF80( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF81( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF82( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF83( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF84( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF85( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF86( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF87( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF88( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF89( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF90( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF91( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF92( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF93( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF94( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF95( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF96( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF97( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF98( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF99( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF100( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF101( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF102( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF103( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF104( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF105( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF106( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF107( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF108( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF109( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF110( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF111( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF112( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF113( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF114( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF115( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF116( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF117( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF118( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF119( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF120( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF121( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF122( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF123( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF124( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF125( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF126( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF127( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF128( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF129( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF130( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF131( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF132( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF133( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF134( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF135( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF136( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF137( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF138( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF139( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF140( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF141( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF142( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF143( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF144( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF145( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF146( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF147( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF148( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF149( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF150( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF151( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF152( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF153( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF154( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF155( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF156( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF157( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF158( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF159( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF160( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF161( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF162( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF163( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF164( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF165( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF166( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF167( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF168( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF169( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF170( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF171( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF172( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF173( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF174( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF175( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF176( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF177( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF178( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF179( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF180( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF181( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF182( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF183( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF184( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF185( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF186( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF187( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF188( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF189( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF190( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF191( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF192( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF193( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF194( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF195( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF196( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF197( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

inline execStatus_t execF198( Core* core, const Core::Instruction* inst )
{
    return execStatus_t::UNKNOWN_INSTR;
}

#pragma GCC diagnostic pop

} // namespace CPUSimulation

#endif // #ifndef EXEC_HH_INCL
