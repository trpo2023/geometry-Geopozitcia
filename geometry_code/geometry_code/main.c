/*Вывод окружности в формате WKT*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Pixel
{
    float x;
    float y;
} point;

typedef struct Segment //описывает отрезок
{
    float a;
    float b;
} segment;

segment coordinates(point first, point second) //возвращает координаты соединяющие вектор
{
    segment res = {(second.x-first.x),(second.x-first.x)};
    return res;
}

double LenVector(segment vector) //длина вектора
{
    return sqrt((vector.a * vector.a) + (vector.b * vector.b));
}

float CircleArea(point spot, float radius)
{
    return M_PI * (radius * radius);
}

float CircleLen(point spot, float radius)
{
    return 2 * M_PI * radius;
}


