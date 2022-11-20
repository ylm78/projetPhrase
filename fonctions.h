//
// Created by Utilisateur on 13/11/2022.
//

#ifndef PROJETPHRASE_TREE_H
#define PROJETPHRASE_TREE_H
#define ALPHABET_SIZE 26

#include <stdio.h>
#include <stdlib.h>
#endif

typedef struct node{

    char lettre; //lettre contenue dans le noeud
    struct node* sons[ALPHABET_SIZE]; // pointeur sur un tableau contenant les nfils (max 26)
}s_node, *p_node;

typedef struct tree{
    s_node *root;
}s_tree;

//protypes
void rechercher_mot();
int isFormFlechieInNodeV(p_node mynode);
int countSonsInNodeV(p_node mynode);
char* randomNodeV(p_node mynode);
char* randomTreeVerb(s_tree tree);