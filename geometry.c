#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT 100

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point center;
    float radius;
} Circle;

void read_circle(char *input, Circle *c) {
    unsigned long n = strlen(input);
    //printf("%ld\n", n);
    int i = 0, j = 0;
    char temp[MAX_INPUT];
    float x, y, r;

    // Проверяем формат ввода
    if (strncmp(input, "circle(", 7) != 0 || input[n-2] != ')') {
        printf("Неверный формат ввода\n");
        exit(EXIT_FAILURE);
    }

    // Извлекаем координаты центра и радиус
    i = 7;
    while (input[i] != ' ') {     //до тех пор пока каретка не встретит пробел (означающий отделение координаты х от координаты у...)
        temp[j++] = input[i++]; //координата x будет записана в масив temp как строка
    }
    temp[j] = '\0'; // когда цикл закончил свою работу массив "завершается"...
    x = atof(temp); // а его значение передаются в формате double в переменную ч

    j = 0;
    i++;
    while (input[i] != ',') { // предыдущие действия повторяются снова, пока не достигнут запятой
        temp[j++] = input[i++]; //которая значит что закончилась координата у и начался радиус
    }
    temp[j] = '\0';
    y = atof(temp);

    j = 0;
    i++;
    while (input[i] != ')') {     //все тоже самое но с радиусом
        temp[j++] = input[i++];
    }
    temp[j] = '\0';
    r = atof(temp);

    c->center.x = x;
    c->center.y = y;
    c->radius = r;
}

void print_circle(Circle c) {
    printf("circle(%.2f %.2f, %.2f)\n", c.center.x, c.center.y, c.radius);
}

double circle_perimeter(Circle c) {
    return 2 * M_PI * c.radius;
}

double circle_area(Circle c) {
    return M_PI * c.radius * c.radius;
}

int main() {
    char input[MAX_INPUT];
    Circle c;

    // Считываем данные об окружности
    printf("Введите данные об окружности в формате WKT: ");
    fgets(input, MAX_INPUT, stdin);
    read_circle(input, &c);

    // Выводим информацию о окружности
    printf("Центр окружности: (%.2f, %.2f)\n", c.center.x, c.center.y);
    printf("Радиус: %.2f\n", c.radius);
    printf("Длина окружности: %.2f\n", circle_perimeter(c));
    printf("Площадь круга: %.2f\n", circle_area(c));
    print_circle(c);

    return 0;
}
