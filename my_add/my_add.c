#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
unsigned int my_add(unsigned int a, unsigned int b);
void display_binary(unsigned int num);

int main() {
    unsigned int a, b, sum;

    printf("Enter the first unsigned integer:\n");
    scanf("%u", &a);
    printf("Enter the second unsigned integer:\n");
    scanf("%u", &b);

    /* Display binary representation of a and b */
    printf("\nBinary representation of %u: ", a);
    display_binary(a);
    printf("\nBinary representation of %u: ", b);
    display_binary(b);

    /* Perform binary addition using my_add function */
    sum = my_add(a, b);

    /* Display sum in binary */
    printf("\n\nBinary representation of sum: ");
    display_binary(sum);

    /* Display sum in decimal */
    printf("\nSum: %u\n", sum);

    return 0;
}

/* Function to add two unsigned integers in binary representation */
unsigned int my_add(unsigned int a, unsigned int b) {
    unsigned int result = 0; 
    unsigned int carry = 0; 
    unsigned int mask = 1; 

    while (a || b || carry) {
        /* Extract the least significant bits of a, b, and carry */
        unsigned int bit_a = a & 1;
        unsigned int bit_b = b & 1;

        /* Calculate sum */
        unsigned int sum = bit_a ^ bit_b ^ carry;

        /* Update result using sum */
        result |= (sum * mask); 

        /* Calculate carry */
        carry = (bit_a & bit_b) | ((bit_a ^ bit_b) & carry);

        /* Move to the next bit position */
        mask <<= 1;

        /* Shift a and b to the right */
        a >>= 1;
        b >>= 1;
    }

    return result;
}

/* Function to display an unsigned integer in binary */
void display_binary(unsigned int num) {
    unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1); 
    int i;
    for (i = 0; i < sizeof(unsigned int) * 8; ++i) {
        if (num & mask)
            printf("1");
        else
            printf("0");
        mask >>= 1;
    }
}

