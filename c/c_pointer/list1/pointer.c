#include <stdio.h>

int main(void)
{
    int hoge = 5;
    int piyo = 10;
    int *hoge_p;
    
    /* $B$=$l$>$l$NJQ?t$N%"%I%l%9$rI=<($9$k(B */
    printf("&hoge..%p\n", &hoge);
    printf("&piyo..%p\n", &piyo);
    printf("&hoge_p..%p\n", &hoge_p);

    /* $B%]%$%s%?JQ?t(Bhoge_p$B$K(Bhoge$B$N%"%I%l%9$rBeF~$9$k(B */
    hoge_p = &hoge;
    printf("hoge_p..%p\n", hoge_p);

    /* hoge_p$B$r7PM3$7$F(Bhoge$B$NFbMF$rI=<($9$k(B */
    printf("*hoge_p..%d\n", *hoge_p);

    /* hoge_p$B$r7PM3$7$F(Bhoge$B$NFbMF$rJQ99$9$k(B */
    *hoge_p = 10;
    printf("hoge_p..%d\n", hoge);

    return 0;
}
