#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clients.h"


int quitter()
{
    int quitte=0, retour=0;
    char clz[500]="";
    do
    {
        printf("voulez vous vraiment quitter le programme\n\n");
        printf("**\t\t1.OUI\n**\t\t2.NON\n");
        retour=scanf("%d",&quitte);
        gets(clz);
    }while(retour!=1);
    if(quitte==1)
        exit(0);
}

void ajout()
{
	
	system("cls");
	printf("*********EFFECTUER LA SASIE***********\n");
    char s = 0,*chaine[TAILLE_MAX];
    int n = 1;
    FILE* banque = fopen("banque.txt","a");
    if(banque == NULL) {

    	printf("\nImpossible d'ouvrir le fichier");
    	return;
    }
    do{
    	printf("Client %d\n",n);
        printf("\nEntrer le numero du client : ");
        fflush(stdin);
        scanf("%[0-9]s",id.NUMERO);
        fflush(stdin);
        while(strlen(id.NUMERO) != 9 )
        {
            printf("\nRe-entrer le numero comportant 9 chiffres : ");
            scanf("%[0-9]s",id.NUMERO);
            fflush(stdin);
        }
        while(fgets(chaine,TAILLE_MAX,banque)!= NULL)
        {
            if(strcmp(id.NUMERO,id.NUMERO)!=0)
            {
                printf("Entrez un nouveau numero du client");
                scanf("%s",id.NUMERO);
            }
        }
        printf("\nEntrer le nom du client : ");
        scanf("%s",id.NOM);
        printf("\nEntrez le PRENOM du client : ");
        scanf("%s",id.PRENOM);
        printf("\nEntrez l'identifiant : ");
        scanf("%d%*[^\n]s",&id.NCIN);
        fflush(stdin);
        while(id.NCIN < -1 || id.NCIN > 1000)
        {
            printf("\nEntrez un identifiant raisonnable : ");
            scanf("%d%*[^\n]s",&id.NCIN);
            fflush(stdin);
        }
        printf("\nEntrer la profession du client : ");
        scanf("%s",id.PROFESSION);
        printf("Entrez la date de creation :");
        scanf("%s",id.DATE);
		fprintf(banque,"%s;%s;%s;%d;%s;%s/%s/%s",id.NUMERO,id.NOM,id.PRENOM,id.NCIN,id.PROFESSION,id.DATE);

		printf("Si le nombre de clients est atteint veuillez tape s : ");
		scanf("%c",&s);
		fflush(stdin);
		n++;
		system("cls");

	}while(s != 's');
	fclose(banque);
}
void supprime(char*NCIN)
{
		int i = 0, premier = 1,d=0;
		char chaine[200] = "",temp[201] = "",*token = NULL,si,ncin[9];
		FILE* banque = fopen("banque.txt","a"),*file_NCIN = fopen("banque_tmp.txt","w");
		if(banque==NULL || file_NCIN==NULL)
		{
			printf("impossible d'ouvrir le fichier !!");
			return;
		}
		printf("1-Supprimer tout");
		printf("2-Supprimer un a un");
		scanf("%d",&d);
		if(d==1)
		{
			remove("banque.txt");
		}
		else if(d==2)
		{
			do{
				if(premier)
					printf("\nRE-Entrer le numero de CIN du candidat a supprimer si vous le voulez vraiment : ");
		        else{
		        	printf("\nNCIN n'existe pas re-entrer : ");
		        	printf("\nReesayer ?(o/n) : ");
		        	scanf("%[o-n^;]c",&si);
		        	if(si == 'n')
		        		goto found;  // sortie d'un nested construct de boucle
		        	printf("\nEntrer le numero de CIN a supprimer : ");
		        }
		        scanf("%s",ncin);
		        fflush(stdin);
		        while(strlen(ncin) != 9)
		        {
		            printf("\nRe-entrer le numero comportant 9 chiffres : ");
		           	scanf("%[0-9^;]s",ncin);
		           	fflush(stdin);
		        }
		        premier = 0;
		    }while(rechercher(ncin) == 0);
		    
		    while(fgets(chaine, 200, banque) != NULL)
			{
				strcpy(temp,chaine);
				token = strtok(chaine,";");
				if(strcmp(token,NCIN) != 0)
					fprintf(file_NCIN,"%s\n",temp);
		    }
			fclose(banque);
		    fclose(file_NCIN);
			remove("banque.txt");
			rename("banque_tmp.txt","banque.txt");
			return;
			found:
				remove("banque_tmp.txt");
				fclose(banque);
				printf("\nvous-etes sortie");
				system("pause");
	
		
		}

}
void modifier()
{
	FILE* banque = fopen("banque.txt","a"),*file_tmp = fopen("banque_tmp.txt","w");
	char chaine[200], ncin[10], choix, *token = NULL, temp[200] = "" ,c;
	
	if(banque == NULL || file_tmp == NULL)
    {
		printf("Impossible d'ouvvrir ce fichier\n");
		return;
	}
	printf("\t\tEntrez le numero de la cni a modifier :\n ");
	scanf("%s",ncin);
    fflush(stdin);
	printf("\t\tVoullez vous vraiment modifier ? o/n :\n ");
	scanf("%c",&choix);
	fflush(stdin);
	if(choix == 'o'|| choix == 'O')
	{
		while(fgets(chaine,200,banque)!=NULL)
		{
			strcpy(temp,chaine);
			token = strtok(chaine,";");
			if(strcmp(token,ncin) != 0) 
			{
				fprintf(file_tmp,"%s",temp);
		    }else {
				printf("\t\tEntrer le numero de CIN : ");
		    	scanf("%[0-9][^;]s",id.NUMERO);
		    	fflush(stdin);
		    	while(strlen(id.NUMERO) != 9)        //verifie que la chaine de caractere entree est veritablement egale a 9
		    	{
		      		printf("Re entrer le numero comportant 9 chiffres : ");
		      		scanf("%[0-9][^;]s",id.NUMERO);
		      		fflush(stdin);
		    	}
	        	printf("Entrez le noms du client : ");
	        	scanf("%s",id.NOM);
	        	printf("Entrez le prenom du client: ");
	        	scanf("%s",id.PRENOM);
	        	printf("Entrez l'identifiant du client : ");
	        	scanf("%d%*[^\n]s",&id.NCIN);
	        	fflush(stdin);
		        while(id.NCIN < -1 || id.NCIN > 1000)
		        {
		            printf("\nEntrez un identifiant raisonnable : ");
		            scanf("%d%*[^\n]s",&id.NCIN);
		            fflush(stdin);
		        }
		        printf("\nEntrer la profession du client : ");
		        scanf("%s",id.PROFESSION);
		        printf("Entrez la date de creation :");
		        scanf("%s",id.DATE);
				fprintf(file_tmp,"%s;%s;%s;%d;%s;%s/%s/%s",id.NUMERO,id.NOM,id.PRENOM,id.NCIN,id.PROFESSION,id.DATE);
			}
	   }
   }
}

