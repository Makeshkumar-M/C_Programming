#include <stdio.h>

// Utility function to print binary representation of a number
void printBinary(int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 8 == 0) printf(" ");  // Space after every 8 bits
    }
    printf("\n");
}

int main() {
    int num = 42;  // Example number to work with

    printf("Basic Bit Operations for num = %d\n", num);
    printf("Binary representation: ");
    printBinary(num);

    // 1. Check if a number is even or odd
    printf("\n1. Is number even? %s\n", (num & 1) ? "No" : "Yes");

    // 2. Get bit at position i
    int pos = 3;
    int getBit = (num >> pos) & 1;
    printf("\n2. Bit at position %d is: %d\n", pos, getBit);

    // 3. Set bit at position i
    int setBit = num | (1 << pos);
    printf("\n3. After setting bit at position %d:\n", pos);
    printf("Original: "); printBinary(num);
    printf("Modified: "); printBinary(setBit);

    // 4. Clear bit at position i
    int clearBit = num & ~(1 << pos);
    printf("\n4. After clearing bit at position %d:\n", pos);
    printf("Original: "); printBinary(num);
    printf("Modified: "); printBinary(clearBit);

    // 5. Toggle bit at position i
    int toggleBit = num ^ (1 << pos);
    printf("\n5. After toggling bit at position %d:\n", pos);
    printf("Original: "); printBinary(num);
    printf("Modified: "); printBinary(toggleBit);

    // 6. Count set bits (Brian Kernighan's Algorithm)
    int count = 0;
    int temp = num;
    while (temp) {
        temp &= (temp - 1);
        count++;
    }
    printf("\n6. Number of set bits: %d\n", count);

    // 7. Check if number is power of 2
    printf("\n7. Is number power of 2? %s\n", 
           (num & (num - 1)) == 0 ? "Yes" : "No");

    // 8. Find rightmost set bit
    int rightmostSetBit = num & -num;
    printf("\n8. Rightmost set bit position: ");
    printBinary(rightmostSetBit);

    return 0;
}