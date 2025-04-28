#include <stdlib.h>
#include <stdio.h>
#include "tree.h"


Tree* initialize() {
    return NULL;
};

char is_empty(Tree* t) {
    return t == NULL;
}

Tree* append(Tree **t, int v) {
    if(is_empty(*t)) {
        *t = (Tree*) malloc(sizeof(Tree));
        (*t)->v = v;
        (*t)->l = initialize();
        (*t)->r = initialize();
        return *t;
    } else {
        if((*t)->v >= v) {
            return append(&(*t)->l, v);
        }
        if((*t)->v < v) {
            return append(&(*t)->r, v);
        }
    }
}

Tree* search_first(Tree *t, int v) {
    if(is_empty(t)) {
        return NULL;
    }
    if(t->v == v) {
        return t;
    }
    if(t->v > v) {
        return search_first(t->l, v);
    } else {
        return search_first(t->r, v);
    }
}

void walk_tree_pre_order(Tree *t, void (*func)(int v)) {
    if(is_empty(t)) {
        return;
    }
    func(t->v);
    walk_tree_pre_order(t->l, func);
    walk_tree_pre_order(t->r, func);
}

void walk_tree_in_order(Tree *t, void (*func)(int v)) {
    if(is_empty(t)) {
        return;
    }
    walk_tree_in_order(t->l, func);
    func(t->v);
    walk_tree_in_order(t->r, func);
}

void walk_tree_post_order(Tree *t, void (*func)(int v)) {
    if(is_empty(t)) {
        return;
    }
    walk_tree_post_order(t->l, func);
    walk_tree_post_order(t->r, func);
    func(t->v);
}

Tree* remove_value(Tree* t, int v) {
    if(is_empty(t)) {

    }
}