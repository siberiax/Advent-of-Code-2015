import sys

chars = open(sys.argv[1]).read()

print(chars.count('(') - chars.count(')'))

curr = 0
for c in range(len(chars)):
    if chars[c] == '(':
        curr +=1
    else:
        curr -= 1
    if curr < 0:
        print(c+1)
        break
