#ifndef _CLIENTS_H_
#define _CLIENTS_H_

#define TAILLE_MAX 400
typedef struct clients
{
	char NOM[100],PRENOM[100],PROFESSION[15],NUMERO[9],DATE[10];
	int NCIN;
}clients;
clients id;
//FONCTION POUR SORTIR DU PROGRAME
  int quitter();

//FONCTION DU MENU

int menu();
//FOCNTIONS DU PROGRAMME
void ajout();
void supprimer(char*NCIN);
#endif
