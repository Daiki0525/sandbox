#include <stdio.h>
#include <stdlib.h>

int global_variable;
static int file_static_variable;

void func1(void)
{
    int func1_variable;
    static int func1_static_variable;

    printf("&func1_variable..%p\n",&func1_variable);
    printf("&func1_static_variable..%p\n",&func1_static_variable);
}

void func2(void)
{
    int func2_variable;

    printf("&func2_variable..%p\n",&func2_variable);
}

int main(void)
{
    int *p;

    /* $B4X?t$X$N%]%$%s%?$NI=<((B */
    printf("&func1..%p\n",func1);
    printf("&func2..%p\n",func2);

    /* $BJ8;zNs%j%F%i%k$N%"%I%l%9$NI=<((B */
    printf("&global_variable..%p\n",&global_variable);

    /* $B%U%!%$%kFb(Bstatic$BJQ?t$N%"%I%l%9$NI=<((B */
    printf("&file_static_variable..%p\n",&file_static_variable);

    /* $B%m!<%+%kJQ?t$NI=<((B */
    func1();
    func2();

    /* malloc$B$K$h$j3NJ]$7$?NN0h$N%"%I%l%9(B */
    p = malloc(sizeof(int));
    printf("maloc address..%p\n",p);

    return 0;
}

