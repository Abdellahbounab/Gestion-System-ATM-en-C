#include <stdio.h>
#include <myconio.h>
#include <conio.h>
#include <time.h>



void 	cadre_menu		  ( void );
int 	M_admin			  ( void );
void 	Gerer_compte	  ( void );
void 	Consult_fichiers  ( void );
void 	Menu_admin		  ( void );
void 	Create_account	  ( void );
void      Compte_creation   ( int );
void 	Update_account	  ( void );
void	  Update_option		( char, int );
void 	Delete_account	  ( void );
void	  del_archive 		( int );
void 	Consult_all_users ( void );
void 	Consult_file	  ( void );
void	  table_comptes		( void );
void	  table_transactions( void );
void	  table_journal		( void );
void	  table_archives	( void );
void 	About_Us  ( void );//
void	cadre_users		  ( void );


int  	M_admin ( void )
{
	cadre_menu();
	int choice;
			gotoxy(35,3);textcolor(9);printf("%c MENU ADMINISTRATION %c",6,6);
			gotoxy(30,6);printf(" CHOOSE YOUR OPTION : ");
			gotoxy(30,9);textcolor(6);printf("1 - GERER LES COMPTES");
			gotoxy(30,10);textcolor(6);printf("2 - COSULTER LES FICHIERS");
			gotoxy(30,11);textcolor(8);printf("0 - QUITTER");
			gotoxy(35,15);textcolor(9);printf("YOUR CHOICE [    ]");
			gotoxy(50,15);scanf("%d",&choice);
			system("cls");
	return choice;
}
void 	Gerer_compte ( void )
{
	cadre_menu();
	int choice;
	gotoxy(35,3);textcolor(9);printf("%c MENU ADMINISTRATION %c",4,4);
			gotoxy(35,5);textcolor(6);printf(" GERER LES COMPTES: ");
			gotoxy(30,7);textcolor(14);printf("1 - CREATE NEW ACCOUNT");
			gotoxy(30,8);textcolor(14);printf("2 - UPDATE EXISTING ACCOUNT");
			gotoxy(30,9);textcolor(14);printf("3 - DELETE ACCOUNT");//
			gotoxy(30,10);textcolor(14);printf("4 - CONSULTAT ALL ACCOUNTS");
			gotoxy(30,12);textcolor(8);printf("5 - BACK TO MENU");
			gotoxy(35,15);textcolor(9);printf("YOUR CHOICE [    ]");
			gotoxy(50,15);scanf("%d",&choice);
			cadre_menu();
			int choice_adm;
			switch(choice)
			{
				case 1:Create_account();	break;
				case 2:Update_account();	break;
				case 3:Delete_account();	break;
				case 4:Consult_all_users();	break;
			}
			system("cls");
}
void 	Consult_fichiers ( void )
{
	cadre_menu();
	gotoxy(35,3);textcolor(6);printf("%c MENU ADMINISTATION %c",4,4);
			gotoxy(30,5);printf(" CONSULTER LES FICHIER:");
			gotoxy(30,7);textcolor(11);printf("1 - CONSULTAT SPECIFIC FILE");
			gotoxy(30,8);textcolor(11);printf("2 - ABOUT US");//
			gotoxy(30,10);textcolor(8);printf("3 - BACK TO MENU");
			gotoxy(35,13);textcolor(3);printf("YOUR CHOICE [    ]");
			int choice;
			gotoxy(50,13);scanf("%d",&choice);
			cadre_menu();
			int choice_adm;
			switch(choice)
			{
				case 1:Consult_file();break;//
				case 2:About_Us();break;//
			}
			system("cls");
}
void 	Menu_admin ( void )
{
		int id;
		bool trouve=false;
		do
		{	
			FILE *f = fopen ( "admin.txt", "r" );
			char pswrd;
			char pass[20]="";
			
			gotoxy(32,3);textcolor(3);printf(">>>  WELCOME TO DIRECTORY PLATFORM  <<<");
			gotoxy(30,7);textcolor(3);printf("LOGIN ACCOUNT");
			gotoxy(30,12);textcolor(4);printf("YOUR CRYPTED NUMBER:[                    ]");
		//hidding password while typing
						int i=0;
							while(pswrd!=13)
							{
								gotoxy(51+i,12);
								pswrd=getch();
								pass[i]=pswrd;
								printf("*");
								i++;
							}pass[i]='\0';
							pswrd='\0';
		//verification of admin crypted password
			char ligne [1000];
					fgets(ligne,1000,f);
					if( strstr(pass,ligne) )
							trouve = true;
				fclose (f);
		} while ( !trouve );
		cadre_menu();
		//choix du MENU
		int choice_admin=3;
		cadre_menu();
		while (choice_admin != 0)
		{
			choice_admin=M_admin();
			switch(choice_admin)
				{
				case 1:Gerer_compte();break;
				case 2:Consult_fichiers();break;
				case 0:choice_admin = 0;break;
				defeault:printf("RECHOOSE (1-2-0)");break;
				}
		}
		printf("LOG OUT");
}
void	Compte_creation( int id )
{
		cadre_menu() ;
		char entree  ;
		gotoxy(30,8);textcolor(6);printf("NUMERO DE COMPTE :");
		gotoxy(50,8);printf( "%d" ,id );
		gotoxy(49,10);textcolor(6);printf("[Courant] OU [Epargne]");
		gotoxy(33,11);textcolor(6);printf("TYPE DE COMPTE:");
		gotoxy(40,12);textcolor(6);printf("MONTANT:");
				x.id = id ;
				gotoxy(50,11);gets(x.type);
				gotoxy(50,12);scanf("%f",&x.montant);
			FILE	*f=fopen("comptes.DAT","a");
			while( entree != 13 )
			{
				fread( &x, sizeof(x), 1, f );
			gotoxy(25,15);
			textcolor(6);printf("NEW ACCOUNT :[ %d ][ compte : %s ][ %f DHs ]",x.id,x.type,x.montant);//affichage du nouveau compte
			 entree = getch();
			 	fwrite( &x, sizeof(x), 1, f );
			}
			fclose(f);
		system("cls");
}
void 	Create_account ( void )
{
	cadre_menu();
	bool	verification = false ;
	bool 	confirm_account 	= false ;//confirmation of account
	bool 	confirm_password	= false; //confirm of password
	int i = 0 ;
		do{
			 //compteur d'auto increment ID
			cadre_menu();
			gotoxy(35,3);textcolor(9);printf("<<< GERER LES COMPTES >>>");
			gotoxy(30,6);printf("CREATE NEW ACCOUNT:");
							FILE *f = fopen ( "utilisateurs.DAT", "r" );
							
		
							while( !feof(f) )
								{
									i++;//AUTO_incerement	
									fread( &u, sizeof(u) , 1, f);
									if( i !=  u.id )
										{
											gotoxy(30,8);textcolor(6);printf("NUMERO DE COMPTE :");
												gotoxy(50,8);printf("%d",i);
												u.id = i ;
												fclose(f);
												break;
										}	
								}
									fclose(f);
							gotoxy(60,8);textcolor(9);printf("%c AUTO_INCREMENT",17);
							gotoxy(44,9);textcolor(6);printf("NOM:");
							gotoxy(40,10);textcolor(6);printf("ADRESSE:");
						
								gotoxy(50,9);fflush(stdin);gets(u.nom);
								gotoxy(50,10);gets(u.adresse);
							
							gotoxy(31,14);textcolor(6);printf("NOUVEAUX MOT DE PASSE :");
							gotoxy(28,16);textcolor(3);printf("CONFIRMER LE MOT DE PASSE:");
						do
						{
							char pswrd[20]="",pswrd_confirm[20]="";
							char taper ;
							int i=0;
							while(taper != 13)	 // hidding password
								 {
											gotoxy(55+i,14);
											taper=getch();
											pswrd[i]=taper;
											printf("*");
											i++;
								 }
							pswrd[i-1]='\0';
							taper='\0';
							i = 0;
							while(taper != 13)	 // hidding password
								 {
											gotoxy(55+i,16);
											taper=getch();
											pswrd_confirm[i]=taper;
											printf("*");
											i++;
								 }
							pswrd_confirm[i-1]='\0';
							taper='\0';
							if(strcmp(pswrd,pswrd_confirm)==0)
								{	
									strcpy(u.password,pswrd_confirm);//
									confirm_password = true;//
								}
							else {
							gotoxy(55,17);textcolor(4);printf("RESSAYER...");
							gotoxy(55,14);printf("                      ");//suppression du ancien etoile (*)
							gotoxy(55,16);printf("                      ");//par des espaces 
								}
						}while(!confirm_password);
					
					gotoxy(30,18);textcolor(6);printf("CONFIRM THE CREATION ( C / N ) ? : ");
					gotoxy(30,18);char C = getch();
					if(C == 'c' || C == 'C')
						{
							textcolor(4);printf("C");
							confirm_account = true ;
						}
		}while(	!confirm_account );//confirmation of creation
			cadre_menu();
			if(confirm_account == true)
			{
			char entree ;//confirmation daffichage
			FILE	*f=fopen("utilisateurs.DAT","a");
					Compte_creation ( u.id ); //insertion des donnees au fichier compte(id,type,montant)
				fread  ( &u, sizeof(u), 1, f );
			 	fwrite ( &u, sizeof(u), 1, f );
			fclose(f);
			}
		system("cls");
		Gerer_compte();// back to menu
}
void	Update_option ( char choice, int id_compte )
{
	char parametre [1000];
	int pos_id ;
	int i=0;
	FILE *f = fopen ( "utilisateurs.DAT", "r" );
	fread(&u,sizeof(u),1,f);
		while(!feof(f))
		{
			if( id_compte == u.id ) pos_id = i;
			fread(&u,sizeof(u),1,f);
			i++;
		}
		fclose(f);
		switch(choice)
		{
			case 'N':gotoxy(25,13);printf("NEW NAME:");gets(parametre);strcpy(u.nom,parametre);break;//Nom
			case 'M':gotoxy(25,13);printf("NEW PASSWORD:");gets(parametre);strcpy(u.password,parametre);break;//MotDePasse
			case 'A':gotoxy(25,13);printf("NEW ADRESSE:");gets(parametre);strcpy(u.adresse,parametre);break;//Adresse
			//case 'T':;break;//Type
			default:;break;
		}
			f = fopen ( "utilisateurs.DAT", "r+b" );
				fseek( f, pos_id*sizeof(u), SEEK_CUR);
				fwrite(&u, sizeof(u), 1, f);
				system("cls");
				cadre_menu();
				gotoxy(30,10);textcolor(4);printf("CHANGE SUCCEFFULLY");
				getch();
				fclose(f);
}
void 	Update_account ( void )
{
	cadre_menu();
	int id_compte;
	char choice ;
	bool trouve = false;
		gotoxy(40,3);textcolor(9);printf("%c MENU ADMIN %c",1,1);
		gotoxy(35,5);printf("NUMERO DU COMPTE:");scanf("%d",&id_compte);//le id du compte concernee
		gotoxy(35,6);printf(" CHOOSE YOUR OPTION : ");//nom,motdepasse,adresse,type
		gotoxy(34,9);textcolor(6);printf("[   changer le ");textcolor(4);printf("N");textcolor(6);printf("om    ]");//
		gotoxy(34,10);textcolor(6);printf("[   changer l'");textcolor(4);printf("A");textcolor(6);printf("dresse   ]");//
		//gotoxy(34,11);textcolor(6);printf("[   changer le ");textcolor(4);printf("T");textcolor(6);printf("ype   ]");//
		gotoxy(34,11);textcolor(6);printf("[   changer le");textcolor(4);printf("M");textcolor(6);printf("ot de passe  ]");//
		while(!trouve)
		{
		gotoxy(41,15);textcolor(6);printf("<CHOICE :   >");//
			gotoxy(51,15); choice = getch() ;printf("%c",choice);
			char pswrd;
			char pass[20];
		gotoxy(30,17);textcolor(4);printf("YOUR CRYPTED NUMBER:[                    ]");
	//hidding password while typing
					int i=0;
						while(pswrd!=13)
						{
							gotoxy(51+i,17);
							pswrd=getch();
							pass[i]=pswrd;
							printf("*");
							i++;
						}pass[i]='\0';
						pswrd='\0';
	//verification of admin crypted password
		char ligne [1000];
		FILE *f=fopen("admin.txt","r");
				fgets(ligne,1000,f);
				if( strstr(pass,ligne) )
						trouve = true;
			fclose (f);
		}
			if(trouve)
			{
					Update_option(choice,id_compte);//loption du changement concernee	
			}
			
		
	system("cls");
}
void	del_archive   ( int id )
{
	//suppression du compte au fichier "utilisateurs""comptes""transactions""journalisation"
	FILE *f, *t, *a;
		//utilisateurs file
	f = fopen ( "utilisateurs.dat", "r" );
	t = fopen ( "temporary_file.dat", "w" );
	a = fopen ( "archives.dat", "a" );
		fread( &u, sizeof(u), 1, f );
		while(!feof(f))
		{
			if( id != u.id )
				fwrite(&u, sizeof(u), 1, t );
			else
				fwrite( &u, sizeof(u), 1, a );
				fread( &u, sizeof(u), 1, f );	
		}
		fclose(f);
		fclose(t);
		fclose(a);
		remove("utilisateurs.dat");
		rename("temporary_file.dat", "utilisateurs.dat");
		//comptes files
		f = fopen ( "comptes.dat", "r" );
		t = fopen ( "temporary_file.dat", "w" );
		fread( &x, sizeof(x), 1, f );
		while(!feof(f))
		{
			if( id != x.id )
				fwrite(&x, sizeof(x), 1, t );	
			fread( &x, sizeof(x), 1, f );	
		}
		fclose(f);
		fclose(t);
		remove("comptes.dat");
		rename("temporary_file.dat", "comptes.dat");
		//transaction file
		f = fopen ( "transactions.dat", "r" );
		t = fopen ( "temporary_file.dat", "w" );
		fread( &Tu, sizeof(Tu), 1, f );
		while(!feof(f))
		{
			if( id != Tu.id )
				fwrite(&Tu, sizeof(Tu), 1, t );	
			fread( &Tu, sizeof(Tu), 1, f );	
		}
		fclose(f);
		fclose(t);
		remove("transactions.dat");
		rename("temporary_file.dat", "transactions.dat");
		//sauvgarder au journalisation file
		time_t orig_format;
		time(&orig_format);//time function
		FILE *r = fopen("journalisation.DAT","a");
 		fread( &Ju, sizeof(Ju), 1, r);
 		sprintf(Ju.evenement,"Suppression du compte numero %d",id);
 		strcpy(Ju.date,asctime(gmtime(&orig_format)));
 		fwrite(&Ju,sizeof(Ju),1,r);
 		fclose(r);
		//success du suppression sur toutes les files
		cadre_menu();
		gotoxy(30,8);textcolor(4);printf("[OPERATION IS DONE SUCCEFULLY]");
		getch();
		system("cls");
}
void 	Delete_account ( void )
{
	cadre_menu();
		//choisir le id concernee
		cadre_menu();
	int id_compte;
	bool exist = false ;//id a supprimer
	bool trouve = false ;// admin password a confirmer la suppression
		gotoxy(40,3);textcolor(9);printf("%c MENU ADMIN %c",1,1);
		gotoxy(35,5);textcolor(6);printf("[  DELETE ACCOUNT  ]");//nom,motdepasse,adresse,type
		gotoxy(35,8);printf("NUMERO DU COMPTE:");//le id du compte concernee
		
		// si le compte concernee existe deja
		while(!exist)
			{
				gotoxy( 53, 8 ); scanf( "%d", &id_compte );
				FILE *f = fopen ( "utilisateurs.DAT", "r" );
				fread( &u, sizeof(u), 1, f );
				while( !feof(f) )
				{
					if ( id_compte == u.id ) 
							exist = true ;
					fread( &u, sizeof(u), 1, f );
				}
				fclose(f);
				break;
			}
		if(exist)
			{
				//confirmation du admin par son password
				while(!trouve)
						{
						
							char pswrd;
							char pass[20];
						gotoxy(30,17);textcolor(4);printf("YOUR CRYPTED NUMBER:[                    ]");
					//hidding password while typing
									int i=0;
										while(pswrd!=13)
										{
											gotoxy(51+i,17);
											pswrd=getch();
											pass[i]=pswrd;
											printf("*");
											i++;
										}pass[i]='\0';
										pswrd='\0';
					//verification of admin crypted password
						char ligne [1000];
						FILE *f=fopen("admin.txt","r");
								fgets(ligne,1000,f);
								if( strstr(pass,ligne) )
										trouve = true;
							fclose (f);
						}
				if(trouve)
					{
							del_archive(id_compte);//parametre de supprimation	et  archive
					}
			}
		else
			{
				gotoxy(35,10);textcolor(4);printf("ACCOUNT DO NOT EXIST");
				getch();
			}
		system("cls");
}
void 	Consult_all_users ( void )
{
	cadre_users();
	gotoxy(40,3);textcolor(9);printf("%c MENU ADMIN %c",1,1);
		gotoxy(35,5);printf("CONSULTATION DU COMPTES:");//le id du compte concernee
		FILE *f= fopen("utilisateurs.DAT","r");
		int i=0;
		fread(&u,sizeof(u),1,f);
			while(!feof(f))
			{
				textcolor(6);
					gotoxy(7,13+i);printf("%d",u.id);
					gotoxy(17,13+i);puts(u.nom);
					gotoxy(47,13+i);puts(u.adresse);
					fread(&u,sizeof(u),1,f);
					i++;
			}
			gotoxy(42,30);getch();
			fclose(f);
	system("cls");
}
void	table_archives	( void )
{
			system("cls");
			for(int i=1;i<=31;i++)
		{
			for(int j=1;j<=100;j++)
			{
				if(i == 1 || i == 31){
				gotoxy(j,i);textcolor(9);printf("#");}
				if(j == 1 || j == 100){
				gotoxy(j,i);textcolor(9);printf("#");}
			}
		}
	//	gotoxy(35,3);	textcolor(6);	printf("[ "); textcolor(4); printf("R"); textcolor(6); printf("elever bancaire ]");
	//	gotoxy(25,7);	textcolor(6);	printf("DATE   :" );
	//	gotoxy(25,8);	textcolor(6);	printf("COMPTE :" );
		gotoxy(5,10);	printf("+");	for(int i=1;i<=79;i++)	printf("*");printf("+");
		gotoxy(5,11);	printf("| NUMERO");	gotoxy(14,11);printf("| NOM");	gotoxy(45,11);printf("| ADRESSE");gotoxy(85,11);printf("|");
		gotoxy(5,12);	printf("+");	for(int i=1;i<=79;i++)	printf("*");printf("+");
						for(int i=1 ; i<=15 ;i++)
						{
							for(int j=1;j<=81;j++)
							{
								if( j==1 || j==10 || j==41 || j==81)
								{
									gotoxy(j+4,i+12);	printf("|");
								}
								if ( i == 15 ) printf("*");
							}
						}
					gotoxy(40,3);textcolor(9);printf("%c MENU ADMIN %c",1,1);
		gotoxy(35,5);printf("CONSULTATION D'ARCHIVES:");//le id du compte concernee
		FILE *f= fopen("archives.DAT","r");
		int i=0;
		fread(&u,sizeof(u),1,f);
			while(!feof(f))
			{
				textcolor(6);
					gotoxy(7,13+i);printf("%d",u.id);
					gotoxy(17,13+i);puts(u.nom);
					gotoxy(47,13+i);puts(u.adresse);
					fread(&u,sizeof(u),1,f);
					i++;
			}
	//	gotoxy(25,30);	textcolor(6);	printf("[ "); textcolor(4); printf("I"); textcolor(6); printf("mprimer ]");//Imprimer
			gotoxy(40,30);	textcolor(6);	printf("[ "); textcolor(4); printf("R"); textcolor(6); printf("etour au menu principal ]");//affichage du nouveau compte
			gotoxy(2,29);textcolor(9);printf("made by :");gotoxy(2,30);textcolor(2);printf("Abdellah Bounab");
			gotoxy(42,30);getch();
		fclose(f);
		system("cls");
}
void	table_transactions	( void )
{
				system("cls");
			for(int i=1;i<=31;i++)
		{
			for(int j=1;j<=100;j++)
			{
				if(i == 1 || i == 31){
				gotoxy(j,i);textcolor(9);printf("#");}
				if(j == 1 || j == 100){
				gotoxy(j,i);textcolor(9);printf("#");}
			}
		}
		gotoxy(5,10);	printf("+");	for(int i=1;i<=92;i++)	printf("*");printf("+");
		gotoxy(5,11);	printf("| NUMERO");	gotoxy(14,11);printf("| DATE");	gotoxy(45,11);printf("| TYPE");gotoxy(55,11);printf("|  SOLDE");gotoxy(85,11);printf("|  MONTANT");gotoxy(98,11);printf("|");
		gotoxy(5,12);	printf("+");	for(int i=1;i<=92;i++)	printf("*");printf("+");
						for(int i=1 ; i<=15 ;i++)
						{
							for(int j=1;j<=94;j++)
							{
								if( j==1 || j==10 || j==41 || j==51 || j==81 || j==94)
								{
									gotoxy(j+4,i+12);	printf("|");
								}
								if ( i == 15 ) printf("*");
							}
						}
					gotoxy(40,3);textcolor(9);printf("%c MENU ADMIN %c",1,1);
		gotoxy(35,5);printf("CONSULTATION DE TRANSACTIONS:");//le id du compte concernee
		FILE *f= fopen("transactions.DAT","r");
		int i=0;
		fread(&Tu,sizeof(Tu),1,f);
			while(!feof(f))
			{
				textcolor(6);
					gotoxy(7,13+i);printf("%d",Tu.id);
					gotoxy(17,13+i);puts(Tu.time);
					gotoxy(47,13+i);puts(Tu.type_histoy);
					gotoxy(57,13+i);printf("%.2f",Tu.solde);
					gotoxy(87,13+i);printf("%.2f",Tu.montant);
					fread(&Tu,sizeof(Tu),1,f);
					i++;
			}
	//	gotoxy(25,30);	textcolor(6);	printf("[ "); textcolor(4); printf("I"); textcolor(6); printf("mprimer ]");//Imprimer
			gotoxy(40,30);	textcolor(6);	printf("[ "); textcolor(4); printf("R"); textcolor(6); printf("etour au menu principal ]");//affichage du nouveau compte
			gotoxy(2,29);textcolor(9);printf("made by :");gotoxy(2,30);textcolor(2);printf("Abdellah Bounab");
			gotoxy(42,30);getch();
		fclose(f);
		system("cls");
}
void	table_journal ( void )//
{
	
				system("cls");
			for(int i=1;i<=31;i++)
		{
			for(int j=1;j<=120;j++)
			{
				if(i == 1 || i == 31){
				gotoxy(j,i);textcolor(9);printf("#");}
				if(j == 1 || j == 120){
				gotoxy(j,i);textcolor(9);printf("#");}
			}
		}
	//	gotoxy(35,3);	textcolor(6);	printf("[ "); textcolor(4); printf("R"); textcolor(6); printf("elever bancaire ]");
	//	gotoxy(25,7);	textcolor(6);	printf("DATE   :" );
	//	gotoxy(25,8);	textcolor(6);	printf("COMPTE :" );
		gotoxy(5,10);	printf("+");	for(int i=1;i<=92;i++)	printf("*");printf("+");
		gotoxy(5,11);	printf("| EVENEMENT");	gotoxy(80,11); printf("|  DATE");gotoxy(98,11);printf("|");
		gotoxy(5,12);	printf("+");	for(int i=1;i<=92;i++)	printf("*");printf("+");
						for(int i=1 ; i<=15 ;i++)
						{
							for(int j=1;j<=94;j++)
							{
								if( j==1|| j==76 || j==94)
								{
									gotoxy(j+4,i+12);	printf("|");
								}
								if ( i == 15 ) printf("*");
							}
						}
					gotoxy(40,3);textcolor(9);printf("%c MENU ADMIN %c",1,1);
		gotoxy(35,5);printf("CONSULTATION DE JOURNAL:");//le id du compte concernee
		FILE *f= fopen("journalisation.DAT","r");
		int i=0;
		fread(&Ju,sizeof(Ju),1,f);
			while(!feof(f))
			{
				textcolor(6);//Ju
					gotoxy(7,13+i);puts(Ju.evenement);
					gotoxy(82,13+i);puts(Ju.date);
					fread(&Ju,sizeof(Ju),1,f);
					i++;
			}
	//	gotoxy(25,30);	textcolor(6);	printf("[ "); textcolor(4); printf("I"); textcolor(6); printf("mprimer ]");//Imprimer
			gotoxy(40,30);	textcolor(6);	printf("[ "); textcolor(4); printf("R"); textcolor(6); printf("etour au menu principal ]");//affichage du nouveau compte
			gotoxy(2,29);textcolor(9);printf("made by :");gotoxy(2,30);textcolor(2);printf("Abdellah Bounab");
			gotoxy(42,30);getch();
		fclose(f);
		system("cls");
}
void	table_comptes ( void )//
{
				system("cls");
			for(int i=1;i<=31;i++)
		{
			for(int j=1;j<=100;j++)
			{
				if(i == 1 || i == 31){
				gotoxy(j,i);textcolor(9);printf("#");}
				if(j == 1 || j == 100){
				gotoxy(j,i);textcolor(9);printf("#");}
			}
		}
	//	gotoxy(35,3);	textcolor(6);	printf("[ "); textcolor(4); printf("R"); textcolor(6); printf("elever bancaire ]");
	//	gotoxy(25,7);	textcolor(6);	printf("DATE   :" );
	//	gotoxy(25,8);	textcolor(6);	printf("COMPTE :" );
		gotoxy(5,10);	printf("+");	for(int i=1;i<=79;i++)	printf("*");printf("+");
		gotoxy(5,11);	printf("| NUMERO");	gotoxy(14,11);printf("| TYPE");	gotoxy(45,11);printf("| MONTANT");gotoxy(85,11);printf("|");
		gotoxy(5,12);	printf("+");	for(int i=1;i<=79;i++)	printf("*");printf("+");
						for(int i=1 ; i<=15 ;i++)
						{
							for(int j=1;j<=81;j++)
							{
								if( j==1 || j==10 || j==41 || j==81)
								{
									gotoxy(j+4,i+12);	printf("|");
								}
								if ( i == 15 ) printf("*");
							}
						}
					gotoxy(40,3);textcolor(9);printf("%c MENU ADMIN %c",1,1);
		gotoxy(35,5);printf("CONSULTATION DES COMPTES:");//le id du compte concernee
		FILE *f= fopen("comptes.DAT","r");
		int i=0;
		fread(&x,sizeof(x),1,f);
			while(!feof(f))
			{
				textcolor(6);
					gotoxy(7,13+i);printf("%d",x.id);
					gotoxy(17,13+i);puts(x.type);
					gotoxy(47,13+i);printf("%.2f",x.montant);
					fread(&x,sizeof(x),1,f);
					i++;
			}
	//	gotoxy(25,30);	textcolor(6);	printf("[ "); textcolor(4); printf("I"); textcolor(6); printf("mprimer ]");//Imprimer
			gotoxy(40,30);	textcolor(6);	printf("[ "); textcolor(4); printf("R"); textcolor(6); printf("etour au menu principal ]");//affichage du nouveau compte
			gotoxy(2,29);textcolor(9);printf("made by :");gotoxy(2,30);textcolor(2);printf("Abdellah Bounab");
			gotoxy(42,30);getch();
		fclose(f);
		system("cls");
}
void 	Consult_file ( void )
{
	cadre_menu();
		int choice ;
		bool trouve = false;
			gotoxy(40,3);textcolor(9);printf("%c MENU ADMIN %c",1,1);
			gotoxy(35,6);printf(" CHOOSE YOUR OPTION : ");//nom,motdepasse,adresse,type
			gotoxy(34,8);textcolor(11);printf("[  FILE 1:");textcolor(6);printf("  Utilisateurs.dat");textcolor(11);printf("    ]");
			gotoxy(34,9);textcolor(11);printf("[  FILE 2:");textcolor(6);printf("  Comptes.dat");textcolor(11);printf("         ]");
			gotoxy(34,10);textcolor(11);printf("[  FILE 3:");textcolor(6);printf("  Transactions.dat");textcolor(11);printf("    ]");
			gotoxy(34,11);textcolor(11);printf("[  FILE 4:");textcolor(6);printf("  Journalisations.dat");textcolor(11);printf(" ]");
			gotoxy(34,12);textcolor(11);printf("[  FILE 5:");textcolor(6);printf("  Archives.dat");textcolor(11);printf("        ]");
			gotoxy(34,13);textcolor(8);printf("[      0 - Retour au Menu       ]");
			gotoxy(41,15);textcolor(6);printf("<CHOICE :   >");gotoxy(51,15); scanf("%d",&choice);
			if(choice != 0)
				{
				while(!trouve)
				{
					char pswrd;
					char pass[20];
				gotoxy(30,17);textcolor(4);printf("YOUR CRYPTED NUMBER:[                    ]");
			//hidding password while typing
							int i = 0 ;
								while( pswrd != 13 )
								{
									gotoxy ( 51+i, 17 );
									pswrd = getch();
									pass[i] = pswrd;
									printf( "*" );
									i++ ;
								}
								pass[i] = '\0' ;
								pswrd = '\0' ;
			//verification of admin crypted password
				char ligne [1000];
				FILE *f= fopen ( "admin.txt", "r" );
						fgets( ligne, 1000, f );
						if( strstr( pass, ligne ) )
								trouve = true;
					fclose ( f );
				}
					if(trouve)
					{
							switch(choice)
							{
								case 1:cadre_users();Consult_all_users();break;
								case 2:table_comptes();break;
								case 3:table_transactions();break;
								case 4:table_journal();break;
								case 5:table_archives();break;
							}
					}
			 	}
		system("cls");
}
void 	About_Us ( void )//
{
	system("cls");
		gotoxy(40,3);textcolor(9);printf("[  ABOUT US  ]");
		textcolor(11);//
		FILE *f=fopen("about_us.txt","r");
		char ligne [1000];
		int i=0;
		while(!feof(f))
		{
			fgets(ligne,1000,f);
			gotoxy(3,6+i); puts(ligne);
			i++;
		}
		gotoxy(40,i+6+2);textcolor(9);printf("[  BACK TO MENU  ]");
		getch();
		fclose(f);
			
	system("cls");
}
void 	cadre_menu ( void )
{
	system("cls");
			for(int i=1;i<=20;i++)
		{
			for(int j=1;j<=100;j++)
			{
				if(i == 1 || i == 20){
				gotoxy(j,i);textcolor(9);printf("#");}
				if(j == 1 || j == 100){
				gotoxy(j,i);textcolor(9);printf("#");}
			}
		}
		gotoxy(2,18);textcolor(9);printf("made by :");gotoxy(2,19);textcolor(2);printf("Abdellah Bounab");
}
void 	cadre_users ( void )
{
		system("cls");
			for(int i=1;i<=31;i++)
		{
			for(int j=1;j<=100;j++)
			{
				if(i == 1 || i == 31){
				gotoxy(j,i);textcolor(9);printf("#");}
				if(j == 1 || j == 100){
				gotoxy(j,i);textcolor(9);printf("#");}
			}
		}
		gotoxy(5,10);	printf("+");	for(int i=1;i<=79;i++)	printf("*");printf("+");
		gotoxy(5,11);	printf("| NUMERO");	gotoxy(14,11);printf("| NOM");	gotoxy(45,11);printf("| ADRESSE");gotoxy(85,11);printf("|");
		gotoxy(5,12);	printf("+");	for(int i=1;i<=79;i++)	printf("*");printf("+");
						for(int i=1 ; i<=15 ;i++)
						{
							for(int j=1;j<=81;j++)
							{
								if( j==1 || j==10 || j==41 || j==81)
								{
									gotoxy(j+4,i+12);	printf("|");
								}
								if ( i == 15 ) printf("*");
							}
						}
	//	gotoxy(25,30);	textcolor(6);	printf("[ "); textcolor(4); printf("I"); textcolor(6); printf("mprimer ]");//Imprimer
		gotoxy(40,30);	textcolor(6);	printf("[ "); textcolor(4); printf("R"); textcolor(6); printf("etour au menu principal ]");//affichage du nouveau compte
		gotoxy(2,29);textcolor(9);printf("made by :");gotoxy(2,30);textcolor(2);printf("Abdellah Bounab");
}
