// Implementation of a B-Tree in C
// Uses linked lists to store values

#include <stdio.h>
#include <stdlib.h>

#define NUMVALUES 2
#define NUMCHILDREN 3

struct treeNode {
    struct listNode *value;
    
};

struct listNode {

    struct listNode *next;
};

struct treeNode *bstNew() {

}