import sys

sols = list()

def subset_sum(numbers, target, partial=[]):
    s = sum(partial)

    # check if the partial sum is equals to target
    if s == target:
        sols.append(partial)
    if s >= target:
        return  # if we reach the number why bother to continue

    for i in range(len(numbers)):
        n = numbers[i]
        remaining = numbers[i+1:]
        subset_sum(remaining, target, partial + [n])


if __name__ == "__main__":
    subset_sum([int(i) for i in open(sys.argv[1]).read().split()], 150)

    print(len(sols))
    lens = [len(el) for el in sols]
    print(lens.count(min(lens)))
