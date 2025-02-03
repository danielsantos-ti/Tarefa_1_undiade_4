#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/interp.h"// Defina os pinos para os LEDs e botões

#define BUTTON_A_PIN 5
#define BUTTON_B_PIN 6
#define LED_RGB_RED_PIN 11
#define LED_RGB_GREEN_PIN 12
#define LED_RGB_BLUE_PIN 13
#define WS2812_PIN 7

volatile int count = 0; // Contador que será exibido na matriz

// Função de debouncing para botão
bool debounce(uint gpio) {
    static uint32_t last_interrupt_time = 0;
    uint32_t current_time = time_us_32();

    // Verifica se o tempo de debounce foi atingido
    if (current_time - last_interrupt_time > 200000) { // 200ms
        last_interrupt_time = current_time;
        return true;
    }
    return false;
}

// ISR para o Botão A
void button_a_isr(uint gpio, uint32_t events) {
    if (debounce(gpio)) {
        count++;
    }
}

// ISR para o Botão B
void button_b_isr(uint gpio, uint32_t events) {
    if (debounce(gpio)) {
        count--;
    }
}

// Função para piscar o LED vermelho
void blink_red_led() {
    gpio_put(LED_RGB_RED_PIN, 1);
    sleep_ms(100);
    gpio_put(LED_RGB_RED_PIN, 0);
    sleep_ms(100);
}

int main() {
    stdio_init_all();

    // Inicializando os LEDs RGB
    gpio_init(LED_RGB_RED_PIN);
    gpio_set_dir(LED_RGB_RED_PIN, GPIO_OUT);

    gpio_init(LED_RGB_GREEN_PIN);
    gpio_set_dir(LED_RGB_GREEN_PIN, GPIO_OUT);

    gpio_init(LED_RGB_BLUE_PIN);
    gpio_set_dir(LED_RGB_BLUE_PIN, GPIO_OUT);

    // Inicializando os botões com resistores pull-up internos
    gpio_init(BUTTON_A_PIN);
    gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_A_PIN);
    gpio_set_irq_enabled_with_callback(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true, button_a_isr);

    gpio_init(BUTTON_B_PIN);
    gpio_set_dir(BUTTON_B_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_B_PIN);
    gpio_set_irq_enabled_with_callback(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true, button_b_isr);

    while (true) {
        blink_red_led();

        // Aqui você pode adicionar a lógica para atualizar a matriz WS2812 com o número
        // exibido pela variável 'count'.
        // A matriz de LEDs WS2812 será controlada através de uma biblioteca apropriada.

        sleep_ms(100);  // Delay para a execução do programa
    }

    return 0;
}

