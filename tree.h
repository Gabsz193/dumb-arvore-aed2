typedef struct Tree {
    struct Tree *l, *r;
    int v;
} Tree;

Tree* initialize();

char is_empty(Tree *t);

Tree* append(Tree **t, int v);

Tree* search_first(Tree *t, int v);

void walk_tree_pre_order(Tree *t, void (*func)(int v));

void walk_tree_in_order(Tree *t, void (*func)(int v));

void walk_tree_post_order(Tree *t, void (*func)(int v));

Tree* remove_value(Tree *t, int v);

void clear_tree(Tree **t);