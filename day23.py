import sys

instructions = open(sys.argv[1]).read().split('\n')[:-1]

registers = {}
registers['a'] = 1
registers['b'] = 0

eip = 0

while(eip < len(instructions)):
    curr = instructions[eip]

    fields = curr.split()

    if fields[0] == 'inc':
        registers[fields[1]] += 1
        eip += 1
    elif fields[0] == 'hlf':
        registers[fields[1]] //= 2
        eip += 1
    elif fields[0] == 'tpl':
        registers[fields[1]] *= 3
        eip += 1
    elif fields[0] == 'jmp':
        eip += int(fields[1])
    elif fields[0] == 'jio':
        if (registers[fields[1][:-1]] == 1):
            eip += int(fields[2])
        else:
            eip += 1
    else:
        if (registers[fields[1][:-1]] % 2 == 0):
            eip += int(fields[2])
        else:
            eip += 1

print(registers['b'])
