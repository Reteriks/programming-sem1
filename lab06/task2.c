#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    size_t capacity = 2;
    size_t count = 0;

    double *buffer = (double *)malloc(capacity * sizeof(double));
    if (buffer == NULL) {
        fprintf(stderr, "Помилка початкового виділення пам'яті!\n");
        wait_exit();
        return 1;
    }

    printf("Вводьте дійсні числа (0.0 для завершення):\n");
    while (1) {
        double val;
        if (scanf("%lf", &val) != 1) {
            printf("Некоректний ввід.\n");
            break;
        }

        if (fabs(val) < 1e-9) {
            break;
        }

        if (count == capacity) {
            size_t new_capacity = capacity * 3;
            double *temp_ptr = (double *)realloc(buffer, new_capacity * sizeof(double));
            if (temp_ptr == NULL) {
                fprintf(stderr, "Помилка перевиділення пам'яті (realloc повернув NULL)!\n");
                free(buffer);
                buffer = NULL;
                wait_exit();
                return 1;
            }
            buffer = temp_ptr;
            capacity = new_capacity;
            printf("[INFO] Буфер розширено втричі -> нова місткість: %zu елементів\n", capacity);
        }

        buffer[count++] = val;
    }

    printf("\nНакопичено елементів: %zu (фінальна місткість: %zu)\n", count, capacity);
    for (size_t i = 0; i < count; i++) {
        printf("%.3f ", buffer[i]);
    }
    printf("\n");

    free(buffer);
    buffer = NULL;

    wait_exit();
    return 0;
}
