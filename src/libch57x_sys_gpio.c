#include "libch57x_sys_gpio.h"

libch57x_ret_t libch57x_gpio_config(libch57x_gpio_config_t *config) {
    uint32_t reg_dir, reg_pu, reg_pd_drv;

    uint32_t pin_mask = config->pin_mask;

    if (config->bank == LIBCH57X_GPIO_BANK_A) {
        reg_dir    = SYS->R32_PA_DIR;
        reg_pu     = SYS->R32_PA_PU;
        reg_pd_drv = SYS->R32_PA_PD_DRV;
    } else if (config->bank == LIBCH57X_GPIO_BANK_B) {
        reg_dir    = SYS->R32_PB_DIR;
        reg_pu     = SYS->R32_PB_PU;
        reg_pd_drv = SYS->R32_PB_PD_DRV;
    } else {
        return CH57X_FAIL;
    }

    reg_dir &= ~pin_mask;
    reg_pu &= ~pin_mask;
    reg_pd_drv &= ~pin_mask;

    switch (config->mode) {
        case LIBCH57X_GPIO_MODE_INPUT_PULLUP:
            reg_pu |= pin_mask;
            break;
        case LIBCH57X_GPIO_MODE_INPUT_PULLDOWN:
            reg_pd_drv |= pin_mask;
            break;
        case LIBCH57X_GPIO_MODE_OUTPUT_5MA:
            reg_dir |= pin_mask;
        case LIBCH57X_GPIO_MODE_OUTPUT_20MA:
            reg_dir |= pin_mask;
            reg_pd_drv |= pin_mask;
            break;
        case LIBCH57X_GPIO_MODE_INPUT_FLOAT:
        default:
            break;
    }

    if (config->bank == LIBCH57X_GPIO_BANK_A) {
        SYS->R32_PA_DIR    = reg_dir;
        SYS->R32_PA_PU     = reg_pu;
        SYS->R32_PA_PD_DRV = reg_pd_drv;
    } else {
        SYS->R32_PB_DIR    = reg_dir;
        SYS->R32_PB_PU     = reg_pu;
        SYS->R32_PB_PD_DRV = reg_pd_drv;
    }

    return CH57X_OK;
}

libch57x_ret_t libch57x_gpio_pin_write(libch57x_gpio_bank_t bank, uint8_t pin, uint32_t value) {
    if (bank == LIBCH57X_GPIO_BANK_A) {
        if (value) {
            SYS->R32_PA_OUT |= (1 << pin);
        } else {
            SYS->R32_PA_CLR |= (1 << pin);
        }
    } else if (bank == LIBCH57X_GPIO_BANK_B) {
        if (value) {
            SYS->R32_PB_OUT__R8_SLV_RD_DATA |= (1 << pin);
        } else {
            SYS->R32_PB_CLR |= (1 << pin);
        }
    } else {
        return CH57X_FAIL;
    }

    return CH57X_OK;
}

uint32_t libch57x_gpio_pin_read(libch57x_gpio_bank_t bank, uint8_t pin) {
    if (bank == LIBCH57X_GPIO_BANK_A) {
        return (SYS->R32_PA_PIN & (1 << pin)) ? 1 : 0;
    } else if (bank == LIBCH57X_GPIO_BANK_B) {
        return (SYS->R32_PB_PIN & (1 << pin)) ? 1 : 0;
    } else {
        return 0;
    }
}

libch57x_ret_t libch57x_gpio_pin_toggle(libch57x_gpio_bank_t bank, uint8_t pin) {
    if (bank == LIBCH57X_GPIO_BANK_A) {
        SYS->R32_PA_OUT ^= (1 << pin);
    } else if (bank == LIBCH57X_GPIO_BANK_B) {
        SYS->R32_PB_OUT__R8_SLV_RD_DATA ^= (1 << pin);
    } else {
        return CH57X_FAIL;
    }

    return CH57X_OK;
}