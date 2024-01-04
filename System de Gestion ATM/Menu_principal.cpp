#include <stdio.h>

//Utilisateur
struct 		User{
	int 	id;
	char 	password[20];
	char 	nom[20];
	char	adresse[100];
//	char 	history[1000];
} u , Updated ;
//u : the main user account || Updated : account where we update transactions of the main user || others are used for the virement section

//Compte
struct 		Account{
	int 	id;
	char 	type[10];
	float 	montant;
} x , xUpdated , T_x ,Transfer_x ;

//Transaction
struct		Transaction{
	int		id;
	char	type_histoy[10];
	float	montant ;
	float	solde ;
	char	time[20];
} Tu, Tb, Tub ;

//Journalism
struct		Journalisation{
	char	evenement[1000];
	char	date[20];
} Ju ;

//bibliotheque user et admin
#include "atm_admin.h"
#include "atm_user.h"

int 	Menu_principal ( void );


main()
{
	//dessination du cadre
	cadre_menu();
	//Menu principal ( admin ou user )
	int choice_principal = Menu_principal();
	system("cls");
	cadre_menu();
		switch(choice_principal)
		{
			case 1:	 	Menu_admin ()						;break;
			case 2: 	Menu_user  ()						;break;
			case 0: 	system ("cls");	printf("LOGOUT")	;break;
			defeault: 	system ("cls"); printf("RECHOOSE (1-2-0)");
		}
	
}
int		Menu_principal ( void )
{
	int choice;
			gotoxy(35,3);textcolor(9);printf("%c MENU PRINCIPAL %c",2,2);
			gotoxy(32,6);printf("CHOOSE YOUR PLATFORM : ");
			gotoxy(32,10);textcolor(6);printf("1 - ADMINISTRATION");
			gotoxy(32,11);textcolor(6);printf("2 - USER");
			gotoxy(32,12);textcolor(8);printf("0 - QUITTER");
			gotoxy(35,15);textcolor(9);printf("YOUR CHOICE [   ]");
			gotoxy(49,15);scanf("%d",&choice);
			system("cls");
	return choice;
}
