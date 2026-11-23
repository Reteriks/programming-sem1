#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdint.h>

uint32_t pack_time(uint8_t sec, uint8_t min, uint8_t hour, uint8_t dst);
void unpack_time(uint32_t packet, uint8_t *sec, uint8_t *min, uint8_t *hour, uint8_t *dst);

int main(void) {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    uint8_t sec = 45;
    uint8_t min = 38;
    uint8_t hour = 19;
    uint8_t dst = 1;

    printf("Вхідні параметри:\n");
    printf("Час: %02u:%02u:%02u | Літній час (DST): %u\n", hour, min, sec, dst);

    uint32_t packed = pack_time(sec, min, hour, dst);
    printf("\nЗапаковане 32-бітне слово -> HEX: 0x%08X (DEC: %u)\n", packed, packed);

    uint8_t u_sec, u_min, u_hour, u_dst;
    unpack_time(packed, &u_sec, &u_min, &u_hour, &u_dst);

    printf("\nВідновлені після розпакування параметри:\n");
    printf("Час: %02u:%02u:%02u | Літній час (DST): %u\n", u_hour, u_min, u_sec, u_dst);

    printf("\nНатисніть Enter для виходу...");
    getchar();
    return 0;
}

uint32_t pack_time(uint8_t sec, uint8_t min, uint8_t hour, uint8_t dst) {
    uint32_t word = 0;
    word |= ((uint32_t)(sec & 0x3F) << 0);   // [Біти 0..5] Секунди (0..59)
    word |= ((uint32_t)(min & 0x3F) << 6);   // [Біти 6..11] Хвилини (0..59)
    word |= ((uint32_t)(hour & 0x1F) << 12); // [Біти 12..16] Години (0..23)
    word |= ((uint32_t)(dst & 0x01) << 17);  // [Біт 17] Літній час (0..1)
    return word;
}

void unpack_time(uint32_t packet, uint8_t *sec, uint8_t *min, uint8_t *hour, uint8_t *dst) {
    *sec  = (uint8_t)((packet >> 0) & 0x3F);
    *min  = (uint8_t)((packet >> 6) & 0x3F);
    *hour = (uint8_t)((packet >> 12) & 0x1F);
    *dst  = (uint8_t)((packet >> 17) & 0x01);
}
