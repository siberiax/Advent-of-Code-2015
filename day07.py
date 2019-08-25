import sys

known = {}
commands = {}

for line in open(sys.argv[1]):
    command, result = line.strip().split(' -> ')
    if command.isdigit():
        known[result] = int(command)
    else:
        commands[result] = command

while 'a' not in known:
    to_remove = []
    for key, value in commands.items():
        fields = value.split()
        if len(fields) == 1:
            if fields[0] in known:
                known[key] = known[fields[0]]
                to_remove.append(key)
        elif len(fields) == 2:
            if fields[1] in known:
                known[key] = ~known[fields[1]]
                to_remove.append(key)
        else:
            if fields[1] == 'RSHIFT' and fields[0] in known:
                known[key] = known[fields[0]] >> int(fields[2])
                to_remove.append(key)
            elif fields[1] == 'LSHIFT' and fields[0] in known:
                known[key] = known[fields[0]] << int(fields[2])
                to_remove.append(key)
            elif fields[1] == 'OR' and fields[0] in known and fields[2] in known:
                known[key] = known[fields[0]] | known[fields[2]]
                to_remove.append(key)
            else:
                if fields[0].isdigit() and fields[2] in known:
                    known[key] = int(fields[0]) & known[fields[2]]
                    to_remove.append(key)
                elif fields[0] in known and fields[2] in known:
                    known[key] = known[fields[0]] & known[fields[2]]
                    to_remove.append(key)
                else:
                    continue
    for el in to_remove:
        commands.pop(el)

print(known['a'])
