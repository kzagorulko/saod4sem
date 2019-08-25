from functools import reduce


def double(arr):
    results = []
    for i in arr:
        results.append(i * 2)
    return results


def add(arr):
    result = 0
    for i in arr:
        result += i
    return result


def add_lambda(arr):
    return reduce(
        lambda x, y: x + y, arr
    )


def double_lambda(arr):
    return map(lambda i: i * 2, arr)


a = [1, 2, 3]

print(double(a))
print([i * 2 for i in a])
print(double(a), "\n")

print(add(a))
print(add_lambda(a))
print(sum(a))

