//
// Created by Utilisateur on 13/11/2022.
//

#ifndef PROJETPHRASE_TREE_H
#define PROJETPHRASE_TREE_H
#define ALPHABET_SIZE 26

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


//Prototype de fonction
int IsVerbeInFichier(char*);
void copy_verbe(char *,char*);
void ajt_vrb_txt(char*);
node_v *new_node_v(char );
tree_v tree_verbe();
void get_file_line_v(char *);
