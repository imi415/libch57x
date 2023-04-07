#include "libch57x_pwm.h"

void libch57x_pwm_config(PWM_Type *base, libch57x_pwm_config_t *config) {
    uint8_t new_config = 0U;

    new_config |= (config->cyc_mode << PWM_CONFIG_PWM_CYC_MOD_Pos) & PWM_CONFIG_PWM_CYC_MOD_Msk;
    new_config |= (config->cyc_sel << PWM_CONFIG_PWM_CYCLE_SEL_Pos) & PWM_CONFIG_PWM_CYCLE_SEL_Msk;
    new_config |= (config->stag_en << PWM_CONFIG_PWM4_5_STAG_EN_Pos);

    base->CONFIG = new_config;
}

void libch57x_pwm_duty(PWM_Type *base, uint8_t mask, uint8_t value) {
    for (uint8_t i = 0; i < 7; i++) {
        if (mask & (1 << i)) {
            base->DATA[i] = value;
        }
    }
}