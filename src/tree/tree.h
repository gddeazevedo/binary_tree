#ifndef __tree_h
#define __tree_h

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <math.h>
#include "../helpers/helpers.h"
#include "../types.h"

void plant(Tree** tree);
Tree* build_tree(int h);

void show_in_level(Tree* tree);
void show_pre_order(Tree* tree);
void show_in_order(Tree* tree);
void show_post_order(Tree* tree);

// Recursive functions
void rshow_pre_order(Tree* tree);
void rshow_in_order(Tree* tree);
void rshow_post_order(Tree* tree);

#endif