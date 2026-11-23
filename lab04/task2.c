#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdint.h>

uint32_t set_bit(uint32_t reg, uint8_t bit);
uint32_t clear_bit(uint32_t reg, uint8_t bit);
uint32_t toggle_bit(uint32_t reg, uint8_t bit);
int check_bit(uint32_t reg, uint8_t bit);
void print_binary(uint32_t reg);

int main(void) {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    // Початкове значення (біт 9 і біт 24 вже встановлені в 1 для наочності)
    uint32_t gpio_reg = (1U << 9) | (1U << 24) | 0x000000A0U;

    printf("Початковий стан регістра:\n");
    print_binary(gpio_reg);

    // 1. Встановити біт 2
    printf("\n1. Встановлення біта 2 (set_bit):\n");
    gpio_reg = set_bit(gpio_reg, 2);
    print_binary(gpio_reg);

    // 2. Скинути біт 9
    printf("\n2. Скидання біта 9 (clear_bit):\n");
    gpio_reg = clear_bit(gpio_reg, 9);
    print_binary(gpio_reg);

    // 3. Інвертувати біт 16
    printf("\n3. Інвертування біта 16 (toggle_bit):\n");
    gpio_reg = toggle_bit(gpio_reg, 16);
    print_binary(gpio_reg);

    // 4. Перевірити стан біта 24
    printf("\n4. Перевірка стану біта 24 (check_bit): %d\n", check_bit(gpio_reg, 24));

    printf("\nНатисніть Enter для виходу...");
    getchar();
    return 0;
}

uint32_t set_bit(uint32_t reg, uint8_t bit) {
    return reg | (1U << bit);
}

uint32_t clear_bit(uint32_t reg, uint8_t bit) {
    return reg & ~(1U << bit);
}

uint32_t toggle_bit(uint32_t reg, uint8_t bit) {
    return reg ^ (1U << bit);
}

int check_bit(uint32_t reg, uint8_t bit) {
    return (reg & (1U << bit)) ? 1 : 0;
}

void print_binary(uint32_t reg) {
    for (int i = 31; i >= 0; i--) {
        printf("%u", (reg >> i) & 1U);
        if (i % 4 == 0 && i != 0) {
            printf(" ");
        }
    }
    printf(" (HEX: 0x%08X)\n", reg);
}
