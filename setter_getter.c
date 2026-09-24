#include <stdio.h>
#include <stdint.h>

static uint16_t value = 0;

void setfunction(uint16_t inputval)
{
    value = inputval;
}

uint16_t getfunction(void)
{
    return value;
}

int main(void)
{
    uint16_t output;

    setfunction(8);
    output = getfunction();

    printf("value of the get function: %d\n", output);
    return 0;
}