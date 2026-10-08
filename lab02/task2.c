#include <stdio.h>
#include <math.h>
#include <windows.h>

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double x, eps;
    
    printf("Введіть аргумент X: ");
    scanf("%lf", &x);
    printf("Введіть точність eps: ");
    scanf("%lf", &eps);
    
    double sum = 1.0;
    double term = 1.0;
    int n = 1;
    
    while (fabs(term) > eps) {
        term = term * (x * x) / ((2 * n - 1) * (2 * n));
        sum += term;
        n++;
    }
    
    printf("\nСума ряду: %.6lf\n", sum);
    printf("Значення з math.h (cosh): %.6lf\n", cosh(x));
    printf("Кількість ітерацій: %d\n", n);
    
    return 0;
}