#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stddef.h>

void zero_even_elements(int *start_ptr, size_t size);
void print_array(const int *start_ptr, size_t size);

int main(void) {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    int buffer[] = {13, 4, 7, 22, 8, 19, 10, 5};
    size_t n = sizeof(buffer) / sizeof(*buffer);

    printf("Початковий масив: ");
    print_array(buffer, n);

    zero_even_elements(buffer, n);

    printf("Після обробки:    ");
    print_array(buffer, n);

    printf("\nНатисніть Enter для виходу...");
    getchar();
    return 0;
}

void zero_even_elements(int *start_ptr, size_t size) {
    if (start_ptr == NULL || size == 0) {
        return;
    }

    int *ptr = start_ptr;
    int *end_ptr = start_ptr + size;

    while (ptr < end_ptr) {
        if (*ptr % 2 == 0) {
            ptrdiff_t index = ptr - start_ptr;
            printf("Занулення парного елемента %d на позиції %td\n", *ptr, index);
            *ptr = 0;
        }
        ptr++;
    }
}

void print_array(const int *start_ptr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", *(start_ptr + i));
    }
    printf("\n");
}
