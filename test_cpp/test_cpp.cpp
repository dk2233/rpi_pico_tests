#include <pico/time.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/stdio.h"
//#include "pico/stdio_usb.h"

#define LED_PIN PICO_DEFAULT_LED_PIN   
int main()
{
    gpio_init(LED_PIN);
    
    // 2. Ustawienie kierunku pinu jako WYJŚCIE
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_put(LED_PIN, 1);
    sleep_ms(200);
    gpio_put(LED_PIN, 0);


    stdio_init_all();

    /**/
    while (!stdio_usb_connected()) {
        sleep_ms(50);
    }
    
    gpio_put(LED_PIN, 1);

    while (true) {
        printf("Hello, worldx2!\n");
        //fflush(stdout);
        sleep_ms(1000);
    }
}
