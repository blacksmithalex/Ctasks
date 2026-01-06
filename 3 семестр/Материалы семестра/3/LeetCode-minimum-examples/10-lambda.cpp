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

  const int x0 = 3;

  /* Немного более сложное правило сортировки. Внутри лямбда-выражения доступна
     константа x0 по значению. */
  std::sort(points.begin(), points.end(),
            [x0](const Point& left, const Point& right) {
    if (left.x <= x0 || right.x <= x0)
      return left.x < right.x;
    else
      return left.x > right.x;
  });
  return 0;
}

