#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>

#define PI 3.14159265358979323846

int calc_circle(const double *radius, double *length, double *area);

void wait_exit(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    printf("\nНатисніть Enter для виходу...");
    getchar();
}

int main(void) {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    double r, l = 0.0, s = 0.0;

    printf("Введіть радіус кола R: ");
    if (scanf("%lf", &r) != 1) {
        printf("Помилка вводу!\n");
        wait_exit();
        return 1;
    }

    int status = calc_circle(&r, &l, &s);
    if (status == 0) {
        printf("Успішно! Довжина кола L = %.4f, Площа круга S = %.4f\n", l, s);
    } else {
        printf("Помилка: некоректний радіус (має бути > 0) або NULL-покажчик.\n");
    }

    wait_exit();
    return 0;
}

int calc_circle(const double *radius, double *length, double *area) {
    if (radius == NULL || length == NULL || area == NULL || *radius <= 0.0) {
        return 1;
    }

    *length = 2.0 * PI * (*radius);
    *area   = PI * (*radius) * (*radius);

    return 0;
}
