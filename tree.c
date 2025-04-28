#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

Tree* initialize() {
    return NULL;
};

char is_empty(Tree *t) {
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

char has_only_child(Tree *t) {
    return (!t->l && t->r) || (t->l && !t->r);
}

char no_child(Tree *t) {
    return !t->r && !t->l; 
}

void foo(Tree *t, Tree *b, Tree *s) {
    if(b->r == t) {
        b->r = s;
    } else {
        b->l = s;
    }
    free(t);
}

char _remove_value(Tree *t, Tree *b, int v) {
    if(is_empty(t)) {
        return 0;
    }
    if(t->v == v) {
        if(has_only_child(t) || no_child(t)) {
            if(t->l) {
                foo(t, b, t->l);
            }
            if(t->r) {
                foo(t, b, t->r);
            }
        } else {
            Tree *tmp1 = t->l, *tmp2;

            while(tmp1) {
                tmp2 = tmp1;
                tmp1 = tmp1->r;               
            }

            

            tmp2->l = t->l;
            tmp2->r = t->r;

            foo(t, b, tmp2);
            
        }
    }
    if(t->v >= v) {
        _remove_value(t->l, t, v);
    } else {
        _remove_value(t->r, t, v);
    }
}

char remove_value(Tree *t, int v) {
    _remove_value(t, NULL, v);
}