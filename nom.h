//
// Created by Utilisateur on 13/11/2022.
//

#ifndef PROJETPHRASE_TREE_H
#define PROJETPHRASE_TREE_H
#define ALPHABET_SIZE 26

#include <stdio.h>
#include <stdlib.h>
#endif

typedef struct nom_flechies{
    int nb_forme;
    char* forme_flechie;
    char genre[3];      //masculin feminin
    char nombre_gram[2];    //singulier pluriel
}nom_flechies;

typedef struct cell_nom_flechies{
    nom_flechies flechies;
    struct cell_nom_flechies* next;
}*p_flechie_nom;

typedef struct liste_flechie_nom{
    p_flechie_nom head;
}liste_flechie_nom;

typedef struct node_nom{
    char lettre;
    int nb_formes;
    liste_flechie_nom l_flechie;
    struct node_nom* sons[ALPHABET_SIZE];
}s_node_nom, *pnode_nom;

typedef struct tree_nom{
    pnode_nom root;
}s_tree_nom;

//Prototype fonction
void display_nom(char*);
void copy_nom(char *,char*);
s_node_nom *new_node_nom(char );
s_tree_nom tree_nom();
int IsNomInFichier(char*);
void copy_nom(char *arrive,char*depart);
void ajt_nom_txt(char*);
#endif //RANDOM_TENSE_NOM_H

