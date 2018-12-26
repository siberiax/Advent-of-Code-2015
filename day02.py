import sys

total = 0
ribbon = 0
for line in open(sys.argv[1]):
    fields = line.strip().split('x')
    a = int(fields[0])
    b = int(fields[1])
    c = int(fields[2])
    total += 2*a*b + 2*a*c + 2*b*c
    total += min(a*b,b*c,a*c)
    nums = sorted([a,b,c])
    ribbon += 2*nums[0] + 2*nums[1] + a*b*c
print(total)
print(ribbon)
