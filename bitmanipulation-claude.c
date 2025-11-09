#include <stdio.h>
#include <stdlib.h>

// ============== FOUNDATIONAL OPERATIONS ==============

// 1. Check if number is odd or even
int isOdd(int n) {
    return n & 1;  // If last bit is 1, number is odd
}

// 2. Check if nth bit is set (positions start from 0)
int isBitSet(int num, int n) {
    return (num & (1 << n)) != 0;
}

// 3. Set the nth bit
int setBit(int num, int n) {
    return num | (1 << n);
}

// 4. Clear the nth bit
int clearBit(int num, int n) {
    return num & ~(1 << n);
}

// 5. Toggle the nth bit
int toggleBit(int num, int n) {
    return num ^ (1 << n);
}

// 6. Count number of set bits (Brian Kernighan's Algorithm)
int countSetBits(int n) {tele
    int count = 0;
    while (n) {
        n = n & (n - 1);  // Removes rightmost set bit
        count++;
    }
    return count;
}

// 7. Find the rightmost set bit position
int rightmostSetBit(int n) {
    if (n == 0) return -1;
    return n & -n;  // Returns only the rightmost set bit
}

// 8. Clear the rightmost set bit
int clearRightmostSetBit(int n) {
    return n & (n - 1);
}

// ============== NUMBER PROPERTIES ==============

// 9. Check if number is power of 2
int isPowerOf2(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// 10. Find position of only set bit (returns -1 if multiple bits set)
int positionOfOnlySetBit(int n) {
    if (n == 0 || (n & (n - 1)) != 0) 
        return -1;  // Not exactly one bit set
    
    int pos = 0;
    while ((n & 1) == 0) {
        n >>= 1;
        pos++;
    }
    return pos;
}

// 11. Check if two numbers have opposite signs
int oppositeSign(int a, int b) {
    return (a ^ b) < 0;
}

// 12. Swap two numbers without temp variable
void swapNumbers(int *a, int *b) {
    if (a != b) {  // Check for same memory location
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

// ============== BIT COUNTING & POSITION ==============

// 13. Count total set bits from 1 to N
int countSetBitsUptoN(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        count += countSetBits(i);
    }
    return count;
}

// 14. Find position of leftmost set bit
int leftmostSetBit(int n) {
    if (n == 0) return -1;
    
    int pos = 0;
    while (n > 1) {
        n >>= 1;
        pos++;
    }
    return pos;
}

// 15. Position of rightmost different bit
int rightmostDifferentBit(int a, int b) {
    int xorVal = a ^ b;
    if (xorVal == 0) return -1;  // Numbers are same
    
    int pos = 0;
    while ((xorVal & 1) == 0) {
        xorVal >>= 1;
        pos++;
    }
    return pos;
}

// 16. Count bits to flip to convert A to B
int bitsToFlip(int a, int b) {
    return countSetBits(a ^ b);
}

// ============== INTERMEDIATE PROBLEMS ==============

// 17. Find two non-repeating elements (all others repeat twice)
void twoNonRepeating(int arr[], int n) {
    int xorAll = 0;
    
    // XOR all elements
    for (int i = 0; i < n; i++) {
        xorAll ^= arr[i];
    }
    
    // Find rightmost set bit
    int rightBit = xorAll & -xorAll;
    
    int x = 0, y = 0;
    // Divide elements into two groups
    for (int i = 0; i < n; i++) {
        if (arr[i] & rightBit)
            x ^= arr[i];
        else
            y ^= arr[i];
    }
    
    printf("Two non-repeating numbers: %d and %d\n", x, y);
}

// 18. Find only non-repeating element
int singleNumber(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    return result;
}

// 19. Generate all subsets using bit masking
void generateSubsets(int arr[], int n) {
    int totalSubsets = 1 << n;  // 2^n subsets
    
    printf("All subsets:\n");
    for (int i = 0; i < totalSubsets; i++) {
        printf("{ ");
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                printf("%d ", arr[j]);
            }
        }
        printf("}\n");
    }
}

// 20. Reverse bits of a number (32-bit)
unsigned int reverseBits(unsigned int n) {
    unsigned int result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}

// 21. Rotate bits left
unsigned int rotateLeft(unsigned int n, int d) {
    return (n << d) | (n >> (32 - d));
}

// 22. Rotate bits right
unsigned int rotateRight(unsigned int n, int d) {
    return (n >> d) | (n << (32 - d));
}

// 23. Check if number has alternating bits
int hasAlternatingBits(int n) {
    int prev = n & 1;
    n >>= 1;
    
    while (n > 0) {
        int curr = n & 1;
        if (curr == prev)
            return 0;
        prev = curr;
        n >>= 1;
    }
    return 1;
}

