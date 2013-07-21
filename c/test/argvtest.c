#include<stdio.h>

int main(int argc, char *argv[])
{
    int ix;

    for(ix=1; ix < argc; ix++)
    {
        printf("%s ",argv[ix]);
    }
    printf("\n");

    return 0;
}
