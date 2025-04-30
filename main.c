#include <stdio.h>
#include "tree.h"

#define N 10

void print_value(int x) {
    printf("%d ", x);
}

int main() {
    Tree *t, *s;
    int vet[] = {5, 9, 1, 4, 2, 3, 7, 8, 0, 6};
    int i, search_found_value = 9, search_not_found_value = -1;
    Tree *aux;
    
    t = initialize();

    for(i = 0; i < N; i++) {
        printf("Adding value %d...\n", vet[i]);
        append(&t, vet[i]);
    }
    printf("Tree done\n");

    printf("\n");

    printf("Pre-order traversal: ");
    walk_tree_pre_order(t, print_value);
    printf("\n");
    printf("In-order traversal: ");
    walk_tree_in_order(t, print_value);
    printf("\n");
    printf("Post-order traversal: ");
    walk_tree_post_order(t, print_value);
    printf("\n");

    printf("\n");


    printf("Searching found value %d...\n", search_found_value);
    s = search_first(t, search_found_value);

    if(s) {
        printf("Found %d\n", s->v);
    } else {
        printf("Not found\n");
    }

    printf("Searching not found value %d...\n", search_not_found_value);
    s = search_first(t, search_not_found_value);

    if(s) {
        printf("Found %d\n", s->v);
    } else {
        printf("Not found\n");
    }

    printf("\n");

    printf("Removing only-child value %d...\n", search_found_value);
    aux = remove_value(t, search_found_value);
    if(aux) {
        t = aux;
        printf("Removed %d\n", search_found_value);
    } else {
        printf("Not found\n");
    }

    printf("\n");

    printf("Pre-order traversal: ");
    walk_tree_pre_order(t, print_value);
    printf("\n");
    printf("In-order traversal: ");
    walk_tree_in_order(t, print_value);
    printf("\n");
    printf("Post-order traversal: ");
    walk_tree_post_order(t, print_value);
    printf("\n");

    printf("\n");

    printf("Removing value %d...\n", search_not_found_value);
    aux = remove_value(t, search_not_found_value);
    if(aux) {
        t = aux;
        printf("Removed %d\n", search_not_found_value);
    } else {
        printf("Not found\n");
    }

    printf("Removing both-child value %d...\n", 1);
    aux = remove_value(t, 1);
    if(aux) {
        t = aux;
        printf("Removed %d\n", 1);
    } else {
        printf("Not found\n");
    }

    printf("\n");

    printf("Pre-order traversal: ");
    walk_tree_pre_order(t, print_value);
    printf("\n");
    printf("In-order traversal: ");
    walk_tree_in_order(t, print_value);
    printf("\n");
    printf("Post-order traversal: ");
    walk_tree_post_order(t, print_value);
    printf("\n");

    printf("\n");

    printf("Cleaning the tree...\n");
    clear_tree(&t);

    if(is_empty(t)) {
        printf("Tree is empty\n");
    } else {
        printf("Tree exists!\n");
    }

    

    return 0;
}