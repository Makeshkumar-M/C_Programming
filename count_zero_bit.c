//Code to code how many zero bit in the number
#include<stdio.h>
#include<inttypes.h>


int main(){
uint16_t value= 0x6;
uint16_t count =0;
for(uint16_t i=0; i <32; i++){
    if((value&(1UL<<i))==0){
        count++;
    }
}
printf("The number of 1:%d",count);
}