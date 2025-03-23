#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    double a;
    double b;
    double c;
} line;

line pointstoline(point p1, point p2) {
    line result;
    double dy = p2.y - p1.y;
    double dx = p2.x - p1.x;
    result.a = dy;
    result.b = -dx;
    result.c = -p1.x * dy + p1.y * dx;
    return result;
}

point kramer(line line1, line line2) {
    point intersection;
    float D = line1.a * line2.b - line2.a * line1.b;
    float Dx = (-line1.c) * line2.b - (-line2.c) * line1.b;
    float Dy =  line1.a * (-line2.c) - line2.a * (-line1.c);
    intersection.x = Dx / D;
    intersection.y = Dy / D;
    return intersection;
}

int main() {
    point p1, p2, p3, p4, inter;
    line line1, line2;
    scanf("%lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y);
    scanf("%lf %lf %lf %lf", &p3.x, &p3.y, &p4.x, &p4.y);
    line1 = pointstoline(p1, p2);
    line2 = pointstoline(p3, p4);

    bool rule1 = line1.a * line2.b == line1.b * line2.a;
    bool rule2 = line1.b * line2.c == line1.c * line2.b;
    bool rule3 = line1.a * line2.c == line1.c * line2.a;

    // printf("%lf %lf %lf\n", line1.a, line1.b, line1.c);
    // printf("%lf %lf %lf\n", line2.a, line2.b, line2.c);
    if (rule1 && rule2 && rule3) {
        printf("%d", 2);
        return 0;
    }
    if (rule1 && (!rule2 || !rule3)) {
        printf("%d", 0);
        return 0;
    }
    inter = kramer(line1, line2);
    printf("1 %lf %lf", inter.x, inter.y);
    
    return 0;
}
