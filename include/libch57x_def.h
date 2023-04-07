#ifndef LIBCH57X_DEF_H
#define LIBCH57X_DEF_H

#ifdef __cpluscplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "ch57x.h"

typedef enum {
    CH57X_OK,
    CH57X_FAIL,
} libch57x_ret_t;

#ifdef __cplusplus
}
#endif
#endif