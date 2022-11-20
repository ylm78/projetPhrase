//
// Created by Utilisateur on 13/11/2022.
//

#ifndef PROJETPHRASE_TREE_H
#define PROJETPHRASE_TREE_H
#define ALPHABET_SIZE 26

#include <stdio.h>
#include <stdlib.h>
#endif
typedef struct v_flechies{
    char * forme_conj;
    char pers[2];
    char nombre_gram[2]; //singulier pluriel
    char temps[5];
}v_flechies;

typedef struct cell_flechies_verbe{

    v_flechies flechies;
    struct cell_flechies_verbe* next;

}*p_flechie_v;

typedef struct liste_flechie_verbe{
    p_flechie_v head;
}l_flechie;

typedef struct node{
    char lettre;
    int nb_formes; //nombre formes flechies
    l_flechie l_flechie;
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

//protypes
void rechercher_mot();
int isFormFlechieInNodeV(p_node mynode);
int countSonsInNodeV(p_node mynode);
char* randomNodeV(p_node mynode);
char* randomTreeVerb(s_tree tree);