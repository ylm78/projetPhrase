//
// Created by Utilisateur on 20/11/2022.
//

#include <stdio.h>
#include <string.h>
#define MAX 256
#define ALPHABET_SIZE 26
#include "fonctions.h"
#include "verbe.h"
#include <time.h>

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

int isFormFlechieInNodeV(p_node mynode) //Verifie si une forme fléchie eest dans le noeud
{
    if(mynode->nb_formes)
        return 1;
    return 0;
}

int countSonsInNodeV(p_node mynode) //Fonction qui permet de compter le nombre d'enfant d'un noeud
{
    int i=0;
    while(mynode->sons[i]->lettre!="-" && i<ALPHABET_SIZE)  //Tantque la lettre est différente de '-' et i inferieur à 26
    {
        i++;    //Incrementatioon de i
        if(i==25) { //Si on a tout parcouru
            return i + 1;   //On return i+1
        }
    }
    return i;   //Sinon return i
}

char* randomNodeV(p_node mynode)    //Fonction qui permet de creer un noeaud aléatoire
{
    char* w;
    srand(time(NULL));
    w=malloc(24*sizeof(char));  //Alocation de mémmoire char à w
    int next=1; //Init de next à 1
    p_node tmp=w;   //Initialisation d'un p_node qui va parcourir mynode
    int i=rand()% countSonsInNodeV(tmp);    //i= à nb aléatoire entre 1 et le nb de fils
    while(countSonsInNodeV(tmp))    //Tantque counSonsInNodeV de tmp n'est pas null
    {
        tmp=tmp->sons[i];   //On parcours
        strcat(w,@tmp->lettre); //
        if(!countSonsInNodeV(tmp))  //Si different de countSonsInNodeV(tmp)
            return w;   //return w
        i=rand()% countSonsInNodeV(tmp);    //i prend une valeur aléatoire entre 1 et countSonsinNodeV
        if(isFormFlechieInNodeV(tmp))   //Si Il y a une forme flécchie dans tmp
        {
            next=rand()%2;  //
        }
    }
    return w;   //return w
}

char* randomTreeVerb(s_tree tree)
{
    return randomTreeVerb(tree.root);   //On applique la fonction précedente à tree.root
}
