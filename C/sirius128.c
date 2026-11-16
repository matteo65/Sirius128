/*
 * sirius128.c
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

#include "sirius128.h"

uint64_t sirius128(sirius128_state_t *state)
{
	state->x += 0xf39cc0605cedc835ull;
	state->y += 0x9e3779b97f4a7c15ull + (state->x < 0xf39cc0605cedc835ull);
	uint64_t z = 0x9e3779b97f4a7c15ull * (state->y ^ (state->y >> 17));
	z = (z << 32) | (z >> 32);
	return 0x9e3779b97f4a7c15ull * (state->x ^ z ^ (z >> 17));
}