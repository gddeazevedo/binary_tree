#include <stdio.h>
#include "src/tree/tree.h"


int main() {
    Tree* tree = build_tree(3);


    // plant(&tree);
    printf("In level: ");
    show_in_level(tree);

    printf("Pre pre order: ");
    show_pre_order(tree);

    printf("In order: ");
    show_in_order(tree);

    printf("Post order: ");
    show_post_order(tree);

    return 0;
}
