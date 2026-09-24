#include <stdint.h>
#include <stdio.h>

/* Generates a mask with a single '1' at the specified bit position */
#define BIT_MASK(bit)            (1UL << (bit))

/* Sets the specified bit to '1' */
#define SET_BIT(reg, bit)        ((reg) |= BIT_MASK(bit))

/* Clears the specified bit to '0' */
#define CLEAR_BIT(reg, bit)      ((reg) &= ~BIT_MASK(bit))

/* Toggles the specified bit */
#define TOGGLE_BIT(reg, bit)     ((reg) ^= BIT_MASK(bit))

/* Reads the specified bit: returns 0 or 1 */
#define READ_BIT(reg, bit)       (((reg) >> (bit)) & 1UL)

/* Checks the specified bit: returns 0 or the mask value */
#define CHECK_BIT(reg, bit)      ((reg) & BIT_MASK(bit))

/* Sets the bit for any nonzero val; clears it for zero */
#define WRITE_BIT(reg, bit, val) \
    ((reg) = ((reg) & ~BIT_MASK(bit)) | \
             ((val) ? BIT_MASK(bit) : 0UL))

int main(void)
{
    uint32_t reg = 0;

    /* Bit positions start at 0 from the right */
    printf("Initial register : 0x%08lX\n", (unsigned long)reg);

    /* Generate mask for bit 3: 00001000 */
    printf("BIT_MASK(3)      : 0x%08lX\n", BIT_MASK(3));

    /* Set bit 3: 00000000 -> 00001000 */
    SET_BIT(reg, 3);
    printf("SET_BIT(3)       : 0x%08lX\n", (unsigned long)reg);

    /* Set bit 1: 00001000 -> 00001010 */
    SET_BIT(reg, 1);
    printf("SET_BIT(1)       : 0x%08lX\n", (unsigned long)reg);

    /* Clear bit 3: 00001010 -> 00000010 */
    CLEAR_BIT(reg, 3);
    printf("CLEAR_BIT(3)     : 0x%08lX\n", (unsigned long)reg);

    /* Toggle bit 2: 00000010 -> 00000110 */
    TOGGLE_BIT(reg, 2);
    printf("TOGGLE_BIT(2)    : 0x%08lX\n", (unsigned long)reg);

    /* Read bit 2: returns 1 */
    printf("READ_BIT(2)      : %lu\n", READ_BIT(reg, 2));

    /* Read bit 3: returns 0 */
    printf("READ_BIT(3)      : %lu\n", READ_BIT(reg, 3));

    /* Check bit 2: returns its mask, 4 */
    printf("CHECK_BIT(2)     : %lu\n", CHECK_BIT(reg, 2));

    if (CHECK_BIT(reg, 2)) {
        printf("Bit 2 is set\n");
    }

    /* Write 1 to bit 7: 00000110 -> 10000110 */
    WRITE_BIT(reg, 7, 1);
    printf("WRITE_BIT(7, 1)  : 0x%08lX\n", (unsigned long)reg);

    /* Write 0 to bit 1: 10000110 -> 10000100 */
    WRITE_BIT(reg, 1, 0);
    printf("WRITE_BIT(1, 0)  : 0x%08lX\n", (unsigned long)reg);

    return 0;
}



//points to keep in mind
/*

int val = 255;
printf("%x\n", val);   // Output: ff
printf("%X\n", val);   // Output: FF
printf("%#x\n", val);  // Output: 0xff
printf("%04X\n", val); // Output: 00FF
*/

