#include "tree.h"

void plant(Tree** tree) {
    printf("Digite um caracter: ");
    char data;
    __fpurge(stdin);
    scanf("%c", &data);

    if (data != '.') {
        *tree = (Tree*)malloc(sizeof(Tree));
        (*tree)->data = data;
        plant(&(*tree)->left);
        plant(&(*tree)->right);
    } else {
        *tree = (Tree*)NULL;
    }
}


Tree* build_tree(int h) {
    Queue* q = newQueue();
    Tree* tree = (Tree*) malloc(sizeof(Tree));
    enqueue(q, tree);
    int n = (int) pow(2, h - 1) - 1;
    int i = 1;

    tree->data = (char) i;
    tree->left = NULL;
    tree->right = NULL;

    while (q->head != NULL) {
        Tree* p = dequeue(q);

        Tree* left = (Tree*) malloc(sizeof(Tree));
        left->data = i + 1;
        left->left = NULL;
        left->right = NULL;

        Tree* right = (Tree*) malloc(sizeof(Tree));
        right->data = i + 2;
        right->left = NULL;
        right->right = NULL;
        
        p->left = left;
        p->right = right;
        i += 2;

        if (i <= n) {
            enqueue(q, left);
            enqueue(q, right);
        }
    }
}


void show_in_level(Tree* tree) {
    Queue* q = newQueue();
    enqueue(q, tree);

    while (q->head != NULL) {
        Tree* p = dequeue(q);

        if (p != NULL) {
            printf("%c ", p->data);
            enqueue(q, p->left);
            enqueue(q, p->right);
        }
    }

    printf("\n");
}

void show_pre_order(Tree* tree) {
    Stack* s = newStack();
    push(s, tree);

    while (s->top != NULL) {
        Tree* p = pop(s);

        if (p != NULL) {
            printf("%c ", p->data);
            push(s, p->right);
            push(s, p->left);
        }
    }

    printf("\n");
}

void show_in_order(Tree* tree) {
    Stack* s = newStack();
    Tree* p = tree;

    while (p != NULL || s->top != NULL) {
        while (p != NULL) {
            push(s, p);
            p = p->left;
        }

        p = pop(s);
        printf("%c ", p->data);
        p = p->right;
    }

    printf("\n");
}

void show_post_order(Tree* tree) {
    Stack* s = newStack();
    Tree* p = tree;

    while (p != NULL || s->top != NULL) {
        while (p != NULL) {
            push_with_time(s, p, 1);
            p = p->left;
        }

        while (p == NULL && s->top != NULL) {
            Node* node = pop_with_time(s);
            int time = node->time;
            p = node->data;

            if (time == 1 && p->left != NULL) {
                push_with_time(s, p, 2);
                p = p->right;
            } else {
                printf("%c ", p->data);
                p = NULL;
            }
        }
    }

    printf("\n");
}

// Recursive functions
void rshow_pre_order(Tree* tree) {
    if (tree == NULL) return;
    printf("%c ", tree->data);
    rshow_pre_order(tree->left);
    rshow_pre_order(tree->right);
}

void rshow_in_order(Tree* tree) {
    if (tree == NULL) return;
    rshow_in_order(tree->left);
    printf("%c ", tree->data);
    rshow_in_order(tree->right);
}

void rshow_post_order(Tree* tree) {
    if (tree == NULL) return;
    rshow_post_order(tree->left);
    rshow_post_order(tree->right);
    printf("%c ", tree->data);
}
