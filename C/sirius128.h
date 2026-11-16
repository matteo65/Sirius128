/*
 * sirius128.h 
 *
 * Sirius128 - Pseudo Random Number Generator 64 bit output, 128 bit state
 * 
 * Copyright(C) 2026 Matteo Zapparoli - zapparoli.matteo@gmail.com
 * 
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Minimalist implementation
 *
 */

#ifndef SIRIUS128_H
#define SIRIUS128_H

#include <stdint.h> // uint64_t

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	uint64_t x;
	uint64_t y;
} sirius128_state_t;

uint64_t sirius128(sirius128_state_t *state);

#ifdef __cplusplus
}
#endif

#endif /* SIRIUS128_H */