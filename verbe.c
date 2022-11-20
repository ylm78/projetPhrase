//
// Created by Utilisateur on 20/11/2022.
//

#include "verbe.h"
#include "dico.txt"
#include "verbe.txt"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 256

void copy_verbe(char *arrive,char*depart)   //Fonction qui permet de verifier si un verbe est dans le fichier
{
    FILE *f=fopen(depart,"r");  //Ouverture du fichier en mode lecture
    FILE *fcp=fopen(arrive,"w");    //Ouverture du fichier dans lequelle on va écrire en mode ecriture
    char str[MAX];  //Definition d'une chaine de caractere (tableau)
    while(fgets(str,MAX,f)!=NULL)   //Tant que nous n'avons pas parcouru le fichier jusqu'au bout
    {
        char line[MAX]; //Une chaine de caractrèe qui va contenir chaque line
        strcpy(line,str);   //Fonction qui permet de copier le contenu de str dans line
        char *deli="\t";    //Définition d'un delimitateur
        char *portion1= strtok(line,deli);  //La portion1 qui va contenir tout ce qu'il y a avant le premier tab
        char *portion2= strtok(NULL,deli);  //La portionn2 qui va contenir tout ce qu'il y a entre le deuxième et le premier tab
        char *portion3= strtok(NULL,"\n");  //La portion3 qui va conteir tout ce qu'il y a entre le troisième tab et le deuxième

        if(strcmp(portion3,"Ver")==0)   //Si la portion3 contient la chaine de caractère 'Ver' alors :
        {
            fputs(str,fcp); //Inserer str danns le fichier qui a pour pointeur fcp
            fputs("\n",fcp);    //Avec un espace entre chaque ligne

        }

    }
    fclose(f);  //Fermeture du fichier de depart
    fclose(fcp);    //Fermeture du fichier d'arrive
}

s_node *Create_node(char val){  //Fonction qui permet de creer un noeud
    s_node *temp = malloc(sizeof(s_node));  //Initialisation et allocation de mémoire à un temp

    temp->lettre = val; //Initialisation de val à temp->lettre

    for (int i = 0; i < ALPHABET_SIZE; i++){    //Boucle pour parcourir tout les noeud
        temp->sons[i] = malloc(sizeof(s_node)); //Allocation de mémoire à l'element i du tableau sons
        temp->sons[i]->lettre='-';  //Initialisation d'un charactère vide pour le premier noeaud
    }
    return temp;    //retour du pointeur de noeaud temp
}

int lettre_existante(s_node * noeud, char lettre){  //Fonction qui permet de savoir si une lettre existe
    int res= 0; //Initialisation d'un entier res à 0
    for (int i = 0; i < 26; ++i) {  //Boucle pour parcourir chaque noeud
        if(lettre!=noeud->sons[i]->lettre){ //Si la lettre est différente de la lettre presente dans le tableau sons du noeud
            res++;  //Incrémentation de res
        }
        else{   //Sinon
            res= -1;    //Décrementation de res
        }
    }
    return res; //Return res
}

char supp_lettre(char *chaine){ //Fonction qui supprime une lettre
    for(int i = 0 ; chaine[i] ; i++)    //Boucle qui parcours la chaine de caractere
        chaine[i] = chaine[i+1];    //Incrementation de i+1 à i
    return *chaine; //Return un pointeur de char
}

void ajouter_mot(s_node * noeud,char* LeMot) {  //Fonction qui permet d'ajouter un mot
    char lettre;    //Initialisation d'une lettre
    s_node *temp;   //Initialisation d'un s_node*
    lettre = LeMot[0];  //Initialisation de LeMot[0] à lettre

    if(lettre=='\t'){   //Si lettre vaut '\t'
        return; //Return rien
    }
    if (lettre_existante(noeud, lettre) != -1)//la lettre n'existe pas
    {
        int c=0;    //Initialisation de c à 0
        for (int i = 0; i < ALPHABET_SIZE; ++i) {   //Boucle qui parcours chaque noeud
            if(noeud->sons[i]->lettre != '-'){  //Si la lettre est différente de '-'
                c++;    //alors on incremente c
            }
        }
        noeud->sons[c] = Create_node(lettre);   //On creer un noeud à noeud_>sons[c]
    }
    else {  //Sinon
        temp = noeud->sons[lettre_existante(noeud, lettre)];    //
    }
    supp_lettre(LeMot); //On applique la fonction qui supprime_lettre à LeMot
    ajouter_mot(temp,LeMot);    //On applique ajouter_mot à LeMot au temp
}

s_tree Creer_arbre_verbe(){ //Fonction qui permet de creer un arbre

    s_tree arbre;   //arbre de type s_tree
    arbre.root = Create_node(' ');  //Creation d'un noeud à arbre.root
    int code_n = 97; //code ascii de 'a'
    for (int i = 0; i < ALPHABET_SIZE; ++i) {   //Boucle qui parcours chaque noeud
        arbre.root->sons[i] = Create_node((char) code_n);   //Creation d'un noeud
        code_n++;   //le code ascii qui prend +1
    } //initialiser l'arbre

    copy_verbe("verbe.txt","dico.txt");   //Copie seulement les verbes present dans dico.txt dans verbe.txt
    FILE *f=fopen("verbe.txt","r"); //Ouverture d'un fichier en mode écriture
    char str[MAX];  //Initialisation d'une chaine de carcactère str
    while(fgets(str,MAX,f)!=NULL) { //Tant que nous ne sommes pas arrivé à la fin du fichier
        char line[MAX];  //Chaine de caractère qui va contenir les lignes du fichiers
        strcpy(line, str);  //Fonction qui permet de copier les elements de str dans line
        char *deli = "\t";  //Initialisation d'un delimiteur '\t'
        char *portion1 = strtok(line, deli);    //La portion1 qui va contenir tout ce qu'il y a avant le premier tab
        char *portion2 = strtok(NULL, deli);    //La portionn2 qui va contenir tout ce qu'il y a entre le deuxième et le premier tab
        char *portion3 = strtok(NULL, "\n");    //La portion3 qui va conteir tout ce qu'il y a entre le troisième tab et le deuxième

        char mot[25];// mot de base le plus long comprend 25 cracrtères
        strcpy(mot, portion2);  //Fonction qui va copier les elements de portion2 dans mot
        ajouter_mot(arbre.root,portion2);   //Ajouter la portion2 dans arbre.root
    }


}