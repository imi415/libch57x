#ifndef LIBCH57X_PWM_H
#define LIBCH57X_PWM_H

#include "libch57x_def.h"

typedef enum {
    LIBCH57x_PWM_CYC_MODE_8B = 0U,
    LIBCH57x_PWM_CYC_MODE_7B = 1U,
    LIBCH57x_PWM_CYC_MODE_6B = 2U,
    LIBCH57x_PWM_CYC_MODE_5B = 3U,
} libch57x_pwm_cyc_mode_t;

typedef enum {
    LIBCH57x_PWM_STAG_0_1 = (1U << 0),
    LIBCH57x_PWM_STAG_2_3 = (1U << 1),
    LIBCH57x_PWM_STAG_4_5 = (1U << 2),
    LIBCH57x_PWM_STAG_6_7 = (1U << 3),
} libch57x_pwm_stag_t;

typedef enum {
    LIBCH57x_PWM_CYCLE_SEL_ADD1 = 0U,
    LIBCH57x_PWM_CYCLE_SEL_NORM = 1U,
} libch57x_pwm_cycle_sel_t;

typedef struct {
    libch57x_pwm_stag_t     stag_en;
    libch57x_pwm_cyc_mode_t cyc_mode;
    libch57x_pwm_cycle_sel_t cyc_sel;
} libch57x_pwm_config_t;

void libch57x_pwm_config(PWM_Type *base, libch57x_pwm_config_t *config);
void libch57x_pwm_duty(PWM_Type *base, uint8_t mask, uint8_t value);

static inline void libch57x_pwm_clock_div(PWM_Type *base, uint8_t div) {
    base->CLOCK_DIV = div;
}

static inline void libch57x_pwm_enable(PWM_Type *base, uint8_t mask, bool enabled) {
    if (enabled) {
        base->OUT_EN |= mask;
    } else {
        base->OUT_EN &= ~mask;
    }
}

static inline void libch57x_pwm_polarity(PWM_Type *base, uint8_t mask, bool active_high) {
    if (active_high) {
        base->POLAR &= ~mask;
    } else {
        base->POLAR |= mask;
    }
}


#endif  // LIBCH57X_PWM_H
