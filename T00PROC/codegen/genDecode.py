import yaml
import os

# yaml props
IN_NAME = 'risc-v.yaml'
DEC_TREE_NAME = 'decodertree'
FIELDS_SET_NAME = 'fields'

# files props
TOP_NAME = 'dec-top'
BOT_NAME = 'dec-bot'
OUT_NAME = 'dec.cc'
TMP_NAME = 'tmp'

with open(IN_NAME) as spec:
    info = yaml.safe_load(spec)

decodeTree = info[DEC_TREE_NAME]
fields = info[FIELDS_SET_NAME]
instId = 1

tmp = open (TMP_NAME, 'w')

top = open (TOP_NAME, 'r')
tmp.write (top.read ())
top.close ()

def printImm( bits ):
    tmp.write (f"inst.imm_ = signExtend<{bits[0]['from']}> (")
    for i in bits:
        tmp.write (f"(getBits<{i['msb']}, {i['lsb']}> (code) << {i['to']}) +")

    tmp.write ('0);')

def printLeaf( leaf ):
    global instId
    fieldsNames = leaf['fields']
    for i in fieldsNames:
        name = fields[i]['name']
        if (name == 'imm' or name == 'shamt'):
            printImm (fields[i]['location']['bits'])
            break

    tmp.write (f'inst.execFunc_ = execF{instId};')
    tmp.write (f'return inst;')
    instId += 1

def printTree( node ):
    range = node['range']
    tmp.write(f"switch (getBits<{range['msb']}, {range['lsb']}> (code))")
    tmp.write('{')
    childs = node['nodes']
    keys = childs.keys ()
    for i in keys:
        tmp.write(f"case {i}:")
        child = childs.get(i)
        if (child.get('nodes') != None):
            printTree (child)
        else:
            printLeaf (child)

    tmp.write ('default: return inst;')
    tmp.write ('}')

printTree(decodeTree)

bot = open (BOT_NAME, 'r')
tmp.write (bot.read ())
bot.close ()

tmp.close ()

os.system(f"clang-format {TMP_NAME} > {OUT_NAME}")
os.system(f"rm {TMP_NAME}")
