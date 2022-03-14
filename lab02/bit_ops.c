#include <stdio.h>
#include "bit_ops.h"

/* Returns the Nth bit of X. Assumes 0 <= N <= 31. */
unsigned get_bit(unsigned x, unsigned n) {
    /* YOUR CODE HERE */
<<<<<<< HEAD
    return (x&(0x01<<n))>>n; /* UPDATE WITH THE CORRECT RETURN VALUE*/
=======
    return -1; /* UPDATE WITH THE CORRECT RETURN VALUE*/
>>>>>>> 53eff2a7a7e0c86848ac8fa2491e484767dec1ba
}

/* Set the nth bit of the value of x to v. Assumes 0 <= N <= 31, and V is 0 or 1 */
void set_bit(unsigned *x, unsigned n, unsigned v) {
    /* YOUR CODE HERE */
<<<<<<< HEAD
    *x=((*x)&(~(1<<n)))|(v<<n);
=======
>>>>>>> 53eff2a7a7e0c86848ac8fa2491e484767dec1ba
}

/* Flips the Nth bit in X. Assumes 0 <= N <= 31.*/
void flip_bit(unsigned *x, unsigned n) {
    /* YOUR CODE HERE */
<<<<<<< HEAD
    *x=(*x)^(1<<n);
=======
>>>>>>> 53eff2a7a7e0c86848ac8fa2491e484767dec1ba
}

