//
// Created by Utilisateur on 13/11/2022.
//

#include "adverbe.h"
#include "dico.txt"
#include "adverbe.txt"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 256

void copy_adverbe(char *arrive,char*depart)
{
    FILE *f=fopen(depart,"r");
    FILE *fcp=fopen(arrive,"w");
    char str[MAX];
    while(fgets(str,MAX,f)!=NULL)
    {
        char line[MAX];
        strcpy(line,str);
        char *deli="\t";
        char *portion1= strtok(line,deli);
        char *portion2= strtok(NULL,deli);
        char *portion3= strtok(NULL,"\n");

        if(strcmp(portion3,"Adv")==0)
        {
            fputs(str,fcp);
            fputs("\n",fcp);

        }

    }
    fclose(f);
    fclose(fcp);
}

s_node *Create_node(char val){
    s_node *temp = malloc(sizeof(s_node));

    temp->lettre = val;

    for (int i = 0; i < ALPHABET_SIZE; i++){
        temp->sons[i] = malloc(sizeof(s_node));
        temp->sons[i]->lettre='-';
    }
    return temp;
}

int lettre_existante(s_node * noeud, char lettre){
    int res= 0;
    for (int i = 0; i < 26; ++i) {
        if(lettre!=noeud->sons[i]->lettre){
            res++;
        }
        else{
            res= -1;
        }
    }
    return res;
}

char supp_lettre(char *chaine){
    for(int i = 0 ; chaine[i] ; i++)
        chaine[i] = chaine[i+1];
    return *chaine;
}

void ajouter_mot(s_node * noeud,char* LeMot) {
    char lettre;
    s_node *temp;
    lettre = LeMot[0];

    if(lettre=='\t'){
        return;
    }
    if (lettre_existante(noeud, lettre) != -1)//la lettre n'existe pas
    {
        int c=0;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if(noeud->sons[i]->lettre != '-'){
                c++;
            }
        }
        noeud->sons[c] = Create_node(lettre);
    }
    else {
        temp = noeud->sons[lettre_existante(noeud, lettre)];
    }
    supp_lettre(LeMot);
    ajouter_mot(temp,LeMot);
}

s_tree Creer_arbre_adverbe(){

    s_tree arbre;
    arbre.root = Create_node(' ');
    int code_n = 97; //code ascii de 'a'
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        arbre.root->sons[i] = Create_node((char) code_n);
        code_n++;
    } //initialiser l'arbre

    copy_adverbe("adverbe.txt","dico.txt");
    FILE *f=fopen("adverbe.txt","r");
    char str[MAX];
    while(fgets(str,MAX,f)!=NULL) {
        char line[MAX];
        strcpy(line, str);
        char *deli = "\t";
        char *portion1 = strtok(line, deli);
        char *portion2 = strtok(NULL, deli);
        char *portion3 = strtok(NULL, "\n");

        char mot[25];// mot de base le plus long comprend 25 cracrtères
        strcpy(mot, portion2);
        ajouter_mot(arbre.root,portion2);
    }


}
