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
    if(*t == NULL) {
        *t = malloc(sizeof(Tree));
        (*t)->v = v;
        (*t)->l = NULL;
        (*t)->r = NULL;
        return *t;
    } else {
        if((*t)->v >= v) {
            return append(&(*t)->l, v);
        } else {
            return append(&(*t)->r, v);
        }
    }
}

Tree* search_first(Tree *t, int v) {
    if(t == NULL || t->v == v) {
        return t;
    }
    if(v < t->v) {
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
}

Tree* _remove_value(Tree *t, Tree *b, int v) {
    Tree *tmp1, *tmp2;
    if(is_empty(t)) {
        return NULL;
    }
    if(t->v == v) {
        if(!(has_only_child(t) || no_child(t))) {
            tmp1 = t->l, tmp2 = tmp1;
            while(tmp1->r) {
                tmp2 = tmp1;
                tmp1 = tmp1->r;               
            }

            Tree* tmp_l = t->l;
            Tree* tmp_r = t->r;
            t->l = tmp1->l;
            t->r = tmp1->r;

            if(tmp_l == tmp1->l) {
                tmp1->l = t;
            } else {
                tmp1->l = tmp_l;
            }

            tmp1->r = tmp_r;
            if(b) {
                foo(tmp1, b, tmp1);                
            }

            b = tmp2;
        }
        if(b) {
            if(t->l) {
                foo(t, b, t->l);
            } else {
                foo(t, b, t->r);
            }
        }

        t = NULL;

        if(b == NULL) {
            return tmp1;
        } else {
            return t;
        }
    }
    if(t->v > v) {
        return _remove_value(t->l, t, v);
    } else {
        return _remove_value(t->r, t, v);
    }
}

Tree* remove_value(Tree *t, int v) {
    return _remove_value(t, NULL, v);
}

void clear_tree(Tree **t) {
    if(*t != NULL) {
        clear_tree(&((*t)->l));
        clear_tree(&((*t)->r));
    } else {
        free(*t);
    }
    *t = NULL;
}