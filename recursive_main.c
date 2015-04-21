#include <stdio.h>

int main(int argc, char **argv) {
    int retval = 0;
    if (argc != 0) {
        printf("Why did you type %s?\n", argv[argc-1]);
        retval = 1 + main(argc - 1, argv);
    }
    return retval;
}

/*

Example usage:

gcc -o stupid recursive_main.c
./stupid anything\ at\ all that

*/
