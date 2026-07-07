#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/flash.h"

int main() {
    stdio_init_all();
    
    // Tablica na ID pamięci Flash
    uint8_t id[8];
    
    while (true) {
        // Czytamy sprzętowe ID kości Flash bezpośrednio przez ROM-bootloader
        flash_get_unique_id(id);
        
        printf("\n=== DIAGNOSTYKA PAMIECI FLASH ===\n");
        printf("Surowe ID kości: %02X %02X %02X %02X %02X %02X %02X %02X\n", 
               id[0], id[1], id[2], id[3], id[4], id[5], id[6], id[7]);
        
        // Winbond koduje pojemność w 5. bajcie (index 4)
        if (id[4] == 0x15) {
            printf("Wykryty rozmiar: 2 MB (2048 KiB) - Klon jest w 100%% oryginalny!\n");
        } else if (id[4] == 0x14) {
            printf("Wykryty rozmiar: 1 MB (1024 KiB) - Cała partia ma mniejszy Flash.\n");
        } else {
            printf("Nieznany kod pojemności: 0x%02X\n", id[4]);
        }
        
        sleep_ms(2000);
    }
    return 0;
}
