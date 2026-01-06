#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
  int x;
  int y;
};

int main() {
  /* Внешний список инициализации для вектора, внутренние --- для его элементов. */
  std::vector<Point> points = {
    {1, 2}, {2, 5}, {5, 3}, {5, 8}, {4, 1}, {3, 7}
  };

  /* Сохраняем лямбду в переменную comparator. Вместо типа данных следует поставить
     auto. */
  auto comparator = [](const Point& left, const Point& right) {
    return left.x < right.x;
  };

  /* Сортируем вектор по возрастанию иксов. В качестве третьего параметра функции
     std::sort() используется лямбда-выражение, задающее правило сравнения элементов
     вектора. */
  std::sort(points.begin(), points.end(), comparator);

  return 0;
}

