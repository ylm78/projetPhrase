//
// Created by Utilisateur on 20/11/2022.
//

#include <stdio.h>
#include <string.h>
#define MAX 256
#define ALPHABET_SIZE 26
#include "fonctions.h"

void rechercher_mot(){
    char mot[50];
    printf("Saisissez le mot que vous souhaitez rechercher :\n");
    scanf("%s", mot);
    FILE *f=fopen("dico.txt","r");
    char str[MAX];
    while(fgets(str,MAX,f)!=NULL) {
        char line[MAX];
        strcpy(line, str);
        char *deli = "\t";
        char *portion1 = strtok(line, deli);
        char *portion2 = strtok(NULL, deli);
        char *portion3 = strtok(NULL, "\n");
        if (strcmp(portion2,mot)==0){
            printf("Le mot recherché existe dans le dictionnaire.\n");

        }
        else{
            printf("Le mot recherché n'existe pas dans le dictionnaire.\n");

        }

    }
}

int isFormFlechieInNodeV(p_node mynode)
{
    if(mynode->nb_formes)
        return 1;
    return 0;
}

int countSonsInNodeV(p_node mynode)
{
    int i=0;
    while(mynode->sons[i]->lettre!="-" && i<ALPHABET_SIZE)
    {
        i++;
        if(i==25) {
            return i + 1;
        }
    }
    return i;
}

char* randomNodeV(p_node mynode)
{
    char* w;
    srand(time(NULL));
    w=malloc(24*sizeof(char));
    int next=1;
    p_node tmp=w;
    int i=rand()% countSonsInNodeV(tmp);
    while(countSonsInNodeV(tmp))
    {
        tmp=tmp->sons[i];
        strcat(mot,@tmp->lettre);
        if(!countSonsInNodeV(tmp))
            return w;
        i=rand()% countSonsInNodeV(tmp);
        if(isFormFlechieInNodeV(tmp))
        {
            next=rand()%2;
        }
    }
    return w;
}

char* randomTreeVerb(s_tree tree)
{
    return randomTreeVerb(tree.root);
}
