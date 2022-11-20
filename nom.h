//
// Created by Utilisateur on 13/11/2022.
//

#ifndef PROJETPHRASE_TREE_H
#define PROJETPHRASE_TREE_H
#define ALPHABET_SIZE 26

#include <stdio.h>
#include <stdlib.h>
#endif

ttypedef struct adj_flechies{
    int nb_forme;
    char* forme_flechie;
    char genre[3];      //Rien masculin feminin
    char nombre_gram[2];    //singulier pluriel
}adj_flechies;

typedef struct cell_adj_flechies{
    adj_flechies flechies;
    struct cell_adj_flechies* next;
}*p_flechie_adj;

typedef struct liste_flechie_adj{
    p_flechie_adj head;
}liste_flechie_adj;

typedef struct node_adj{
    char lettres;
    int nb_formes;
    liste_flechie_adj l_flechie;
    struct node_adj* sons[ALPHABET_SIZE];
}node_adj;

typedef struct tree_adj{
    node_adj root;
}s_tree_adj;

void copy_adj(char *arrive,char*depart);
int IsAdjInFichier(char*);
void ajt_adj_txt(char*);
node_adj *new_node_adj(char);
s_tree_adj tree_adj();


//protypes
void copy_nom(char *arrive,char*depart);
s_node *Create_node(char val);
int lettre_existante(s_node * noeud, char lettre);
char supp_lettre(char *chaine);
void ajouter_mot(s_node * noeud,char* LeMot);
s_tree Creer_arbre_nom();
