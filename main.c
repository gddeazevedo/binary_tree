#include <stdio.h>
#include "src/tree/tree.h"


int main() {
    Tree* tree = build_tree(4);

    show_in_level(tree);

    show_pre_order(tree);
    rshow_pre_order(tree);
    printf("\n");

    show_in_order(tree);
    rshow_in_order(tree);
    printf("\n");

    show_post_order(tree);
    rshow_post_order(tree);
    printf("\n");

    return 0;
}
