#ifndef LIBCH57X_SYSAUX_GPIO_H
#define LIBCH57X_SYSAUX_GPIO_H

#include "libch57x_def.h"

typedef enum {
    LIBCH57X_GPIO_BANK_A,
    LIBCH57X_GPIO_BANK_B,
} libch57x_gpio_bank_t;

typedef enum {
    LIBCH57X_GPIO_MODE_INPUT_FLOAT,
    LIBCH57X_GPIO_MODE_INPUT_PULLUP,
    LIBCH57X_GPIO_MODE_INPUT_PULLDOWN,
    LIBCH57X_GPIO_MODE_OUTPUT_5MA,
    LIBCH57X_GPIO_MODE_OUTPUT_20MA,
} libch57x_gpio_mode_t;

typedef enum {
    LIBCH57X_GPIO_INTR_DISABLE,
    LIBCH57X_GPIO_INTR_RISING,
    LIBCH57X_GPIO_INTR_FALLING,
    LIBCH57X_GPIO_INTR_HIGH,
    LIBCH57X_GPIO_INTR_LOW,
} libch57x_gpio_intr_t;

typedef struct {
    libch57x_gpio_bank_t bank;
    uint32_t             pin_mask;
    libch57x_gpio_mode_t mode;
    libch57x_gpio_intr_t intr;
} libch57x_gpio_config_t;

libch57x_ret_t libch57x_gpio_config(libch57x_gpio_config_t *config);
libch57x_ret_t libch57x_gpio_pin_write(libch57x_gpio_bank_t bank, uint8_t pin, uint32_t value);
uint32_t       libch57x_gpio_pin_read(libch57x_gpio_bank_t bank, uint8_t pin);
libch57x_ret_t libch57x_gpio_pin_toggle(libch57x_gpio_bank_t bank, uint8_t pin);

#endif