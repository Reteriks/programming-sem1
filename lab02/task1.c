#include <stdio.h>
#include <math.h>
#include <windows.h>

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    float x_start, x_end, dx;
    
    printf("Введіть початкове значення X_start: ");
    scanf("%f", &x_start);
    printf("Введіть кінцеве значення X_end: ");
    scanf("%f", &x_end);
    printf("Введіть крок dX: ");
    scanf("%f", &dx);
    
    // Перевірка коректності введених даних
    if (x_start >= x_end || dx <= 0) {
        printf("\nПомилка: X_start має бути меншим за X_end, а крок dX — більшим за 0!\n");
        return 1;
    }
    
    printf("\n------------------------\n");
    printf("|    X    |     Y      |\n");
    printf("------------------------\n");
    
    for (float x = x_start; x <= x_end; x += dx) {
        float y;
        if (x <= 1.0) {
            y = cos(x);
        } 
        else if (x > 1.0 && x <= 4.0) {
            if (x == 1.0) {
                printf("| %7.2f |  помилка   |\n", x);
                continue;
            }
            y = 1.0 / (x - 1.0);
        } 
        else {
            y = 2.0 * x - 5.0;
        }
        
        printf("| %7.2f | %10.4f |\n", x, y);
    }
    printf("------------------------\n");
    
    return 0;
}