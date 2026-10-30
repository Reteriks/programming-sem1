#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main() {
    int arr[SIZE];
    int negative_count = 0;

   
    srand((unsigned int)time(NULL));

  
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 101 - 50;
    }


    printf("Original array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

  
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < 0) {
            negative_count++;
        }
    }


    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] = 0;
        }
    }

    printf("Number of negative elements: %d\n\n", negative_count);

    printf("Modified array (even numbers replaced with 0):\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}