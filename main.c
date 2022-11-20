#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stab.h>
#include <stdint.h>
#include "adjectif.h"
#include "adverbe.h"
#include "fonctions.h"
#include "nom.h"
#include "verbe.h"

#define MAX 256

int main() {
    /*
     EN CHAR
     FILE *fp,*fpcp;
    fp=fopen("test_adv.txt","r");
    fpcp=fopen("test_affichage_adv.txt", "w");
    if (fp==NULL){
        printf("Erreur fopen\n");
        return 1;
    }
    else {
        printf("Fichier ouvert\n");
        printf("\n");
        char c = fgetc(fp);
        while (c != EOF) {
            printf("%c",c);
            c = fgetc(fp);
            putc(c,fpcp);
        }
    }
    fclose(fp);
    fclose(fpcp);
    FILE *f,*fp;
    f=fopen("test_adv.txt","r");
    fp=fopen("test_affichage_adv.txt", "w");
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
            printf("%s", str);
            fputs(str,fp);
            fputs("\n",fp);
        }
    }
    fclose(f);
    fclose(fp);
    return 0;
    int choice=0;
    printf("Tapez 1 pour le modèle: nom-adjectif-verbe-nom\n");
    printf("Tapez 2 pour le modèle: nom-'qui'-verbe-nom-adjectif\n");
    printf("Tapez 3 pour le modèle perso\n");
    scanf("%d\n", &choice);
    if(choice<1 || choice>3)
        scanf("%d", &choice);
    if(choice==1)
    {
        printf("Vous avez choisi le modèle n°1\n");
    }
    else if(choice==2)
    {
        printf("Vous avez choisi le modèle n°2\n");
    }
    else if(choice==3)
    {
        printf("Vous avez choisi le modèle n°3\n");
    }
*/
    display_adv("test_adv.txt");
    copy_adv("test_affichage_adv.txt","dico_test");

    //get_file_line_v("dico_test");
}
