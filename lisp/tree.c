#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int type;
    void *value;
    struct node *left;
    struct node *right;
} *Node;

Node newNode(int type, void *value) {
    Node new = malloc(sizeof(new));
    new->type = type;
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}


