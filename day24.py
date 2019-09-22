import sys
from functools import reduce
import itertools

# nums = [int(i) for i in open(sys.argv[1]).read().split()]

nums = [1,2,3,4,5,6]

smallest = 999999
smallest_groups = []

for start1 in range(len(nums) + 1):
    for end1 in range(start1, len(nums) + 1):
        for start2 in range(end1, len(nums)):
            for end2 in range(start2, len(nums) + 1):
                group1 = nums[start1:end1]
                group2 = nums[start2:end2]
                group3  = []
                for el in nums:
                    if el not in group1 and el not in group2:
                        group3.append(el)
                if (len(group1) and len(group2) and len(group3)):
                    print(group1, group2, group3)
                if (sum(group1) == sum(group2) == sum(group3)):
                    print(group1, group2,group3)
                    for group in [group1, group2, group3]:
                        if len(group) < smallest:
                            smallest = len(group)
                            smallest_groups = []
                            smallest_groups.append(group)
                        elif (len(group) == smallest):
                            smallest_groups.append(group)

smallest_qe = 999999

for group in smallest_groups:
    mul = reduce(lambda x, y: x*y, group)
    if mul < smallest_qe:
        smallest_qe = mul

print(smallest_qe)
