#include <stdio.h>

int main(int argc, char* argv[]) {

    long x = 444444441;
    long y;
    
    long s = 2;
    long t;
    long l;

    asm("movq %0, %%r9"
                            :
                            : "r" (s)
                            : "r9");
 

    asm("movq %1, %%r9\n\t"
        "movq %%r9, %0\n\t"
                                : "=r" (y)
                                : "r" (x)
                                : "r9");    


    l = printf("r9 held %ld\n", y);

    asm("movq %%rax, %0"
                            : "=r" (t));

    printf("rax held %ld\n", t);
    printf("l = %ld\n", l);
    return 0;

}
