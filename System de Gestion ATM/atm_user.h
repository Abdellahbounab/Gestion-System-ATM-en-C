#include <stdio.h>
#include <myconio.h>
#include <conio.h>
#include <time.h>


void 	cadre_              ( void );
void 	cadre_transaction 	( void );
void 	Consult_solde 		( int );
void	Confirm_transaction	( int, float, float, char);
void 	Retirer_argent  	( int );
void	   Retire  			   ( int, float, int );//sous_program
void 	Deposer_argent  	( int );
void 	   Depose  		       ( int, float, int );
void 	Virement_bancaire  	( int );
void 	   Virement		  	   ( int, int, float, int );
int	       Benificier_transfer ( int, float );
void 	Releve_bancaire  	( int );//
void	Changer_mot_de_pass ( int );
void 	   password_change	   ( int, char, int );
void 	Menu_user  			( void );
char 	Menu_princip  		( void );


void 	Consult_solde ( int id )
{
	FILE *f = fopen( "comptes.DAT", "r" );
		cadre_();
		char retour ;//option de retour au menu
		float montant_deposer;
			while( !feof(f) )
			{
				fread( &x, sizeof(x) , 1, f);
				if( id == x.id )
				{
						while( retour != 13 )
					{
					cadre_();
					gotoxy(37,3);textcolor(6);printf("[ ");textcolor(4);printf("C");textcolor(6);printf("onsulter le solde ]");
					gotoxy(25,7);textcolor(14);printf("SOLDE DISPONIBLE SUR LE COMPTE NUMERO : [ %d ]",x.id);
					gotoxy(30,10);textcolor(11);printf("LE COMPTE DU TYPE : ");puts(x.type);
					gotoxy(40,12);textcolor(11);printf("[ %.3f DHs ]", x.montant );//affichage du nouveau compte
					gotoxy(35,15);textcolor(6);printf("[ ");textcolor(4);printf("R");textcolor(6);printf("etour au menu principal ]");//affichage du nouveau compte
					gotoxy(34,15);textcolor(4); printf("%c",16);gotoxy(63,15);printf("%c",17);retour = getch() ;
					}	
					break;	
				}	
			}
		fclose(f);
	system("cls");
}
void	Confirm_transaction	( int id, float montant, float new_sold, char type[20] )
{
		cadre_();
		char event[1000];
		time_t orig_format;
		time(&orig_format);//time function	
		FILE *r = fopen("journalisation.DAT","a");
		fread( &Ju, sizeof(Ju), 1, r);
		strcpy(Ju.evenement,type);
 		sprintf(event," fais avec succeess depuis le numéro de compte %d ",Tub.id);
 		strcat(Ju.evenement,event);
 		strcpy(Ju.date,asctime(gmtime(&orig_format)));
 		fwrite(&Ju,sizeof(Ju),1,r);
 		fclose(r);
		char retour ;//option de retour au menu
						while( retour != 13 )
					{
					cadre_();
					gotoxy(35,3);textcolor(6);printf("[ ");textcolor(4);printf("C");textcolor(6);printf("onfirmation de transaction ]");
					gotoxy(38,7);textcolor(14);printf("   COMPTE NUMBER : [ %d ]",id);
					gotoxy(25,10);textcolor(11);printf("TYPE DE TRANSACTION :    ");puts(type);
					gotoxy(37,11);textcolor(11);printf("MONTANT : [ %.3f DHs ]", montant );//affichage du nouveau compte
					gotoxy(36,12);textcolor(11);printf("NEW SOLD : [ %.3f DHs ]", new_sold );
					gotoxy(45,15);textcolor(6);printf("[ ");textcolor(4);printf("C");textcolor(6);printf("ontinuer ]");//affichage du nouveau compte
					gotoxy(44,15);textcolor(4); printf("%c",16);gotoxy(58,15);printf("%c",17);retour = getch() ;
					}
//	system("cls");
}
void	Retire ( int id, float montant_ajoute ,int pos_i )
{
//	struct		Journalisation{
//	char	evenement[1000];
//	char	date[20];
//	} Ju ;
	FILE *f = fopen( "comptes.DAT", "r+b"  );
	time_t orig_format;
	time(&orig_format);//time function			
 		fseek(f, pos_i*sizeof(x), SEEK_CUR);
 		xUpdated = x ;
 	//	fread ( &Tu , sizeof(Tu), 1, g);
 		char type [10] ="RETRAIT" ;
 		char transaction_type[10]="CREDIT";
 		if(xUpdated.montant<montant_ajoute)
 			{
 				FILE *r = fopen("journalisation.DAT","a");
 				fread( &Ju, sizeof(Ju), 1, r);
 				sprintf(Ju.evenement,"Retire de l'argent est echouee au compte %d",xUpdated.id);
 				strcpy(Ju.date,asctime(gmtime(&orig_format)));
 				fwrite(&Ju,sizeof(Ju),1,r);
 				fclose(r);
 				gotoxy(25,10);textcolor(4);printf("[ SOLDE INSUFFICANT : %.3f DHs ]", xUpdated.montant );
			}
		else
			{
		 		xUpdated.montant -= montant_ajoute ;
		 		fwrite(	&xUpdated, sizeof(xUpdated), 1, f );
		 	 FILE *g = fopen( "transactions.DAT","a");
		 		fread( &Tub, sizeof(Tub), 1, g );
		 		Tub.solde = xUpdated.montant ;
 				Tub.id = pos_i+1 ; // le id de transaction
		 		Tub.montant = montant_ajoute ; // montant de transaction
		 		strcpy(Tub.time,asctime(gmtime(&orig_format)));// date et time de transaction
 				strcpy(Tub.type_histoy,transaction_type); //type de transaction
 				fwrite( &Tub, sizeof(Tub), 1, g );
		 		Confirm_transaction	( xUpdated.id, montant_ajoute, xUpdated.montant, type);
		 		char entree = getch();
		 		fclose(g);
  				fclose(f);
  				
			}
    
}
void 	Retirer_argent ( int id )
{
		FILE *f = fopen( "comptes.dat", "r" );
		cadre_();
		char retour ;//option de retour au menu
		int pos_i=0; // position des donnes sur le fichier
		float montant_retirer;
			while( !feof(f) )
			{
				fread( &x, sizeof(x) , 1, f);
				if( id == x.id )
				{
						cadre_();
						gotoxy(35,3);	textcolor(6);	printf("[ "); textcolor(4); printf("R"); textcolor(6); printf("etirer de l'argent ]");
						gotoxy(25,7);	textcolor(14);	printf("Retirer de l'argent du compte numéro : [ %d ]", x.id );
						if( strcmp (x.type,"Epargne") == 0 || strcmp (x.type,"epargne") == 0 ) // verification si le compte est de type eparge
						{
							gotoxy(40,12);	textcolor(4);	printf("IMPOSSIBLE DE RETIRER (COMPTE EPARGE)");
						}
						else
						{
						gotoxy(40,12);	textcolor(6);	printf("Montant a retirer : [                DHs ]");
						gotoxy(61,12);	textcolor(4);	scanf("%f",&montant_retirer);
						gotoxy(35,15);	textcolor(6);	printf("[ "); textcolor(4); printf("C"); textcolor(6); printf("onfirmer ]");//confirmation
						}
						gotoxy(35,16);	textcolor(6);	printf("[ "); textcolor(4); printf("R"); textcolor(6); printf("etour au menu principal ]");
						gotoxy(37,16);	retour = getch() ;
						switch ( retour )
								{
									case 'R':	gotoxy(37,16);	textcolor(6);	printf("R");	retour='R';						 	break;
									case 'C':   gotoxy(37,15);	textcolor(6);	printf("C");	Retire(u.id,montant_retirer,pos_i);	break;
									default :	printf("C ou R");				break;
								}
						break;
				}	
				pos_i ++;	
			}
		fclose(f);
	system("cls");
}
void 	Depose ( int id, float montant_ajoute ,int pos_i )
{
	    FILE *f = fopen( "comptes.dat",     "r+b");
	    time_t orig_format;
		time(&orig_format);//time function	
	    char type [20] = "DEPOSITION";
	    char transaction_type [10] ="DEBIT";
		 		fseek( f, pos_i*sizeof(x), SEEK_CUR);
		 		xUpdated = x ;	//incrementation dune autre element du type (USER struct) avec les donnees de lelement precedant de la meme struct
		 		xUpdated.montant += montant_ajoute ;
		 		fwrite(	&xUpdated, sizeof(xUpdated), 1, f );
		 	FILE *g = fopen( "transactions.DAT","a");
		 		fread( &Tub, sizeof(Tub), 1, g );
		 		Tub.solde = xUpdated.montant ;
 				Tub.id = pos_i+1 ; // le id de transaction
		 		Tub.montant = montant_ajoute ; // montant de transaction
		 		strcpy(Tub.time,asctime(gmtime(&orig_format)));// date et time de transaction
 				strcpy(Tub.type_histoy,transaction_type); //type de transaction
 				fwrite( &Tub, sizeof(Tub), 1, g );
		        Confirm_transaction	( xUpdated.id, montant_ajoute, xUpdated.montant, type);
		       	char entree = getch();//affichage du nouveau solde et expectation du (entree)
	    fclose(f);
	    fclose(g);
}
void 	Deposer_argent ( int id )
{
		FILE *f = fopen( "comptes.DAT", "r" );
		cadre_();
		int pos_i=0; // position des donnes sur le fichier
		char retour ;//option de retour au menu
		float montant_deposer;
			while( !feof(f) )
			{
				fread( &x, sizeof(x) , 1, f);
				if( id == x.id )
				{
						cadre_();
						gotoxy(35,3);	textcolor(6);	printf("[ "); textcolor(4); printf("D"); textcolor(6); printf("eposer de l'argent ]");
						gotoxy(25,7);	textcolor(4);	printf("DEPOSER DE L'ARGENT SUR LE COMPTE NUMERO : [ %d ]", x.id );
						gotoxy(40,12);	textcolor(6);	printf("Montant a deposer : [                DHs ]");
						gotoxy(61,12);	textcolor(4);	scanf("%f",&montant_deposer);
						gotoxy(35,15);	textcolor(6);	printf("[ "); textcolor(4); printf("C"); textcolor(6); printf("onfirmer ]");//confirmation
						gotoxy(35,16);	textcolor(6);	printf("[ "); textcolor(4); printf("R"); textcolor(6); printf("etour au menu principal ]");//affichage du nouveau compte
						retour = getch() ;
						switch ( retour )
								{
									case 'R':	gotoxy(37,16);	textcolor(6);	printf("R");	retour='R';						break;
									//C : CONFIRMATION pour faire le traitement requies
									case 'C':   gotoxy(37,15);	textcolor(6);	printf("C");	Depose(u.id,montant_deposer,pos_i);	break;
									default :	printf("C ou R");				break;
								}
						break;		
				}
				pos_i ++;	
			}
		fclose(f);
	system("cls");
}
int 	Benificier_transfer ( int id_benificier, float montant_ajoute )
{
	FILE *f = fopen( "comptes.dat", "r" );
		cadre_  ();
		bool 	not_found = false ;
		int 	exist ;
		time_t orig_format;
		time ( &orig_format );//time function
		char 	transaction_type[10]= "DEBIT"; 
		int 	pos_i=1; // position des donnes sur le fichier
			while( !feof(f) )
			{
				fread( &T_x, sizeof(T_x) , 1, f);
				if( id_benificier != T_x.id )	pos_i++;
				else break;
			}
				if( pos_i < id_benificier ) not_found = true ;// si ce compte nexiste pas
			fclose ( f );
			if ( !not_found ) // si le compte benificier n'exist pas
			{
						pos_i--;
					f = fopen ( "comptes.dat", "r+b" );
					FILE *g = fopen( "transactions.DAT","a");
				 		fseek ( f, pos_i*sizeof(T_x), SEEK_CUR );
				 		fread( &Tb, sizeof(Tb), 1, g );
				 		Tb.id = pos_i + 1 ; // le id de transaction
				 		Transfer_x = T_x ;	// incrementation dune autre element du type (USER struct) avec les donnees de l'element precedant de la meme struct
				 		Transfer_x.montant += montant_ajoute ;
				 		Tb.solde = 	 Transfer_x.montant ;
				 		Tb.montant = montant_ajoute ;
				 		strcpy(Tb.type_histoy,transaction_type);
				 		strcpy(Tb.time,asctime(gmtime(&orig_format)));
				 		fwrite( &Tb, sizeof(Tb), 1, g );
				 		fread ( &Tb, sizeof(Tb), 1, g );
				 		exist = 1 ;
				 		fwrite ( &Transfer_x, sizeof(Transfer_x), 1, f );
				 		fclose ( f );
				 		fclose ( g );
			 }
			else 
			{
						gotoxy (50,12);	textcolor(4);	printf( "ACCOUNT DO NOT EXIST %d",pos_i );
						exist = 0 ;
						getch  () ;
			}
		return exist ;// 0 is not found , 1 is found
}
void 	Virement  ( int id, int id_benificier, float montant_ajoute ,int pos_i )
{
	FILE *f = fopen( "comptes.DAT", "r+b" );
    char type [20] = "VIREMENT";
    char transaction_type[10]="CREDIT";
    time_t orig_format;
	time(&orig_format);//time function
 		fseek( f, pos_i*sizeof(x), SEEK_CUR );
 		xUpdated = x ;	//incrementation dune autre element du type (Account struct) avec les donnees de lelement precedant de la meme struct
 		int exist = Benificier_transfer( id_benificier, montant_ajoute );
 		if ( exist == 1 )
 		{
		 		xUpdated.montant -= montant_ajoute ;
		 		fwrite(	&xUpdated, sizeof(xUpdated), 1, f );
		 	FILE *g = fopen( "transactions.DAT","a");
		 	FILE *r = fopen("journalisation.DAT","a");
		 		fread( &Tub, sizeof(Tub), 1, g );
		 		Tub.solde = xUpdated.montant ;
 				Tub.id = pos_i+1 ; // le id de transaction
		 		Tub.montant = montant_ajoute ; // montant de transaction
		 		strcpy(Tub.time,asctime(gmtime(&orig_format)));// date et time de transaction
 				strcpy(Tub.type_histoy,transaction_type); //type de transaction
 				fwrite( &Tub, sizeof(Tub), 1, g );
 				fread( &Ju, sizeof(Ju), 1, r);
 				sprintf(Ju.evenement,"Virement effectue depuis le numéro de compte %d vers le numéro de compte %d",Tub.id,id_benificier);
 				strcpy(Ju.date,asctime(gmtime(&orig_format)));
 				fwrite(&Ju,sizeof(Ju),1,r);
		        Confirm_transaction	( xUpdated.id, montant_ajoute, xUpdated.montant, type );
		       	char entree = getch();//affichage du nouveau solde et expectation du (entree)
	   	 	fclose(f);
	   	 	fclose(g);
	   	 	fclose(r);
    	}
}
void 	Virement_bancaire ( int id )
{
	FILE *f = fopen( "comptes.DAT", "r" );
		cadre_();
		int pos_i=0; // position des donnes sur le fichier
		char retour ;//option de retour au menu
		int compte_benificier;
		float montant_transferer;
			while( !feof(f) )
			{
				fread( &x, sizeof(x) , 1, f);
				if( id == x.id )
				{
							//verificcation si compte epargne ou courant
							if( strcmp(x.type,"Epargne") == 0 || strcmp(x.type,"epargne") == 0 ) 
							{
								gotoxy(25,7);	textcolor(4);	printf("IMPOSSIBLE COMPTE DE TYPE : ");puts(x.type);
							}
							else
							{
								cadre_();
								gotoxy(35,3);	textcolor(6);	printf("[  effectuer un "); textcolor(4); printf("V"); textcolor(6); printf("irement  ]");
								gotoxy(25,7);	textcolor(4);	printf("EFFECTUER UN VIREMENT DU COMPTE NUMERO : [ %d ]", x.id );
								gotoxy(28,12);	textcolor(6);	printf("Numero de compte benificier : [                    ]");
								gotoxy(61,12);	textcolor(4);	scanf("%d",&compte_benificier);
								//verification si le compte benificier et le meme que le compte concernee
									if(compte_benificier == x.id) 
									{
										gotoxy(40,13);	textcolor(4);	printf("IMPOSSIBLE (MEME COMPTE)");
									}
									else
									{
										gotoxy(38,13);	textcolor(6);	printf("Montant a deposer : [                 DHs]");
										gotoxy(61,13);	textcolor(4);	scanf("%f",&montant_transferer);//
										gotoxy(35,15);	textcolor(6);	printf("[ "); textcolor(4); printf("C"); textcolor(6); printf("onfirmer ]");//confirmation
									}
							}
						gotoxy(35,16);	textcolor(6);	printf("[ "); textcolor(4); printf("R"); textcolor(6); printf("etour au menu principal ]");//affichage du nouveau compte
						retour = getch() ;
						switch ( retour )
								{
									case 'R':	gotoxy(37,16);	textcolor(6);	printf("R");	retour='R';						break;
									//C : CONFIRMATION pour faire le traitement requies
									case 'C':   gotoxy(37,15);	textcolor(6);	printf("C");	Virement(x.id,compte_benificier,montant_transferer,pos_i);	break;
									default :	printf("C ou R");				break;
								}
						break;		
				}
				pos_i ++;	
			}
		fclose(f);
	system("cls");
}
void 	Releve_bancaire ( int id )//fread(double) to modifiy
{
	cadre_transaction();
	char retour ;
	time_t orig_format;
	time(&orig_format);//time function		
		FILE *f = fopen ( "transactions.DAT","r");
		int i	= 0 ;
		while( !feof( f ) )
			{
				fread( &Tu, sizeof(Tu), 1, f );
				if( id == Tu.id )
					{
						gotoxy(34,7);		puts(asctime(gmtime(&orig_format)));//date
						gotoxy(34,8);		printf("%d",Tu.id);//ID
						gotoxy(6,13+i);		puts(Tu.time);//time
						gotoxy(34,13+i);	puts(Tu.type_histoy);     //type
						gotoxy(47,13+i);	printf("$%.2f",Tu.montant);//montant
						gotoxy(67,13+i);	printf("%.2f DHs",Tu.solde);//solde
						i++ ; 
						fread( &Tu, sizeof(Tu), 1, f );
					}
		//		
			}
			fclose(f);
		gotoxy(28,30); retour = getch();
			switch(retour)
			{
				case 'I':gotoxy(27,30);textcolor(6);printf("I");break;//imprimer
				case 'R':break;
			}
	system("cls");
}
void 	password_change ( int id, char password[20], int pos_i )
{
	FILE *f = fopen( "utilisateurs.dat", "r+b" );
 		fseek(f, pos_i*sizeof(u), SEEK_CUR);
 		Updated = u ;
 		//comparing between ancient password and the new one
 		if( strcmp(Updated.password,password) == 0 )
 			{
 				 gotoxy(25,10);textcolor(4);printf("[ PASSWORDS ARE SIMILAR ]" );
			}
		else
			{
		 		strcpy( Updated.password,password); 
		 		fwrite(	&Updated, sizeof(Updated), 1, f );
		        gotoxy(25,10);textcolor(4);printf("[ YOUR NEW PASSWORD IS UPDATED SUCCESSFULLY ]");
			}
       	char entree = getch();
    fclose(f);
}
void 	Changer_mot_de_pass ( int id )
{
		FILE *f = fopen( "utilisateurs.dat", "r" );
			cadre_();
			char retour ;//option de retour au menu
			int pos_i=0; // position des donnes sur le fichier
			bool verification_correct=false;
			bool verified_nouveaux=false;
			char confirmer_mdp [20];
			while( !feof(f) )
			{
				fread( &u, sizeof(u) , 1, f);
				if( id == u.id )
				{
						cadre_();
						gotoxy(35,3);	textcolor(6);	printf("[ c"); textcolor(4); printf("H"); textcolor(6); printf("angement du mot de passe ]");
						gotoxy(25,7);	textcolor(14);	printf("compte numero : [ %d ]", u.id );
						while(!verification_correct)
						{
							char ancient_mdp[20];
							bool verified_ancient=false;
						while(!verified_ancient)
								{
						gotoxy(40,12);	textcolor(6);	printf("Ancient mot de passe : [                    ]");
						gotoxy(65,12);	textcolor(4);	gets(ancient_mdp);
								//getting old password first as confirmation
								if( strcmp(ancient_mdp,u.password) == 0 )
									verified_ancient=true;
								else 
									{	
									gotoxy(50,11);textcolor(4);printf("PASSWORD INCORRECT"); 
									}
								}
								//getting new password and its confirmation
							while(!verified_nouveaux)
								{
						char	nouveau_mdp[20] ;
						gotoxy(39,13);	textcolor(6);	printf("Nouveaux mot de passe : [                    ]");
						gotoxy(30,14);	textcolor(6);	printf("Confirmer nouveau mot de passe : [                    ]");
						gotoxy(65,13);	textcolor(4);	gets(nouveau_mdp);
						gotoxy(65,14);	textcolor(4);	gets(confirmer_mdp);
								if(strcmp(nouveau_mdp,confirmer_mdp)==0)
									{
										verified_nouveaux=true;
										verification_correct=true;
									}
								else 
									{	
									gotoxy(50,15);textcolor(4);printf("CONFIRMATION INCORRECT");
									}
								}
						}
							gotoxy(35,17);	textcolor(6);	printf("[ "); textcolor(4); printf("C"); textcolor(6); printf("onfirmer ]");//confirmation
							gotoxy(35,18);	textcolor(6);	printf("[ "); textcolor(4); printf("R"); textcolor(6); printf("etour au menu principal ]");
							gotoxy(37,17);	retour = getch() ;
							switch ( retour )
									{
										case 'R':	gotoxy(37,18);	textcolor(6);	printf("R");	retour='R';						 			break;
										case 'C':   gotoxy(37,17);	textcolor(6);	printf("C");	password_change(u.id,confirmer_mdp,pos_i);	break;
										default :	printf("C ou R");				break;
									}
							break;
				}	
				pos_i ++;	
		     }
			fclose(f);
		system("cls");
}
char	Menu_princip ( int id )
{
	cadre_();
	char choice_user='A';
	gotoxy(40,3);textcolor(9);printf("%c MENU USER %c",2,2);
			gotoxy(31,5);printf(" CHOOSE YOUR OPTION ( %c or %c ): ",24,25);
			char updown = 1;//moving through the options
			int i = 0;
			int position ;
			while( updown != 13 )//
			{
			position = 9 + i ;
			gotoxy(34,9);textcolor(6);printf("[   ");textcolor(4);printf("C");textcolor(6);printf("onsulter le solde    ]");//
			gotoxy(34,10);textcolor(6);printf("[   ");textcolor(4);printf("R");textcolor(6);printf("etirer de l'argent   ]");//
			gotoxy(34,11);textcolor(6);printf("[   ");textcolor(4);printf("D");textcolor(6);printf("eposer de l'argent   ]");//
			gotoxy(34,12);textcolor(6);printf("[  effectuer un ");textcolor(4);printf("V");textcolor(6);printf("irement  ]");//
			gotoxy(34,13);textcolor(6);printf("[     Re");textcolor(4);printf("L");textcolor(6);printf("ev\202 bancaire     ]");//
			gotoxy(34,14);textcolor(6);printf("[ c");textcolor(4);printf("H");textcolor(6);printf("anger le mot de passe ]");//
			gotoxy(41,15);textcolor(6);printf("[ ");textcolor(4);printf("Q");textcolor(6);printf("uitter ]");//
			gotoxy(33,position-1);printf(" ");gotoxy(61,position-1);printf(" ");
			gotoxy(33,position+1);printf(" ");gotoxy(61,position+1);printf(" ");
			gotoxy(33,position);textcolor(4); printf("%c",16);gotoxy(61,position);printf("%c",17);	updown = getch();
			
			switch(updown)// ARROW KEYS TO CHOOSE OPTIONS
			{
				case 80 :i++;break;//down
				case 72 :i--;break;//up
				case 13 : updown = 13 ;break ;//
				default : updown = 80 ;break;
			}
			// si le cursor vas plus que la darniere case (QUITTER) , alors il vas retourner a la premiere case
			if( i < 0 || i > 6 )
			{
				i=0;
				gotoxy(33,15);textcolor(9);printf(" ");gotoxy(61,15);printf(" ");	
			}
			}
			switch(position)
			{
				case 9 	:	choice_user = 'C' ;break;
				case 10 :	choice_user = 'R' ;break;
				case 11 :	choice_user = 'D' ;break;
				case 12 :	choice_user = 'V' ;break;
				case 13 :	choice_user = 'L' ;break;
				case 14 :	choice_user = 'H' ;break;
				case 15 :	choice_user = 'Q' ;break;
				default	:					  ;break;
			}
			cadre_();
			system("cls");
		return choice_user;
}
void	Menu_user ( void )
{
	int id;
	bool trouve=false;
	do
	{
		int compteur;//essaye de login
		cadre_();
		int id_checker;
		FILE *f = fopen ( "utilisateurs.dat", "r" );
		char pswrd;
		char pass[20]="";
		fflush(stdin);
		gotoxy(32,3);textcolor(9);printf("%c  WELCOME TO USER PLATFORM  %c",1,1);
		gotoxy(38,6);printf("LOGIN ACCOUNT");
		gotoxy(30,9);textcolor(11);printf("YOUR LOGIN NUMBER:[                           ]");
		gotoxy(30,10);textcolor(11);printf("YOUR PASSWORD    :[                           ]");
		if(compteur>0)
		{
			time_t orig_format;
			time(&orig_format);//time function	
			FILE *r = fopen("journalisation.DAT","a");
			fread( &Ju, sizeof(Ju), 1, r);
	 		sprintf(Ju.evenement," Connection echoue depuis le compte numero %d ",Tub.id);
	 		strcpy(Ju.date,asctime(gmtime(&orig_format)));
	 		fwrite(&Ju,sizeof(Ju),1,r);
			gotoxy(30,11);textcolor(4);printf("NUMBER OR PASSWORD IS INCORRECT");
			fclose(r);
		}
		gotoxy(50,9);scanf("%d",&id_checker);
	//hidding password while typing
					int i=0;
						while( pswrd != 13 )
						{
							gotoxy(50+i,10);
							pswrd=getch();
							pass[i]=pswrd;
							printf("*");
							i++;
						}pass[i-1]='\0';
						pswrd='\0';
	//verification of user id and password
			while(!feof(f))
			{
				fread( &u, sizeof(u) ,1 ,f);
				if( u.id == id_checker && strcmp( pass , u.password ) == 0 )
					{
						trouve = true;
						id = id_checker;
					}
				else	compteur++;
			}
			fclose (f);
			system("cls");
	} while ( !trouve );
	cadre_();
	char choice_user; // user's choice of the menu
	while(choice_user != 'Q')
	{
		choice_user=Menu_princip(u.id);
			switch(choice_user)
			{
				case 'C':	   Consult_solde(id);break;
				case 'R':	  Retirer_argent(id);break;
				case 'D':	  Deposer_argent(id);break;
				case 'V':  Virement_bancaire(id);break;//
				case 'L':	 Releve_bancaire(id);break;//
				case 'H':Changer_mot_de_pass(id);break;
				case 'Q':		 choice_user='Q';break;
				default:;break;
			}
	}
	printf("LOG OUT");
}
void	cadre_ ( void )
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
void 	cadre_transaction ( void )
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
		gotoxy(35,3);	textcolor(6);	printf("[ "); textcolor(4); printf("R"); textcolor(6); printf("elever bancaire ]");
		gotoxy(25,7);	textcolor(6);	printf("DATE   :" );
		gotoxy(25,8);	textcolor(6);	printf("COMPTE :" );
		gotoxy(5,10);	printf("+");	for(int i=1;i<=79;i++)	printf("*");printf("+");
		gotoxy(5,11);	printf("| DATE");	gotoxy(32,11);printf("| TYPE");	gotoxy(45,11);printf("| MONTANT"); gotoxy(65,11);printf("| SOLDE");gotoxy(85,11);printf("|");
		gotoxy(5,12);	printf("+");	for(int i=1;i<=79;i++)	printf("*");printf("+");
						for(int i=1 ; i<=15 ;i++)
						{
							for(int j=1;j<=81;j++)
							{
								if( j==1 || j==28 || j==41 || j==61 || j==81)
								{
									gotoxy(j+4,i+12);	printf("|");
								}
								if ( i == 15 ) printf("*");
							}
						}
		gotoxy(25,30);	textcolor(6);	printf("[ "); textcolor(4); printf("I"); textcolor(6); printf("mprimer ]");//Imprimer
		gotoxy(40,30);	textcolor(6);	printf("[ "); textcolor(4); printf("R"); textcolor(6); printf("etour au menu principal ]");//affichage du nouveau compte
		gotoxy(2,29);textcolor(9);printf("made by :");gotoxy(2,30);textcolor(2);printf("Abdellah Bounab");
}
