//
// Created by Utilisateur on 13/11/2022.
//

#ifndef PROJETPHRASE_TREE_H
#define PROJETPHRASE_TREE_H
#define ALPHABET_SIZE 26

#include <stdio.h>
#include <stdlib.h>
#endif
//VERBE

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
}l_flechie_vrb;

typedef struct node_v{
    char lettre;
    int nb_formes; //nombre formes flechies
    l_flechie_vrb l_flechie;
    struct node_v*  sons[ALPHABET_SIZE]; //tableau de l'alphabet
}node_v, *p_node_v;

typedef struct arbre_v{
    node_v  *root;
    l_flechie_vrb l_flechie;
}tree_v;

typedef struct liste_root_verbe{
    p_flechie_v head;
}l_root_vrb;

//NOM
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

//ADVERBE
//Définition des structures
typedef struct adv_flechies{
    int nb_forme;
    char* forme_felchie;
}adv_flechies;

typedef struct cell_adv_flechies{
    adv_flechies flechies;
    struct cell_adv_flechies* next;
}*p_flechie_adv;

typedef struct liste_flechie_adv{
    p_flechie_adv head;
}liste_flechie_adv;

typedef struct node_adv{
    char lettre;
    int nb_formes;
    liste_flechie_adv l_flechie;
    struct node_adv* sons[ALPHABET_SIZE];
}node_adv,*pnode_adv;

typedef struct cell_adv{
    node_adv value;
    pnode_adv next;
}cell_adv, *pcell_adv;

typedef struct std_adv{
    pcell_adv head;
}std_adv, p_std_adv;

typedef struct tree_adv{
    node_adv *root;
}*p_tree_adv,t_tree_adv;

//ADJECTIF
typedef struct adj_flechies{
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
void rechercher_mot();
int isFormFlechieInNodeV(p_node mynode);
int countSonsInNodeV(p_node mynode);
char* randomNodeV(p_node mynode);
char* randomTreeVerb(s_tree tree);
