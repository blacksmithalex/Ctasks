#ifndef VECTOR2D
#define VECTOR2D

#include <cmath>

class Vector2d {
 private:
  double x;
  double y;
 public:
  /* Реализацию методов ниже напишем в файле исходного кода. */
  Vector2d();
  Vector2d(double xArg, double yArg);
  
  double Length() const;
  void Add(const Vector2d& other);

  /* А вот эти методы напишем сразу вместе с реализацией. */
  double X() const { return x; }
  double& X() { return x; }
  double Y() const { return y; }
  double& Y() { return y; }
};

#endif // VECTOR2D

