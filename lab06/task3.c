#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    size_t n = 6;
    int *original = (int *)malloc(n * sizeof(int));
    if (original == NULL) {
        return 1;
    }

    for (size_t i = 0; i < n; i++) {
        original[i] = (int)((i + 1) * 10);
    }

    int *copy = (int *)malloc(n * sizeof(int));
    if (copy == NULL) {
        free(original);
        original = NULL;
        return 1;
    }

    memcpy(copy, original, n * sizeof(int));
    copy[0] = 999;

    printf("Оригінал: ");
    for (size_t i = 0; i < n; i++) printf("%d ", original[i]);
    printf("\nКопія:    ");
    for (size_t i = 0; i < n; i++) printf("%d ", copy[i]);
    printf("\n");

    free(copy);
    copy = NULL;

    free(original);
    original = NULL;

    printf("\nНатисніть Enter для виходу...");
    getchar();
    return 0;
}
