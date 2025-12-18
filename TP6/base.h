#pragma once

#include <stdlib.h>
#include <stdbool.h>

void tri_insertion(int *T, int n);

bool est_trie(int *T, int n);

int *genere_tab(int n);

void echanger(int *T, int a, int b);

int partition_entre(int *T, int a, int b);
