//call back function

#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int process(int x, int y, int(*fpointer)(int, int)) {
    return fpointer(x, y);  // Now returns the result
}

int main() {
    int sum_val;
    int sub_val;
    
    sum_val = process(10, 5, sum);   // Correct: 3 args, sum function pointer
    sub_val = process(10, 5, sub);   // Correct: 3 args, sub function pointer
    
    printf("The sum value: %d\n", sum_val);
    printf("The sub value: %d\n", sub_val);
    
    return 0;
}