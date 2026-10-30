#include <stdio.h>

#define BUFFER_SIZE 256

void reverse_range(char str[], int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
int main() {
    char str[BUFFER_SIZE];

    printf("Enter text: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    
    int i = 0;
    int word_start = -1;


    while (str[i] != '\0') {
        char ch = str[i];

       
        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r') {
            if (word_start == -1) {
                word_start = i; 
            }
        } else {
           
            if (word_start != -1) {
                reverse_range(str, word_start, i - 1);
                word_start = -1;
            }
        }
        i++;
    }

    if (word_start != -1) {
        reverse_range(str, word_start, i - 1);
    }

    printf("Result: %s", str);

    return 0;
}