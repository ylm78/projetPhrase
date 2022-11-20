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
void copy_nom(char *arrive,char*depart);
s_node *Create_node(char val);
int lettre_existante(s_node * noeud, char lettre);
char supp_lettre(char *chaine);
void ajouter_mot(s_node * noeud,char* LeMot);
s_tree Creer_arbre_nom();