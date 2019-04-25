import math
import operator
import time


def timer(f):
    def tmp(*args, **kwargs):
        t = time.time()
        result = f(*args, **kwargs)
        print('Время выполнения функции: %f' % (time.time()-t))
        return result

    return tmp


class Sort:
    def __init__(self, array):
        self.array = array

    @timer
    def direct_inclusion(self):
        count = 0
        for i in range(1, len(self.array)):
            j = i
            while (j > 0) and (self.array[j] < self.array[j - 1]):
                self.array[j - 1], self.array[j] = \
                    self.array[j], self.array[j - 1]
                count += 2
                j -= 1

        return count

    @timer
    def binary_inclusion(self):
        self.array.sort()

        return round(len(self.array) * math.log1p(len(self.array)))

    @timer
    def direct_selection(self):
        count = 0
        for i in range(0, len(self.array)):
            min_index = self.array.index(min(self.array[i:]))
            self.array[i], self.array[min_index] = \
                self.array[min_index], self.array[i]
            count += 2
        return count

    @timer
    def cocktail(self):
        count = 0
        n = len(self.array)
        swapped = True
        start = 0
        end = n - 1
        while swapped:

            swapped = False

            for i in range(start, end):
                if self.array[i] > self.array[i + 1]:
                    self.array[i], self.array[i + 1] = \
                        self.array[i + 1], self.array[i]
                    count += 2
                    swapped = True

            if not swapped:
                break

            swapped = False

            end = end - 1

            for i in range(end - 1, start - 1, -1):
                if self.array[i] > self.array[i + 1]:
                    self.array[i], self.array[i + 1] = \
                        self.array[i + 1], self.array[i]
                    count += 2
                    swapped = True

            start = start + 1

        return count

    def __repr__(self):
        return '[' + ' '.join([str(i) for i in self.array]) + ']'


data = [int(i) for i in input().split()]

print('Сортировка с помощью прямого включения:')
sort = Sort(data[:])
res = sort.direct_inclusion()
print(sort, 'сложность:', res)
print('Сортировка с помощью двоичного включения:')
sort1 = Sort(data[:])
res1 = sort1.binary_inclusion()
print(sort1, 'сложность:', res1)
print('Сортировка с помощью прямого выбора:',)
sort2 = Sort(data[:])
res2 = sort2.direct_selection()
print(sort2, 'сложность:', res2)
print('Шейкерная сортировка:')
sort3 = Sort(data[:])
res3 = sort3.cocktail()
print(sort3, 'сложность:', res3)

k = int(input('Введите k='))
print(sort.array[:k])

print('Практическое приминение:')

dic = {}
teams = [team for team in input().split()]
for team in teams:
    key, value = team.split(':')
    dic[key] = int(value)

print(sorted(dic.items(), key=operator.itemgetter(1)))
