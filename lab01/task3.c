#include <stdio.h>
#include <windows.h>

int main(void) {
SetConsoleCP(65001);
SetConsoleOutputCP(65001); 
    double mass, velocity, height;
    const double g = 9.81; 

    printf("Лабораторна робота №1: Кінетична та потенціальна енергія\n");
    
    printf("Введіть масу m (кг): ");
    if (scanf("%lf", &mass) != 1 || mass < 0) {
        printf("Помилка: некоректне значення маси!\n");
        return 1;
    }

    printf("Введіть швидкість v (м/с): ");
    if (scanf("%lf", &velocity) != 1 || velocity < 0) {
        printf("Помилка: некоректне значення швидкості!\n");
        return 1;
    }

    
    printf("Введіть висоту h (м): ");
    if (scanf("%lf", &height) != 1 || height < 0) {
        printf("Помилка: некоректне значення висоти!\n");
        return 1;
    }


    double kinetic_energy = (mass * velocity * velocity) / 2.0;
    double potential_energy = mass * g * height;
    double total_energy = kinetic_energy + potential_energy;

    printf("\n--- Результати розрахунку ---\n");
    printf("Кінетична енергія (Ek):   %.3f Дж\n", kinetic_energy);
    printf("Потенціальна енергія (Ep): %.3f Дж\n", potential_energy);
    printf("Повна механічна енергія:   %.3f Дж\n", total_energy);

    return 0;
}