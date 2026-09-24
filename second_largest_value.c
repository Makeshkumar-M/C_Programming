// code to find the second largest element in the array

#include <stdio.h>
#include <limits.h>

int findSecondLargest(int arr[], int n) {
    if (n < 2) {
        printf("Array must have at least 2 elements\n");
        return -1;
    }
    
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    
    if (secondLargest == INT_MIN) {
        printf("No valid second largest found\n");
        return -1;
    }
    
    return secondLargest;
}

int main() {
    int arr[] = {10, 5, 20, 8, 15, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = findSecondLargest(arr, n);
    
    if (result != -1) {
        printf("Second Largest: %d\n", result);
    }
    
    return 0;
}



/*


Single pass logic:

Track two variables: largest and secondLargest
If current element > largest: shift largest to secondLargest, update largest
Else if current element > secondLargest and not equal to largest: update secondLargest

Time: O(n) | Space: O(1)


What #include <limits.h> Does

The limits.h header file defines constants for integer limits on your system.

In This Code

We use INT_MIN (the smallest integer value) to initialize our tracking variables:

c
int largest = INT_MIN;
int secondLargest = INT_MIN;



Common Limit Constants in limits.h
Constant	Value (typical)	Use

INT_MIN	-2147483648	Initialize for "find max"
INT_MAX	2147483647	Initialize for "find min"
CHAR_MIN, CHAR_MAX	-128, 127	Character range
LONG_MIN, LONG_MAX	System-dependent	Long integers
*/