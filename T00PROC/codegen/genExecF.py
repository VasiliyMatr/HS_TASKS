
out = open('execGen.hh', 'w')

top = open ('exec-top', 'r')
out.write (top.read ())
top.close ()

for i in range(0, 199):
    out.write (f"execStatus_t execF{i}( const Instruction* inst )\n")
    out.write ("{\n")
    out.write ("    return execStatus_t::UNKNOWN_INSTR;\n")
    out.write ("}\n\n")

bot = open ('exec-bot', 'r')
out.write (bot.read ())
bot.close ()

out.close ()
