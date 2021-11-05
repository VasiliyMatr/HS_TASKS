
#include "core.hh"
#include "exec.hh"

namespace CPUSimulation {

Core::Instruction Core::Instruction::decode(bitField_t code) {
  Instruction inst{};
  inst.dest_ = static_cast<regId_t>(getBits<11, 7>(code));
  inst.src1_ = static_cast<regId_t>(getBits<19, 15>(code));
  inst.src2_ = static_cast<regId_t>(getBits<24, 20>(code));
  switch (getBits<6, 0>(code)) {
  case 99:
    switch (getBits<14, 12>(code)) {
    case 0:
      inst.imm_ = signExtend<12>(
          (getBits<31, 31>(code) << 12) + (getBits<30, 25>(code) << 5) +
          (getBits<11, 8>(code) << 1) + (getBits<7, 7>(code) << 11) + 0);
      inst.execFunc_ = execF1;
      return inst;
    case 1:
      inst.imm_ = signExtend<12>(
          (getBits<31, 31>(code) << 12) + (getBits<30, 25>(code) << 5) +
          (getBits<11, 8>(code) << 1) + (getBits<7, 7>(code) << 11) + 0);
      inst.execFunc_ = execF2;
      return inst;
    case 4:
      inst.imm_ = signExtend<12>(
          (getBits<31, 31>(code) << 12) + (getBits<30, 25>(code) << 5) +
          (getBits<11, 8>(code) << 1) + (getBits<7, 7>(code) << 11) + 0);
      inst.execFunc_ = execF3;
      return inst;
    case 5:
      inst.imm_ = signExtend<12>(
          (getBits<31, 31>(code) << 12) + (getBits<30, 25>(code) << 5) +
          (getBits<11, 8>(code) << 1) + (getBits<7, 7>(code) << 11) + 0);
      inst.execFunc_ = execF4;
      return inst;
    case 6:
      inst.imm_ = signExtend<12>(
          (getBits<31, 31>(code) << 12) + (getBits<30, 25>(code) << 5) +
          (getBits<11, 8>(code) << 1) + (getBits<7, 7>(code) << 11) + 0);
      inst.execFunc_ = execF5;
      return inst;
    case 7:
      inst.imm_ = signExtend<12>(
          (getBits<31, 31>(code) << 12) + (getBits<30, 25>(code) << 5) +
          (getBits<11, 8>(code) << 1) + (getBits<7, 7>(code) << 11) + 0);
      inst.execFunc_ = execF6;
      return inst;
    default:
      return inst;
    }
  case 103:
    inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
    inst.execFunc_ = execF7;
    return inst;
  case 111:
    inst.imm_ = signExtend<20>(
        (getBits<31, 31>(code) << 20) + (getBits<30, 21>(code) << 1) +
        (getBits<20, 20>(code) << 11) + (getBits<19, 12>(code) << 12) + 0);
    inst.execFunc_ = execF8;
    return inst;
  case 55:
    inst.imm_ = signExtend<31>((getBits<31, 12>(code) << 12) + 0);
    inst.execFunc_ = execF9;
    return inst;
  case 23:
    inst.imm_ = signExtend<31>((getBits<31, 12>(code) << 12) + 0);
    inst.execFunc_ = execF10;
    return inst;
  case 19:
    switch (getBits<14, 12>(code)) {
    case 0:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF11;
      return inst;
    case 1:
      inst.imm_ = signExtend<5>((getBits<25, 20>(code) << 0) + 0);
      inst.execFunc_ = execF12;
      return inst;
    case 2:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF13;
      return inst;
    case 3:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF14;
      return inst;
    case 4:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF15;
      return inst;
    case 5:
      switch (getBits<31, 26>(code)) {
      case 0:
        inst.imm_ = signExtend<5>((getBits<25, 20>(code) << 0) + 0);
        inst.execFunc_ = execF16;
        return inst;
      case 16:
        inst.imm_ = signExtend<5>((getBits<25, 20>(code) << 0) + 0);
        inst.execFunc_ = execF17;
        return inst;
      default:
        return inst;
      }
    case 6:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF18;
      return inst;
    case 7:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF19;
      return inst;
    default:
      return inst;
    }
  case 51:
    switch (getBits<31, 25>(code)) {
    case 0:
      switch (getBits<14, 12>(code)) {
      case 0:
        inst.execFunc_ = execF20;
        return inst;
      case 1:
        inst.execFunc_ = execF21;
        return inst;
      case 2:
        inst.execFunc_ = execF22;
        return inst;
      case 3:
        inst.execFunc_ = execF23;
        return inst;
      case 4:
        inst.execFunc_ = execF24;
        return inst;
      case 5:
        inst.execFunc_ = execF25;
        return inst;
      case 6:
        inst.execFunc_ = execF26;
        return inst;
      case 7:
        inst.execFunc_ = execF27;
        return inst;
      default:
        return inst;
      }
    case 32:
      switch (getBits<14, 12>(code)) {
      case 0:
        inst.execFunc_ = execF28;
        return inst;
      case 5:
        inst.execFunc_ = execF29;
        return inst;
      default:
        return inst;
      }
    case 1:
      switch (getBits<14, 12>(code)) {
      case 0:
        inst.execFunc_ = execF30;
        return inst;
      case 1:
        inst.execFunc_ = execF31;
        return inst;
      case 2:
        inst.execFunc_ = execF32;
        return inst;
      case 3:
        inst.execFunc_ = execF33;
        return inst;
      case 4:
        inst.execFunc_ = execF34;
        return inst;
      case 5:
        inst.execFunc_ = execF35;
        return inst;
      case 6:
        inst.execFunc_ = execF36;
        return inst;
      case 7:
        inst.execFunc_ = execF37;
        return inst;
      default:
        return inst;
      }
    default:
      return inst;
    }
  case 27:
    switch (getBits<14, 12>(code)) {
    case 0:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF38;
      return inst;
    case 1:
      inst.execFunc_ = execF39;
      return inst;
    case 5:
      switch (getBits<31, 25>(code)) {
      case 0:
        inst.execFunc_ = execF40;
        return inst;
      case 32:
        inst.execFunc_ = execF41;
        return inst;
      default:
        return inst;
      }
    default:
      return inst;
    }
  case 59:
    switch (getBits<31, 25>(code)) {
    case 0:
      switch (getBits<14, 12>(code)) {
      case 0:
        inst.execFunc_ = execF42;
        return inst;
      case 1:
        inst.execFunc_ = execF43;
        return inst;
      case 5:
        inst.execFunc_ = execF44;
        return inst;
      default:
        return inst;
      }
    case 32:
      switch (getBits<14, 12>(code)) {
      case 0:
        inst.execFunc_ = execF45;
        return inst;
      case 5:
        inst.execFunc_ = execF46;
        return inst;
      default:
        return inst;
      }
    case 1:
      switch (getBits<14, 12>(code)) {
      case 0:
        inst.execFunc_ = execF47;
        return inst;
      case 4:
        inst.execFunc_ = execF48;
        return inst;
      case 5:
        inst.execFunc_ = execF49;
        return inst;
      case 6:
        inst.execFunc_ = execF50;
        return inst;
      case 7:
        inst.execFunc_ = execF51;
        return inst;
      default:
        return inst;
      }
    default:
      return inst;
    }
  case 3:
    switch (getBits<14, 12>(code)) {
    case 0:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF52;
      return inst;
    case 1:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF53;
      return inst;
    case 2:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF54;
      return inst;
    case 3:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF55;
      return inst;
    case 4:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF56;
      return inst;
    case 5:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF57;
      return inst;
    case 6:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF58;
      return inst;
    default:
      return inst;
    }
  case 35:
    switch (getBits<14, 12>(code)) {
    case 0:
      inst.imm_ = signExtend<11>((getBits<31, 25>(code) << 5) +
                                 (getBits<11, 7>(code) << 0) + 0);
      inst.execFunc_ = execF59;
      return inst;
    case 1:
      inst.imm_ = signExtend<11>((getBits<31, 25>(code) << 5) +
                                 (getBits<11, 7>(code) << 0) + 0);
      inst.execFunc_ = execF60;
      return inst;
    case 2:
      inst.imm_ = signExtend<11>((getBits<31, 25>(code) << 5) +
                                 (getBits<11, 7>(code) << 0) + 0);
      inst.execFunc_ = execF61;
      return inst;
    case 3:
      inst.imm_ = signExtend<11>((getBits<31, 25>(code) << 5) +
                                 (getBits<11, 7>(code) << 0) + 0);
      inst.execFunc_ = execF62;
      return inst;
    default:
      return inst;
    }
  case 15:
    switch (getBits<14, 12>(code)) {
    case 0:
      inst.execFunc_ = execF63;
      return inst;
    case 1:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF64;
      return inst;
    default:
      return inst;
    }
  case 47:
    switch (getBits<31, 27>(code)) {
    case 0:
      switch (getBits<14, 12>(code)) {
      case 2:
        inst.execFunc_ = execF65;
        return inst;
      case 3:
        inst.execFunc_ = execF66;
        return inst;
      default:
        return inst;
      }
    case 4:
      switch (getBits<14, 12>(code)) {
      case 2:
        inst.execFunc_ = execF67;
        return inst;
      case 3:
        inst.execFunc_ = execF68;
        return inst;
      default:
        return inst;
      }
    case 8:
      switch (getBits<14, 12>(code)) {
      case 2:
        inst.execFunc_ = execF69;
        return inst;
      case 3:
        inst.execFunc_ = execF70;
        return inst;
      default:
        return inst;
      }
    case 12:
      switch (getBits<14, 12>(code)) {
      case 2:
        inst.execFunc_ = execF71;
        return inst;
      case 3:
        inst.execFunc_ = execF72;
        return inst;
      default:
        return inst;
      }
    case 16:
      switch (getBits<14, 12>(code)) {
      case 2:
        inst.execFunc_ = execF73;
        return inst;
      case 3:
        inst.execFunc_ = execF74;
        return inst;
      default:
        return inst;
      }
    case 20:
      switch (getBits<14, 12>(code)) {
      case 2:
        inst.execFunc_ = execF75;
        return inst;
      case 3:
        inst.execFunc_ = execF76;
        return inst;
      default:
        return inst;
      }
    case 24:
      switch (getBits<14, 12>(code)) {
      case 2:
        inst.execFunc_ = execF77;
        return inst;
      case 3:
        inst.execFunc_ = execF78;
        return inst;
      default:
        return inst;
      }
    case 28:
      switch (getBits<14, 12>(code)) {
      case 2:
        inst.execFunc_ = execF79;
        return inst;
      case 3:
        inst.execFunc_ = execF80;
        return inst;
      default:
        return inst;
      }
    case 1:
      switch (getBits<14, 12>(code)) {
      case 2:
        inst.execFunc_ = execF81;
        return inst;
      case 3:
        inst.execFunc_ = execF82;
        return inst;
      default:
        return inst;
      }
    case 2:
      switch (getBits<24, 20>(code)) {
      case 0:
        switch (getBits<14, 12>(code)) {
        case 2:
          inst.execFunc_ = execF83;
          return inst;
        case 3:
          inst.execFunc_ = execF84;
          return inst;
        default:
          return inst;
        }
      default:
        return inst;
      }
    case 3:
      switch (getBits<14, 12>(code)) {
      case 2:
        inst.execFunc_ = execF85;
        return inst;
      case 3:
        inst.execFunc_ = execF86;
        return inst;
      default:
        return inst;
      }
    default:
      return inst;
    }
  case 115:
    switch (getBits<14, 12>(code)) {
    case 0:
      switch (getBits<31, 25>(code)) {
      case 0:
        switch (getBits<24, 15>(code)) {
        case 0:
          inst.execFunc_ = execF87;
          return inst;
        case 32:
          inst.execFunc_ = execF88;
          return inst;
        case 64:
          inst.execFunc_ = execF89;
          return inst;
        default:
          return inst;
        }
      case 8:
        switch (getBits<24, 15>(code)) {
        case 64:
          inst.execFunc_ = execF90;
          return inst;
        case 160:
          inst.execFunc_ = execF91;
          return inst;
        default:
          return inst;
        }
      case 24:
        inst.execFunc_ = execF92;
        return inst;
      case 61:
        inst.execFunc_ = execF93;
        return inst;
      case 9:
        inst.execFunc_ = execF94;
        return inst;
      case 17:
        inst.execFunc_ = execF95;
        return inst;
      case 49:
        inst.execFunc_ = execF96;
        return inst;
      default:
        return inst;
      }
    case 1:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF97;
      return inst;
    case 2:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF98;
      return inst;
    case 3:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF99;
      return inst;
    case 5:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF100;
      return inst;
    case 6:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF101;
      return inst;
    case 7:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF102;
      return inst;
    default:
      return inst;
    }
  case 83:
    switch (getBits<31, 25>(code)) {
    case 0:
      inst.execFunc_ = execF103;
      return inst;
    case 4:
      inst.execFunc_ = execF104;
      return inst;
    case 8:
      inst.execFunc_ = execF105;
      return inst;
    case 12:
      inst.execFunc_ = execF106;
      return inst;
    case 16:
      switch (getBits<14, 12>(code)) {
      case 0:
        inst.execFunc_ = execF107;
        return inst;
      case 1:
        inst.execFunc_ = execF108;
        return inst;
      case 2:
        inst.execFunc_ = execF109;
        return inst;
      default:
        return inst;
      }
    case 20:
      switch (getBits<14, 12>(code)) {
      case 0:
        inst.execFunc_ = execF110;
        return inst;
      case 1:
        inst.execFunc_ = execF111;
        return inst;
      default:
        return inst;
      }
    case 44:
      inst.execFunc_ = execF112;
      return inst;
    case 1:
      inst.execFunc_ = execF113;
      return inst;
    case 5:
      inst.execFunc_ = execF114;
      return inst;
    case 9:
      inst.execFunc_ = execF115;
      return inst;
    case 13:
      inst.execFunc_ = execF116;
      return inst;
    case 17:
      switch (getBits<14, 12>(code)) {
      case 0:
        inst.execFunc_ = execF117;
        return inst;
      case 1:
        inst.execFunc_ = execF118;
        return inst;
      case 2:
        inst.execFunc_ = execF119;
        return inst;
      default:
        return inst;
      }
    case 21:
      switch (getBits<14, 12>(code)) {
      case 0:
        inst.execFunc_ = execF120;
        return inst;
      case 1:
        inst.execFunc_ = execF121;
        return inst;
      default:
        return inst;
      }
    case 32:
      switch (getBits<24, 20>(code)) {
      case 1:
        inst.execFunc_ = execF122;
        return inst;
      case 3:
        inst.execFunc_ = execF123;
        return inst;
      default:
        return inst;
      }
    case 33:
      switch (getBits<24, 20>(code)) {
      case 0:
        inst.execFunc_ = execF124;
        return inst;
      case 3:
        inst.execFunc_ = execF125;
        return inst;
      default:
        return inst;
      }
    case 45:
      inst.execFunc_ = execF126;
      return inst;
    case 3:
      inst.execFunc_ = execF127;
      return inst;
    case 7:
      inst.execFunc_ = execF128;
      return inst;
    case 11:
      inst.execFunc_ = execF129;
      return inst;
    case 15:
      inst.execFunc_ = execF130;
      return inst;
    case 19:
      switch (getBits<14, 12>(code)) {
      case 0:
        inst.execFunc_ = execF131;
        return inst;
      case 1:
        inst.execFunc_ = execF132;
        return inst;
      case 2:
        inst.execFunc_ = execF133;
        return inst;
      default:
        return inst;
      }
    case 23:
      switch (getBits<14, 12>(code)) {
      case 0:
        inst.execFunc_ = execF134;
        return inst;
      case 1:
        inst.execFunc_ = execF135;
        return inst;
      default:
        return inst;
      }
    case 35:
      switch (getBits<24, 20>(code)) {
      case 0:
        inst.execFunc_ = execF136;
        return inst;
      case 1:
        inst.execFunc_ = execF137;
        return inst;
      default:
        return inst;
      }
    case 47:
      inst.execFunc_ = execF138;
      return inst;
    case 80:
      switch (getBits<14, 12>(code)) {
      case 0:
        inst.execFunc_ = execF139;
        return inst;
      case 1:
        inst.execFunc_ = execF140;
        return inst;
      case 2:
        inst.execFunc_ = execF141;
        return inst;
      default:
        return inst;
      }
    case 81:
      switch (getBits<14, 12>(code)) {
      case 0:
        inst.execFunc_ = execF142;
        return inst;
      case 1:
        inst.execFunc_ = execF143;
        return inst;
      case 2:
        inst.execFunc_ = execF144;
        return inst;
      default:
        return inst;
      }
    case 83:
      switch (getBits<14, 12>(code)) {
      case 0:
        inst.execFunc_ = execF145;
        return inst;
      case 1:
        inst.execFunc_ = execF146;
        return inst;
      case 2:
        inst.execFunc_ = execF147;
        return inst;
      default:
        return inst;
      }
    case 96:
      switch (getBits<24, 20>(code)) {
      case 0:
        inst.execFunc_ = execF148;
        return inst;
      case 1:
        inst.execFunc_ = execF149;
        return inst;
      case 2:
        inst.execFunc_ = execF150;
        return inst;
      case 3:
        inst.execFunc_ = execF151;
        return inst;
      default:
        return inst;
      }
    case 112:
      switch (getBits<24, 20>(code)) {
      case 0:
        switch (getBits<14, 12>(code)) {
        case 0:
          inst.execFunc_ = execF152;
          return inst;
        case 1:
          inst.execFunc_ = execF153;
          return inst;
        default:
          return inst;
        }
      default:
        return inst;
      }
    case 97:
      switch (getBits<24, 20>(code)) {
      case 0:
        inst.execFunc_ = execF154;
        return inst;
      case 1:
        inst.execFunc_ = execF155;
        return inst;
      case 2:
        inst.execFunc_ = execF156;
        return inst;
      case 3:
        inst.execFunc_ = execF157;
        return inst;
      default:
        return inst;
      }
    case 113:
      switch (getBits<24, 20>(code)) {
      case 0:
        switch (getBits<14, 12>(code)) {
        case 0:
          inst.execFunc_ = execF158;
          return inst;
        case 1:
          inst.execFunc_ = execF159;
          return inst;
        default:
          return inst;
        }
      default:
        return inst;
      }
    case 99:
      switch (getBits<24, 20>(code)) {
      case 0:
        inst.execFunc_ = execF160;
        return inst;
      case 1:
        inst.execFunc_ = execF161;
        return inst;
      case 2:
        inst.execFunc_ = execF162;
        return inst;
      case 3:
        inst.execFunc_ = execF163;
        return inst;
      default:
        return inst;
      }
    case 115:
      switch (getBits<24, 20>(code)) {
      case 0:
        switch (getBits<14, 12>(code)) {
        case 0:
          inst.execFunc_ = execF164;
          return inst;
        case 1:
          inst.execFunc_ = execF165;
          return inst;
        default:
          return inst;
        }
      default:
        return inst;
      }
    case 104:
      switch (getBits<24, 20>(code)) {
      case 0:
        inst.execFunc_ = execF166;
        return inst;
      case 1:
        inst.execFunc_ = execF167;
        return inst;
      case 2:
        inst.execFunc_ = execF168;
        return inst;
      case 3:
        inst.execFunc_ = execF169;
        return inst;
      default:
        return inst;
      }
    case 120:
      inst.execFunc_ = execF170;
      return inst;
    case 105:
      switch (getBits<24, 20>(code)) {
      case 0:
        inst.execFunc_ = execF171;
        return inst;
      case 1:
        inst.execFunc_ = execF172;
        return inst;
      case 2:
        inst.execFunc_ = execF173;
        return inst;
      case 3:
        inst.execFunc_ = execF174;
        return inst;
      default:
        return inst;
      }
    case 121:
      inst.execFunc_ = execF175;
      return inst;
    case 107:
      switch (getBits<24, 20>(code)) {
      case 0:
        inst.execFunc_ = execF176;
        return inst;
      case 1:
        inst.execFunc_ = execF177;
        return inst;
      case 2:
        inst.execFunc_ = execF178;
        return inst;
      case 3:
        inst.execFunc_ = execF179;
        return inst;
      default:
        return inst;
      }
    case 123:
      inst.execFunc_ = execF180;
      return inst;
    default:
      return inst;
    }
  case 7:
    switch (getBits<14, 12>(code)) {
    case 2:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF181;
      return inst;
    case 3:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF182;
      return inst;
    case 4:
      inst.imm_ = signExtend<11>((getBits<31, 20>(code) << 0) + 0);
      inst.execFunc_ = execF183;
      return inst;
    default:
      return inst;
    }
  case 39:
    switch (getBits<14, 12>(code)) {
    case 2:
      inst.imm_ = signExtend<11>((getBits<31, 25>(code) << 5) +
                                 (getBits<11, 7>(code) << 0) + 0);
      inst.execFunc_ = execF184;
      return inst;
    case 3:
      inst.imm_ = signExtend<11>((getBits<31, 25>(code) << 5) +
                                 (getBits<11, 7>(code) << 0) + 0);
      inst.execFunc_ = execF185;
      return inst;
    case 4:
      inst.imm_ = signExtend<11>((getBits<31, 25>(code) << 5) +
                                 (getBits<11, 7>(code) << 0) + 0);
      inst.execFunc_ = execF186;
      return inst;
    default:
      return inst;
    }
  case 67:
    switch (getBits<26, 25>(code)) {
    case 0:
      inst.execFunc_ = execF187;
      return inst;
    case 1:
      inst.execFunc_ = execF188;
      return inst;
    case 3:
      inst.execFunc_ = execF189;
      return inst;
    default:
      return inst;
    }
  case 71:
    switch (getBits<26, 25>(code)) {
    case 0:
      inst.execFunc_ = execF190;
      return inst;
    case 1:
      inst.execFunc_ = execF191;
      return inst;
    case 3:
      inst.execFunc_ = execF192;
      return inst;
    default:
      return inst;
    }
  case 75:
    switch (getBits<26, 25>(code)) {
    case 0:
      inst.execFunc_ = execF193;
      return inst;
    case 1:
      inst.execFunc_ = execF194;
      return inst;
    case 3:
      inst.execFunc_ = execF195;
      return inst;
    default:
      return inst;
    }
  case 79:
    switch (getBits<26, 25>(code)) {
    case 0:
      inst.execFunc_ = execF196;
      return inst;
    case 1:
      inst.execFunc_ = execF197;
      return inst;
    case 3:
      inst.execFunc_ = execF198;
      return inst;
    default:
      return inst;
    }
  default:
    return inst;
  }

  return inst;
}

} // namespace CPUSimulation