/*
 * Function Name: fibonacci
 * Explanation:
 *   Print the first `j` terms of the Fibonacci sequence to stdout.
 *   This is a basic, easy-to-read iterative implementation using `int`.
 *
 * Inputs:
 *   j - number of terms to print (int)
 *
 * Outputs:
 *   Prints the sequence as space-separated numbers followed by a newline.
 */

#include <stdio.h>

void fibonacci(int j) {
    int a = 0, b = 1, next, i;

    if (j <= 0) {
        printf("No terms to print.\n");
        return;
    }

    printf("Fibonacci series for %d terms:\n", j);
    for (i = 1; i <= j; ++i) {
        printf("%d", a);
        if (i < j) {
            printf(" ");
        }
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

/*
 * Function Name: main
 * Explanation:
 *   Prompt the user to enter the number of terms (N). If input fails, default to 10.
 *   Calls `fibonacci(N)` to print the sequence.
 */
int main(void) {
    int n = 10; /* default */

    printf("Enter number of Fibonacci terms (press enter for default 10): ");
    if (scanf("%d", &n) != 1) {
        n = 10; /* use default if user input is invalid */
    }

    fibonacci(n);
    return 0; /* success */
}


