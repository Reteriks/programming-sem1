#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdint.h>

void configure_register(uint32_t *reg);
int check_status_flag(const uint32_t *reg, uint8_t bit_pos);

int main(void) {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    uint32_t peripheral_reg = (1U << 9) | (1U << 17) | (1U << 25);

    printf("До модифікації:    0x%08X\n", peripheral_reg);
    configure_register(&peripheral_reg);
    printf("Після модифікації: 0x%08X\n", peripheral_reg);

    int status = check_status_flag(&peripheral_reg, 17);
    printf("Стан статусного біта 17: %d\n", status);

    printf("\nНатисніть Enter для виходу...");
    getchar();
    return 0;
}

void configure_register(uint32_t *reg) {
    if (reg == NULL) {
        return;
    }
    *reg |= (1U << 1);   // Встановити в 1 біт 1
    *reg &= ~(1U << 9);  // Скинути в 0 біт 9
    *reg ^= (1U << 25);  // Інвертувати біт 25
}

int check_status_flag(const uint32_t *reg, uint8_t bit_pos) {
    if (reg == NULL || bit_pos > 31) {
        return 0;
    }
    return (*reg & (1U << bit_pos)) ? 1 : 0;
}
