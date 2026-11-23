#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>

// Прототипи функцій
int gcd_with_steps(int a, int b, int *total_steps);

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
    int a, b;
    int steps = 0;

    printf("=== Обчислення НСД (Варіант 7) ===\n");
    printf("Введіть два числа (або 0 0 для виходу):\n");

    while (1) {
        printf("\nВведіть a та b: ");
        if (scanf("%d %d", &a, &b) != 2) {
            printf("Помилка вводу!\n");
            break;
        }
        if (a == 0 && b == 0) {
            break;
        }

        int result = gcd_with_steps(a, b, &steps);
        printf("НСД(%d, %d) = %d | Сумарна кількість кроків Евкліда за сесію: %d\n",
               a, b, result, steps);
    }

    wait_exit();
    return 0;
}

// Передача a та b виключно за значенням (Pass-by-Value)
int gcd_with_steps(int a, int b, int *total_steps) {
    static int cumulative_steps = 0; // Зберігає стан між викликами

    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
        cumulative_steps++;
    }

    if (total_steps != NULL) {
        *total_steps = cumulative_steps;
    }

    return a;
}
