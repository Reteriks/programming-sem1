#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>

void wait_exit(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    printf("\nНатисніть Enter для виходу...");
    getchar();
}

void reverse_segment(int *arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(void) {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int n, k;

    printf("Введіть розмір масиву N: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Некоректний розмір масиву.\n");
        wait_exit();
        return 1;
    }

    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Критична помилка: дефіцит RAM (malloc повернув NULL)!\n");
        wait_exit();
        return 1;
    }

    printf("Введіть %d цілих чисел:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Помилка вводу елемента.\n");
            free(arr);
            wait_exit();
            return 1;
        }
    }

    printf("Введіть величину зсуву праворуч K: ");
    if (scanf("%d", &k) != 1) {
        fprintf(stderr, "Помилка вводу K.\n");
        free(arr);
        wait_exit();
        return 1;
    }

    k = ((k % n) + n) % n;

    if (k > 0) {
        reverse_segment(arr, 0, n - 1);
        reverse_segment(arr, 0, k - 1);
        reverse_segment(arr, k, n - 1);
    }

    printf("Масив після зсуву праворуч на %d позицій:\n", k);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;

    wait_exit();
    return 0;
}
