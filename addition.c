#include <stdio.h>
#include <stdlib.h>

int add(int, int);

int main(int argc, char** argv) {

    if (argc != 3) {
        fprintf(stderr, "%s needs exactly 2 additional arguments!\n", argv[0]);
        return -1;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int sum = add(x, y);
    printf("%d + %d = %d\n", x, y, sum);
    return 0;
}

int add(int a, int b) {
    int sum, carry;
    sum = a ^ b; 
    carry = ((a & b) << 1);

    //now just repeatedly add the carry to the previous sum
    //until there is nothing left to carry!
    while(carry != 0) {
        sum = sum ^ carry;
        carry = ((sum ^ carry) & carry) << 1;
    }

    return sum;
}
