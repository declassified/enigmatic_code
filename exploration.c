#include <stdio.h>
#include <stdlib.h>

int add(int x, int y);
int multiply(int x, int y);
int return_input(int x);

int main(int argc, char* argv[]) {

    

    int x;
    int w = 42;
    static int z = 99;
    static int y;

    unsigned u = -3;

    char a = 'a';
    char b = 'b';
    char c, d;

    const short s = 2;

    char* str = "Hello World!\n";


    
    int* pI_uninit = &x;
    int* pI_init = &w;
    int* pI_static = &z;
    int* pI_static_uninit = &y;

    int (*pFun_add)(int, int) = add;
    int (*pFun_mult)(int, int) = multiply;
    
    int* pI_heap = (int*)malloc(1 * sizeof(int));

    printf("uninitialized int: \t%p\t\t\t%02x\n", pI_uninit, *pI_uninit);
    printf("initialized int: \t%p\t\t\t%02x\n", pI_init, *pI_init);
    printf("uninit static int: \t%p\t\t\t%02x\n", pI_static_uninit, *pI_static_uninit);
    printf("init static int: \t%p\t\t\t%02x\n", pI_static, *(unsigned char*)pI_static);

    printf("string: \t\t%p\t\t\t%02x\n", str, *(unsigned char*)str);

    printf("function (add): \t%p\t\t\t%02x\n", add, *(unsigned char*)add);
    printf("function (mult): \t%p\t\t\t%02x\n", multiply, *(unsigned char*)multiply);
    printf("function (main): \t%p\t\t\t%02x\n", main, *(unsigned char*)main);
    printf("function (printf): \t%p\t\t\t%02x\n", printf, *(unsigned char*)printf);
    printf("function (malloc): \t%p\t\t\t%02x\n", malloc, *(unsigned char*)malloc);


    printf("malloc'd int: \t\t%p\t\t\t%02x\n", pI_heap, *pI_heap);
    printf("const short int: \t%p\t\t\t%02x\n", &s, s);

    return 113;
}

int add(int x, int y) {
    return x + y;
}

int multiply(int x, int y) {
    return x*y;
}

int return_input(int x) {
    return x;
}
