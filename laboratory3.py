class Cities:

    def __init__(self, adjacency_matrix):
        self.adjacency_matrix = adjacency_matrix
        self.cities_in_radius = set()

    def get_number_of_cities(self, city, max_distance):
        for i in range(len(self.adjacency_matrix[city])):
            city_distance = self.adjacency_matrix[city][i]
            if max_distance >= city_distance and city != i and city_distance:
                self.cities_in_radius.add(i)
                self.get_number_of_cities(i, max_distance - city_distance)

        return self.cities_in_radius


n = int(input('Количество городов: '))
matrix = []
for _ in range(n):
    matrix.append([int(i) for i in input().split()])

capital = int(input('Столица: '))
distance = int(input('Расстояние: '))
cities = Cities(matrix)
print('N-переферия:', ' '.join(
    [str(i+1) for i in cities.get_number_of_cities(capital - 1, distance)]
))