// 24. Find XOR from 1 to N (optimized)
int xorFrom1ToN(int n) {
    int mod = n % 4;
    if (mod == 0) return n;
    if (mod == 1) return 1;
    if (mod == 2) return n + 1;
    return 0;
}

// ============== OPTIMIZATION TECHNIQUES ==============

// 25. Multiply by power of 2
int multiplyByPowerOf2(int n, int k) {
    return n << k;  // Multiply by 2^k
}

// 26. Divide by power of 2
int divideByPowerOf2(int n, int k) {
    return n >> k;  // Divide by 2^k
}

// 27. Check if divisible by power of 2
int isDivisibleByPowerOf2(int n, int k) {
    int divisor = 1 << k;  // 2^k
    return (n & (divisor - 1)) == 0;
}

// 28. Find next power of 2
unsigned int nextPowerOf2(unsigned int n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}

// ============== MAIN FUNCTION WITH EXAMPLES ==============

int main() {
    printf("========== BIT MANIPULATION EXAMPLES ==========\n\n");
    
    // 1. Odd/Even
    printf("1. Is 7 odd? %s\n", isOdd(7) ? "Yes" : "No");
    
    // 2. Check bit
    printf("2. Is 2nd bit of 5 set? %s\n", isBitSet(5, 2) ? "Yes" : "No");
    
    // 3. Set bit
    printf("3. Set 1st bit of 5: %d\n", setBit(5, 1));
    
    // 4. Clear bit
    printf("4. Clear 0th bit of 5: %d\n", clearBit(5, 0));
    
    // 5. Toggle bit
    printf("5. Toggle 1st bit of 5: %d\n", toggleBit(5, 1));
    
    // 6. Count set bits
    printf("6. Set bits in 15: %d\n", countSetBits(15));
    
    // 7. Rightmost set bit
    printf("7. Rightmost set bit of 12: %d\n", rightmostSetBit(12));
    
    // 8. Clear rightmost set bit
    printf("8. Clear rightmost set bit of 12: %d\n", clearRightmostSetBit(12));
    
    // 9. Power of 2
    printf("9. Is 16 power of 2? %s\n", isPowerOf2(16) ? "Yes" : "No");
    
    // 10. Position of only set bit
    printf("10. Position of only set bit in 8: %d\n", positionOfOnlySetBit(8));
    
    // 11. Opposite signs
    printf("11. Do 5 and -3 have opposite signs? %s\n", oppositeSign(5, -3) ? "Yes" : "No");
    
    // 12. Swap numbers
    int x = 10, y = 20;
    printf("12. Before swap: x=%d, y=%d\n", x, y);
    swapNumbers(&x, &y);
    printf("    After swap: x=%d, y=%d\n", x, y);
    
    // 13. Count set bits up to N
    printf("13. Total set bits from 1 to 5: %d\n", countSetBitsUptoN(5));
    
    // 14. Leftmost set bit
    printf("14. Leftmost set bit position in 12: %d\n", leftmostSetBit(12));
    
    // 15. Rightmost different bit
    printf("15. Rightmost different bit position (5,7): %d\n", rightmostDifferentBit(5, 7));
    
    // 16. Bits to flip
    printf("16. Bits to flip to convert 10 to 20: %d\n", bitsToFlip(10, 20));
    
    // 17. Two non-repeating elements
    printf("17. ");
    int arr1[] = {2, 3, 7, 9, 11, 2, 3, 11};
    twoNonRepeating(arr1, 8);
    
    // 18. Single number
    int arr2[] = {2, 3, 5, 3, 2};
    printf("18. Single non-repeating number: %d\n", singleNumber(arr2, 5));
    
    // 19. Generate subsets
    printf("19. ");
    int arr3[] = {1, 2, 3};
    generateSubsets(arr3, 3);
    
    // 20. Reverse bits
    printf("20. Reverse bits of 5: %u\n", reverseBits(5));
    
    // 21-22. Rotate bits
    printf("21. Rotate 8 left by 2: %u\n", rotateLeft(8, 2));
    printf("22. Rotate 8 right by 2: %u\n", rotateRight(8, 2));
    
    // 23. Alternating bits
    printf("23. Does 5 have alternating bits? %s\n", hasAlternatingBits(5) ? "Yes" : "No");
    
    // 24. XOR from 1 to N
    printf("24. XOR from 1 to 7: %d\n", xorFrom1ToN(7));
    
    // 25-26. Multiply/Divide
    printf("25. 5 * 2^3 = %d\n", multiplyByPowerOf2(5, 3));
    printf("26. 20 / 2^2 = %d\n", divideByPowerOf2(20, 2));
    
    // 27. Divisible by power of 2
    printf("27. Is 16 divisible by 2^2? %s\n", isDivisibleByPowerOf2(16, 2) ? "Yes" : "No");
    
    // 28. Next power of 2
    printf("28. Next power of 2 after 10: %u\n", nextPowerOf2(10));
    
    return 0;
}