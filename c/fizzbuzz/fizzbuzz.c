#include<stdio.h>

int main(void){
    int ix;
    for(ix=1;ix<101;ix++){
        if(ix%3==0){
            printf("fizz");
        }
        if(ix%5==0){
            printf("buzz");
        }
        if(ix%3!=0 && ix%5!=0){
            printf("%d",ix);
        }
        printf("\n");
    }
    return 0;
}
