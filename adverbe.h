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
s_tree Creer_arbre_adverbe();
void ajouter_mot(s_node * noeud,char* LeMot);
char supp_lettre(char *chaine);
int lettre_existante(s_node * noeud, char lettre);
s_node *Create_node(char val);
void copy_adverbe(char *arrive,char*depart);