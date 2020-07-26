#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAILLE_MAX 400
typedef struct clients
{
	char NOM[100],PRENOM[100],PROFESSION[15],NUMERO[9],DATE[10],NCIN[9];
}clients;
clients id;

int menu();
//FOCNTIONS DU PROGRAMME
void ajout();
void supprimer(char*NCIN);
void modifier();
void afficher();
void recherche();

int main()
{
	supprime();
	rechercher();
	return 0;
}

/*int quitter()
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
    return 0;
}*/

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
        printf("\nEntrer le numero identifiant : ");
        gets(id.NCIN);
         while(strlen(id.NCIN) != 3 )
        {
            printf("\nRe-entrer le numero comportant 9 chiffres : ");
            scanf("%[0-9]s",id.NCIN);
            getc(stdin);
        }
        fprintf(banque,"%s;",id.NCIN);
        getc(stdin);
        printf("\nEntrer le nom du client : ");
        scanf("%[^\n]",id.NOM);
        fflush(stdin);
        fprintf(banque,"%s;",id.NOM);
        printf("\nEntrez le PRENOM du client : ");
        scanf("%[^\n]",id.PRENOM);
        fflush(stdin);
        fprintf(banque,"%s;",id.PRENOM);
        printf("\nEntrez le numero du client : ");
        gets(id.NUMERO);
        fflush(stdin);
         while(strlen(id.NUMERO) != 9 )
        {
            printf("\nRe-entrer le numero comportant 9 chiffres : ");
            scanf("%[0-9]s",id.NUMERO);
            gets(stdin);
        }
        fprintf(banque,"%s;",id.NUMERO);
        printf("\nEntrer la profession du client : ");
        scanf("%[^\n]",id.PROFESSION);
        fflush(stdin);
        fprintf(banque,"%s;",id.PROFESSION);
        printf("\nEntrez la date de creation :");
        scanf("%[^\n]",id.DATE);
        fflush(stdin);
		fprintf(banque,"%s\n",id.DATE);
		printf("Si le nombre de clients est atteint veuillez tape s : ");
		scanf("%c",&s);
		fflush(stdin);
		n++;
		system("cls");

	}while(s != 's');
	fclose(banque);
}
void supprime()
{
		 char NCIN[9];
		int i = 0, premier = 1,d=0;
		char chaine[200] = "",temp[201] = "",*token = NULL,si,ncin[9];
		FILE* banque = fopen("banque.txt","a"),*file_NCIN = fopen("banque_tmp.txt","w");
		if(banque==NULL || file_NCIN==NULL)
		{
			printf("impossible d'ouvrir le fichier !!");
			return ;
		}
		printf("1-Supprimer tout \n");
		printf("2-Supprimer un a un :");
		scanf("%d",&d);
		if(d==1)
		{
			remove("banque.txt");
			printf("fichier supprimer avec succes !!");
			//Menu();
		}
		else if(d==2)
		{
			do{
				if(premier)
					printf("\nRE-Entrer l'identifiant du client a supprimer si vous le voulez vraiment : ");
		        else{
		        	printf("\nNCIN n'existe pas re-entrer : ");
		        	printf("\nReesayer ?(o/n) : ");
		        	scanf("%[o-n^;]c",&si);
		        	if(si == 'n')
		        		goto found;  // sortie d'un nested construct de boucle
		        	printf("\nEntrer l'identifiant' a supprimer : ");
		        }
		        scanf("%d",ncin);
		        fflush(stdin);
		        while(strlen(ncin) != 9)
		        {
		            printf("\nRe-entrer le numero comportant 9 chiffres : ");
		           	scanf("%[0-9^;]s",ncin);
		           	fflush(stdin);
		        }
		        premier = 0;
		    }while(rechercher(ncin)==0);
		    while(fgets(chaine, 200, banque) != NULL)
			{
				strcpy(temp,chaine);
				token = strtok(chaine,";");
				if(strcmp(token,NCIN) != 0)
					fprintf(file_NCIN,"%s\n",temp);
		    }


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
void modifier()
{
	FILE* banque = fopen("banque.txt","r"),*file_tmp = fopen("banque_tmp.txt","w");
	char chaine[200], ncin[10], choix, *token = NULL, temp[200] = "" ,c ,s=0;
	int n=1;

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
			    printf("identifiant inexistant !!");
				fprintf(file_tmp,"%s",temp);
		    }else {
                    do{
                        printf("Client %d\n",n);
                        printf("\nEntrer le numero identifiant : ");
                        gets(id.NCIN);
                         while(strlen(id.NCIN) != 3 )
                        {
                            printf("\nRe-entrer le numero comportant 9 chiffres : ");
                            scanf("%[0-9]s",id.NCIN);
                            gets(stdin);
                        }
                        fprintf(file_tmp,"%s;",id.NCIN);
                        getc(stdin);
                        printf("\nEntrer le nom du client : ");
                        scanf("%[^\n]",id.NOM);
                        fflush(stdin);
                        fprintf(file_tmp,"%s;",id.NOM);
                        printf("\nEntrez le PRENOM du client : ");
                        scanf("%[^\n]",id.PRENOM);
                        fflush(stdin);
                        fprintf(file_tmp,"%s;",id.PRENOM);
                        printf("\nEntrez le numero du client : ");
                        gets(id.NUMERO);
                        fflush(stdin);
                         while(strlen(id.NUMERO) != 9 )
                        {
                            printf("\nRe-entrer le numero comportant 9 chiffres : ");
                            scanf("%[0-9]s",id.NUMERO);
                            gets(stdin);
                        }
                        fprintf(file_tmp,"%s;",id.NUMERO);
                        printf("\nEntrer la profession du client : ");
                        scanf("%[^\n]",id.PROFESSION);
                        fflush(stdin);
                        fprintf(file_tmp,"%s;",id.PROFESSION);
                        printf("\nEntrez la date de creation :");
                        scanf("%[^\n]",id.DATE);
                        fflush(stdin);
                        fprintf(file_tmp,"%s\n",id.DATE);
                        printf("Si le nombre de clients est atteint veuillez tape s : ");
                        scanf("%c",&s);
                        fflush(stdin);
                        n++;
                        system("cls");

                }while(s != 's');


			}
	   }
   }else{
   printf("merci d'avoir utiliser notre programme !!!");
   // Menu();
   }
   fclose(banque);
   fclose(file_tmp);
   remove("banque.txt");
   rename("banque_tmp.txt","banque.txt");
}
void afficher()
{
	int i=0 , k=0;
	char chaine[TAILLE_MAX],*token = NULL;
	FILE *banque = fopen("banque.txt","r");
	clients t[TAILLE_MAX] ;
	while(fgets(chaine, TAILLE_MAX, banque) != NULL)
    {
    	token = strtok(chaine ,";");
        for(i=0;i<5;i++)
        {
            if(i == 0)
            {
                strcpy(id.NUMERO ,token);
            }
            else if(i==1)
            {
                strcpy(id.NOM,token);
            }
            else if (i==2)
            {
                strcpy(id.PRENOM,token);
            }
            else if (i==3)
            {
                strcpy(id.NCIN,token);
            }
            else if(i==4)
            {
            	strcpy(id.PROFESSION,token);
			}
			 else if(i==5)
            {
            	strcpy(id.DATE,token);
			}
            token = strtok(NULL ,";");
        }
        t[k] = id;
        k++;
    }
     printf("\n");
    for(i=0;i<k;i++)
    {
        printf("\n\n-----------------------------------------------------------------------------------------------------------------------\n\n");
        printf("Les informations sur le client %d\n",i+1);
        printf("\tNUMERO: %s",t[i].NUMERO);
        printf("\tNOM: %s",t[i].NOM);
        printf("\tPRENOM: %s",t[i].PRENOM);
        printf("\tIDENTIFIANT : %s",t[i].NCIN);
        printf("\tPROFESSION : %s",t[i].PROFESSION);
        printf("\tDATE DE CREATION: %S/%S/%S\n",t[i].DATE);
    }
    printf("\n\n-----------------------------------------------------------------------------------------------------------------------\n\n");
    fclose(banque);
}
int rechercher() {
   FILE *banque = fopen("banque.txt","r");
   char chain[200] = {},ncin[9];

   if(banque == NULL){
   	printf("Impossible d'ouvrir le fichier");
   	return -1;
   }
   char chaine, *split = NULL;
   while(fgets(chain,200,banque) != NULL)
    {
   		split = strtok(chain,";");
   		if(strcmp(split,ncin) == 0){
   			fclose(banque);
   			return 1;
   		}
   }
   fclose(banque);
   return 0;
}
void recherche(char*NCIN,char*NOM)
{
	char *chaine[TAILLE_MAX],*token = NULL, temp[200]="",s=0;
	FILE *banque = fopen("banque.txt","r");
	int d=0;
	do{
		printf("1-rechercher avec le nom: ");
	printf("2-rechercher avec l'identifiant: ");
	scanf("%d",&d);
	if(d==1)
	{
		printf("1-rechercher avec le nom: ");
		scanf("%s",id.NOM);
	}else if(d==2){
		printf("1-rechercher avec l'identifiant: ");
		scanf("%s",id.NCIN);
	}else{
		printf("desolée cette option n'est valide");
	}

	}while(d!=1 && d!=2);
	if(d==1)
	{
		while(fgets(chaine, 200, banque) != NULL)
			{

                    strcpy(temp,chaine);
                    token = strtok(chaine,";");
                    if(strcmp(token,NOM) == 0)
                        afficher(NOM);
                    else
                        printf("cet identifiant n'existe pas !!");
                     printf("Si le nombre de clients est atteint veuillez tape s : ");
                    scanf("%c",&s);
                    fflush(stdin);

		    }
	}
	if(d==2){
		while(fgets(chaine, 200, banque) != NULL)
		{
			strcpy(temp,chaine);
			token = strtok(chaine,";");
			if(strcmp(token,NCIN) == 0)
				afficher(NCIN);
			else{
				printf("cet identifiant n'existe pas !!");
				/*Menu();cette fonction ecrite par guylene permet de rentrer sur le menu apres avoir effectuer un choi
				non desireux*/
			}
		}
	}
	else{
		printf("choix non disponible !!");
		// Menu();
	}
}

