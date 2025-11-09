#include <stdio.h>

void sumofdigit(int num);

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    sumofdigit(num);
    return 0;
}

void sumofdigit(int num){
    int sum = 0;
    while(num != 0){
        sum += num % 10;
        num /= 10;
    }
    printf("The sum of digits is %d\n", sum);
}