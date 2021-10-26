/**
 * @file ch57x.h
 * @author imi415 (imi415.public@gmail.com)
 * @brief CMSIS CH57x Device Peripheral Access Layer Header File
 * @version 0.1
 * @date 2021-10-27
 * 
 * @copyright Copyright (c) 2021 imi415
 * 
 */

#ifndef CH57X_H
#define CH57X_H

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(DEVICE_CH579) && !defined(DEVICE_CH578) && !defined(DEVICE_CH577)
#error "Please define DEVICE_CH577/8/9 according to the actual device."
#endif

#if defined(DEVICE_CH579)
#include "ch579.h"
#endif

#ifdef __cplusplus
}
#endif

#endif // CH57X_H