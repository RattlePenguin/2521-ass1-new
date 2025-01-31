#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define MAX_STR_LEN 512
#define TYPE_INT 0
#define TYPE_OPERATOR 1

int main(int argc, char *argv[]) {
    printf("LISP> ");
    
    // Continuous stdin
    char input[MAX_STR_LEN];
    while(1) {
        fgets(input, MAX_STR_LEN, stdin);
        
    }
    printf("=> %s", result);
}

