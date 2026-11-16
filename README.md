# Sirius128 Pseudo-Random Number Generator
Sirius128 is a ultra-fast, robust pseudo-random number generator (PRNG) designed for high-performance applications, simulations, and games. 

```C
typedef struct {
	uint64_t x;
	uint64_t y;
} sirius128_state_t;

uint64_t sirius128(sirius128_state_t *state)
{
	state->x += 0xf39cc0605cedc835ull;
	state->y += 0x9e3779b97f4a7c15ull + (state->x < 0xf39cc0605cedc835ull);
	uint64_t z = 0x9e3779b97f4a7c15ull * (state->y ^ (state->y >> 17));
	z = (z << 32) | (z >> 32);
	return 0x9e3779b97f4a7c15ull * (state->x ^ z ^ (z >> 17));
}
```

## Collision Count
Ten independent collision-counting runs were performed using different initial seeds. Exact collision counts were measured using **ColFinder**, an open-source tool developed specifically for large-scale PRNG collision analysis.

For **16 × 10^9** generated 64-bit values, the theoretical expected number of collisions is **6.94**. The observed average was **6.2** collisions, showing excellent agreement with the random-mapping model. Individual runs produced between 3 and 10 collisions, a range fully consistent with the expected Poisson distribution governing collision events in a 64-bit output space.

**Report directory:** [test_collision/](https://github.com/matteo65/Sirius128/tree/main/test_collision)  
**ColFinder repository:** [Colfinder](https://github.com/matteo65/colfinder)  

|#|  Seed x     |   Seed y      |# Collisions|
|--|------------|---------------|----|
|01|0           | 0             |5|
|02|1           | 1             |5|
|03|0xAAAAAAAAAAAAAAAA | 0xAAAAAAAAAAAAAAAA |7|
|04|0x5555555555555555 | 0x5555555555555555 |3|
|05|UINT64_MAX | UINT64_MAX |6|
|06|123456789  | 987654321  |6|
|07|0x0123456789ABCDEF | 0xFEDCBA9876543210 |8| 
|08|122333444455555 | 555554444333221 |9| 
|09|12812691690885789454 | 2513978961650573177 |3|
|10|135360732483323487 | 9243983136210913915 |10|
|  |                   |**AVERAGE**     |**6.2**|
