/*
	NOM: 			TOUR DE HANOI
	DATE:    	10/01/2006
   ATHORS:     Etienne Th. SADIO & Thierno IB. BARRY
   DESCRIPTION: Ce jeux est la reprise du vieux jeux Tour de Hanoi en mode texte.
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <ctype.h>
#include <dir.h>

#define n 8
#define SUCCES 0
#define FAILLURE -1

typedef struct
{
	int t[n];
   char *tab[n]; /*Qui recevra les disques*/
 	int sommet;
} tour;

typedef struct
{
	char nom_joueur[20];
   int nbre_disk_joueur;
   int score_joueur;
}score;

/*Variable globales*/
tour A, B, C;
score joueur;
char *s;

/*=============================================================================*/
/*											définition des fonctions							 */
/*=============================================================================*/

/*==============================*/
void init_tour(tour *p)
/*==============================*/
{
/*initialise la tour*/
	int i;
	p->sommet = -1;
   for(i=0; i<n; i++)
   	p->t[i]=-1;    /*Place des: | dans la tour*/
}                    /* ce qui correspond a -1*/

/*==============================*/
int est_vide(tour *p)
/*==============================*/
{
/*Vérifit si la tour est vide ou non*/
	if(p->sommet==-1)
   	return(1);
   else
   	return(0);
}

/*==============================*/
int est_pleine(tour *p)
/*==============================*/
{
/*Vérifit si la tour est pleine ou non*/
	if(p->sommet==n)
   	return(1);
   else
   	return(0);
}

/*==============================*/
int empiler(tour *p, int val)
/*==============================*/
{
/*verifit si la tour est vide ou */
/*si elle est pleine et que la disk à emplier est inférieur*/
/*à celui qui y est déja*/
	if( (est_vide(p))   ||  ((!est_pleine(p))&&(val < p->t[p->sommet])) )
   {
   	p->t[++p->sommet]=val;
      return(1);
   }
   else return(0);

}

/*==============================*/
int depiler(tour *depart, tour *arrive)
/*==============================*/
{
	int val=2*n;
	if(!est_vide(depart))
   {
   	val=depart->t[depart->sommet];
   /*vérifit si la valeur dépilée peut être empilée*/
      if((est_vide(arrive))||(val < arrive->t[arrive->sommet]))
      {
      	depart->t[depart->sommet]=-1;
      	depart->sommet--;
      }
      else val=2*n;   /*retourne cette valeur si elle ne peut*/
   }                  /*pas être empilée*/
   return(val);
}

/*==============================*/
char *disk(int d)
/*==============================*/
{
/*Tableau de disques. Pour chaque chaine de caractère*/
/*correspond une taille de disque*/
   s=(char *)malloc(18*sizeof(char));
	switch(d)
   {
   	case -1:{s[0]=' ';s[1]=' ';s[2]=' ';s[3]=' ';s[4]=' ';s[5]=' ';s[6]=' ';s[7]=' ';s[8]='|';s[9]=' ';s[10]=' ';s[11]=' ';s[12]=' ';s[13]=' ';s[14]=' ';s[15]=' ';s[16]=' ';s[17]='\0'; break;}
      case  0:{s[0]=' ';s[1]=' ';s[2]=' ';s[3]=' ';s[4]=' ';s[5]=' ';s[6]=' ';s[7]='#';s[8]='|';s[9]='#';s[10]=' ';s[11]=' ';s[12]=' ';s[13]=' ';s[14]=' ';s[15]=' ';s[16]=' ';s[17]='\0'; break;}
      case  1:{s[0]=' ';s[1]=' ';s[2]=' ';s[3]=' ';s[4]=' ';s[5]=' ';s[6]='#';s[7]='#';s[8]='|';s[9]='#';s[10]='#';s[11]=' ';s[12]=' ';s[13]=' ';s[14]=' ';s[15]=' ';s[16]=' ';s[17]='\0'; break;}
      case  2:{s[0]=' ';s[1]=' ';s[2]=' ';s[3]=' ';s[4]=' ';s[5]='#';s[6]='#';s[7]='#';s[8]='|';s[9]='#';s[10]='#';s[11]='#';s[12]=' ';s[13]=' ';s[14]=' ';s[15]=' ';s[16]=' ';s[17]='\0'; break;}
      case  3:{s[0]=' ';s[1]=' ';s[2]=' ';s[3]=' ';s[4]='#';s[5]='#';s[6]='#';s[7]='#';s[8]='|';s[9]='#';s[10]='#';s[11]='#';s[12]='#';s[13]=' ';s[14]=' ';s[15]=' ';s[16]=' ';s[17]='\0'; break;}
      case  4:{s[0]=' ';s[1]=' ';s[2]=' ';s[3]='#';s[4]='#';s[5]='#';s[6]='#';s[7]='#';s[8]='|';s[9]='#';s[10]='#';s[11]='#';s[12]='#';s[13]='#';s[14]=' ';s[15]=' ';s[16]=' ';s[17]='\0'; break;}
      case  5:{s[0]=' ';s[1]=' ';s[2]='#';s[3]='#';s[4]='#';s[5]='#';s[6]='#';s[7]='#';s[8]='|';s[9]='#';s[10]='#';s[11]='#';s[12]='#';s[13]='#';s[14]='#';s[15]=' ';s[16]=' ';s[17]='\0'; break;}
      case  6:{s[0]=' ';s[1]='#';s[2]='#';s[3]='#';s[4]='#';s[5]='#';s[6]='#';s[7]='#';s[8]='|';s[9]='#';s[10]='#';s[11]='#';s[12]='#';s[13]='#';s[14]='#';s[15]='#';s[16]=' ';s[17]='\0'; break;}
      case  7:{s[0]='#';s[1]='#';s[2]='#';s[3]='#';s[4]='#';s[5]='#';s[6]='#';s[7]='#';s[8]='|';s[9]='#';s[10]='#';s[11]='#';s[12]='#';s[13]='#';s[14]='#';s[15]='#';s[16]='#';s[17]='\0'; break;}
   }
   return(s);
}

/*==============================*/
void tour_hanoi(tour *p)
/*==============================*/
{
/*Met les disques dans une tour, du plus grand au plus petit*/
	int i;
   for(i=0; i<=p->sommet; i++)
      p->t[p->sommet-i]=i;
}

/*==============================*/
void affiche_tour(void)
/*==============================*/
{
	int i;
   for(i=0; i<n; i++)
   {
   	A.tab[i]=disk(A.t[i]);
      B.tab[i]=disk(B.t[i]);
      C.tab[i]=disk(C.t[i]);
   }
   clrscr();
   printf("\n\t--------- TOUR DE HANOI ---------\n\n");
   for(i=n-1; i>=0; i--)
   {
   	printf("%s\t", A.tab[i]);
      printf("%s\t", B.tab[i]);
      printf("%s\n", C.tab[i]);
   }
   printf("\n     -TOUR 1-\t\t     -TOUR 2-\t\t     -TOUR 3-\n");
}

/*==============================*/
void deplacement(int depart, int arrive)
/*==============================*/
{
	int temp;
 	switch(depart)
   {
   	case 1:
      {
      	if(arrive==2)
         {
         	if((temp=depiler(&A,&B))!=2*n)
            {
            	if(!empiler(&B,temp))
            		{printf("\tERREUR 1: Mouvement non autoris\202 \a \n"); getch();}
            }
            else	{printf("\tERREUR 2: Mouvement non autoris\202 \a \n"); getch();}
         }
         else if(arrive==3)
         {
         	if((temp=depiler(&A,&C))!=2*n)
            {
            	if(!empiler(&C,temp))
            		{printf("\tERREUR 1: Mouvement non autoris\202 \a \n"); getch();}
            }
            else	{printf("\tERREUR 2: Mouvement non autoris\202 \a \n"); getch();}
         }
         else
         	{printf("\tERREUR 3: Mouvement non autoris\202 \a \n"); getch();}
         break; /*break pour case 1 (tour_depart)*/
      } /*fin case 1*/

      case 2:
      {
      	if(arrive==1)
         {
         	if((temp=depiler(&B,&A))!=2*n)
            {
            	if(!empiler(&A,temp))
            		{printf("\tERREUR 1: Mouvement non autoris\202 \a \n"); getch();}
            }
            else	{printf("\tERREUR 2: Mouvement non autoris\202 \a \n"); getch();}
         }
         else if(arrive==3)
         {
         	if((temp=depiler(&B,&C))!=2*n)
            {
            	if(!empiler(&C,temp))
            		{printf("\tERREUR 1: Mouvement non autoris\202 \a \n"); getch();}
            }
            else	{printf("\tERREUR 2: Mouvement non autoris\202 \a \n"); getch();}
         }
         else
         	{printf("\tERREUR 3: Mouvement non autoris\202 \a \n"); getch();}
         break;
      } /*fin case 2*/

      case 3:
      {
      	if(arrive==1)
         {
         	if((temp=depiler(&C,&A))!=2*n)
            {
            	if(!empiler(&A,temp))
            		{printf("\tERREUR 1: Mouvement non autoris\202 \a \n"); getch();}
            }
            else	{printf("\tERREUR 2: Mouvement non autoris\202 \a \n"); getch();}
         }
         else if(arrive==2)
         {
         	if((temp=depiler(&C,&B))!=2*n)
            {
            	if(!empiler(&B,temp))
            		{printf("\tERREUR 1: Mouvement non autoris\202 \a \n"); getch();}
            }
            else	{printf("t\ERREUR 2: Mouvement non autoris\202 \a \n"); getch();}
         }
         else
         	{printf("\tERREUR 3: Mouvement non autoris\202 \a \n"); getch();}
         break;
      } /*fin case 3*/
      default:
      	{printf("\tERREUR 4: Mouvement non autoris\202 \a \n"); getch();}
      break;
   }  /*fin switch(tour_depart)*/
}

/*==============================*/
int test_fin(void)
/*==============================*/
{
	if((est_vide(&A))&&(est_vide(&B)))
   	return(1);
   else
   	return(0);
}

/*================================*/
char *tostring(score sc_elmt)
/*================================*/
{
/*Nous allons convertir une structure en chaine de caractères*/
/*Pour faciliter la sauvegarde du nom et du score de chaque joueur*/
	int i, nbr_zero;
	char nom_joueur[21], score_joueur1[6], score_joueur2[6], str_score[30];

/*On augmente des espaces pour uniformiser le nom du joueur*/
   strcpy(nom_joueur,sc_elmt.nom_joueur);
   for(i=strlen(sc_elmt.nom_joueur); i<21; i++)
		nom_joueur[i]=' ';
	nom_joueur[i]='\0';
	strcpy(str_score,nom_joueur);

   itoa(sc_elmt.nbre_disk_joueur,score_joueur1,10);
   nbr_zero=5-(strlen(score_joueur1));
	for(i=0; i<nbr_zero; i++)
		score_joueur2[i]='0';
   score_joueur2[i]='\0';
   strcat(score_joueur2,score_joueur1);
   strcat(str_score,score_joueur2);

   /*On augmente des zeros à droite du chiffre*/
   itoa(sc_elmt.score_joueur,score_joueur1,10);
	nbr_zero=5-(strlen(score_joueur1));
	for(i=0; i<nbr_zero; i++)
		score_joueur2[i]='0';
   score_joueur2[i]='\0';
   strcat(score_joueur2,score_joueur1);
	strcat(str_score,score_joueur2);
   strcat(str_score,"\n");

	return(str_score);
}

/*==============================*/
int calcul_score(int nb_disk)
/*==============================*/
{
	int min_coup;
 	switch(nb_disk)
   {
    	case 3:	min_coup=7;   break;
      case 4:  min_coup=15;  break;
      case 5:	min_coup=31;  break;
      case 6:  min_coup=63;  break;
      case 7:  min_coup=127; break;
      case 8:  min_coup=255; break;
   }
   return(1000*nb_disk*min_coup);
}
/*==============================*/
void ajoute_score(FILE *fp)
/*==============================*/
{
/*Elle permet d'ajouter une structure dans un fichier*/
	char score_save[35];
   printf("\n\tEntrez votre nom: ");
   scanf("%s",joueur.nom_joueur);
   strcpy(score_save,tostring(joueur));
   fputs(score_save,fp);
   printf("\n\tSauvegarde effectu\202e avec succes...");
}

/*==============================*/
int sauvegarde(FILE *fich_score)
/*==============================*/
{
	char rep_courant[MAXPATH];
   char rep;
/*on recupère le repertoire courant de l'executable*/
   if( getcwd(rep_courant,MAXPATH) == NULL )
   {    // Gestion de l'erreur
   	printf("\n\tImpossible d'obtenir le repertoire courant\n\t");
      system("pause");
      return(FAILLURE);
   }
   else
   {
/*on concatène le non du fichier, et on a chemin complet */
   	strcat(rep_courant,"\\score.tak");

      if((fich_score=fopen(rep_courant,"r"))==NULL)
      {
      	printf("\n\tImpossible d'ouvrir le fichier: %c\\...\\score.tak\n",getdisk()+'A');
         printf("\tCe fichier peut ne pas exister...\n");
         printf("\tVoulez-vous le cr\202er? O - N:  ");
        	rep=toupper(getch());
   /*traitement sur le choix de l'utilasateur*/
			switch(rep)
   		{
    			case 'O':
      		{
         		fclose(fich_score);
      			if((fich_score=fopen(rep_courant,"w"))==NULL)
         		{
         			printf("\n\tImpossible de cr\202er le fichier: \n\t");
            		system("\tpause");
            		return(FAILLURE);
         		}
         		else
         			ajoute_score(fich_score);
      			break;
      		}/*fin case oui*/

      		case 'N':
      		{
               printf("\n\tVotre score ne sera pas enregistr\202...\n");
      			break;
      		}/*fin case non*/

            default:
            	printf("\n\tERREUR: choix non valide");
            break;
   		} /*fin du switch(rep)*/
      }
/*Dans le cas ou le fichier existe on ajoutera tout simplement*/
      else
      {
       	fclose(fich_score);
         if((fich_score=fopen(rep_courant,"a"))==NULL)
         {
      		printf("\n\tImpossible d'ouvrir le fichier: %c\\...\\score.tak\n",getdisk()+'A');
            getch();
            return(FAILLURE);
         }
         else
         	ajoute_score(fich_score);
      }
      fclose(fich_score);
      return(SUCCES);
   }
}

/*==============================*/
int test_caractere()
/*==============================*/
{
/*Test si on a tapé un chiffre ou un caratère*/
	char test[2];
   scanf("%s",test);
   if (isdigit(test[0]))
   	return(atoi(test)); /*retourne le chiffre si ça en est un*/
   else
   {	printf("\t\t  Vous avez tap\202 un caract\212re");
   	getch();
   	return(-1); /*sinon retourne -1*/
   }
}

/*==============================*/
void jouer()
/*==============================*/
{
   FILE *score_streem;
	int nbr_disk, tour_depart, tour_arrive, cpt=0;
   int i;
   char choix;
   /*initiaisation des tours (sommet=-1)*/
   init_tour(&A);
   init_tour(&B);
   init_tour(&C);
   do{
         clrscr();
   		printf("\n\tEntrez le nombre de disques [3..%d]:  ",n);
			nbr_disk=test_caractere();
   }while((nbr_disk<3)||(nbr_disk>n));
   A.sommet = nbr_disk-1; 		/*le nombre de disk est le sommet de la tour A*/
   joueur.nbre_disk_joueur = nbr_disk;
   tour_hanoi(&A);
   affiche_tour();
   free(s);
   do{
   		do{
         	affiche_tour();
         		printf("\n\t--------------------Mouvements-------------------\n");
               if (cpt!=0)
               	printf("\tCoup num\202ro: %d\n",cpt);
               printf("\tTour de d\202part:  ");
               tour_depart=test_caractere();
               printf("\n\tTour d'arriv\202e:  ");
               tour_arrive=test_caractere();
               printf("\n");
         }while((tour_depart<0)||(tour_arrive<0));
         deplacement(tour_depart,tour_arrive);
         cpt++;
         affiche_tour();
         free(s);
   }while(!test_fin());
   printf("\a                                                    \a");
   printf("\n\tF\202licitation, vous avez gagn\202 en %d coup\n",cpt);
   joueur.score_joueur=(calcul_score(nbr_disk))/cpt;
   printf("\tVotre score est de: %d\n",joueur.score_joueur);
   printf("\tAppuyer sur S pour sauvegarder");
   choix=toupper(getch());
   if(choix=='S')
   {
   	if(sauvegarde(score_streem)==FAILLURE)
      	printf("\n\tImpossible de sauvegarder");
   }
   else
   	printf("\n\tsauvegarde non effectu\202e...\n");
}

/*==============================*/
void meilleur_score()
/*==============================*/
{
   FILE *fp;
   score *tab_score, aux;
   int cpt, c, i, j;
	char path_courant[MAXPATH], s[25];
/*on recupère le repertoire courant de l'executable*/
   if( getcwd(path_courant,MAXPATH) == NULL )
   {    // Gestion de l'erreur
   	printf("\n\tImpossible d'obtenir le repertoire courant\n\t");
      getch();
   }
   else
   {
   	strcat(path_courant,"\\score.tak");
   	if((fp=fopen(path_courant,"r"))==NULL)
      	printf("\n\tImpossible d'ouvrir le fichier: %c\\...\\score.tak\n",getdisk()+'A');
      else
      {
   		for(cpt=0; (c=getc(fp))!=EOF; )
      		if(c=='\n')		cpt++;

         tab_score=(score *)malloc(cpt*sizeof(score));
         rewind(fp);
      	for(i=0; fgets(s,22,fp)!=NULL; i++)
      	{
           	if(strcmp(s," ")!=0)
            	strcpy(tab_score[i].nom_joueur,s);

            fgets(s,6,fp);
           	if(strcmp(s," ")!=0)
            	tab_score[i].nbre_disk_joueur = atoi(s);

         	fgets(s,6,fp);
            if(strcmp(s," ")!=0)
            	tab_score[i].score_joueur = atoi(s);
            fgets(s,2,fp);
      	}
         for(i=0; i<cpt-1; i++)
         	for(j=i+1; j<cpt; j++)
            {
             	if(tab_score[i].score_joueur < tab_score[j].score_joueur)
               {
               				aux = tab_score[i];
                  tab_score[i] = tab_score[j];
                  tab_score[j] = aux;
               }
            }
         clrscr();
         printf("\t----------------------------------------------\n");
         printf("\t--N\t NOM\t\t\tSCORE\tDISK--\n");
         printf("\t----------------------------------------------\n");
         for(i=0; i<cpt; i++)
         	printf("\t  %d\t%s\t%d\t  %d\n",i+1,tab_score[i].nom_joueur,tab_score[i].score_joueur,tab_score[i].nbre_disk_joueur);

      }
   }
}

/*==============================*/
void aide()
/*==============================*/
{
	FILE *fp;
   char path_courant[MAXPATH], t[1];
   int c;
   clrscr();
   printf("\t-------------------------------------------------------------------\n");
   printf("\t--                              AIDE                             --\n");
   printf("\t-------------------------------------------------------------------\n\n\t");
   if( getcwd(path_courant,MAXPATH) == NULL )
   {    // Gestion de l'erreur
   	printf("\n\tImpossible d'obtenir le repertoire courant");
      getch();
   }
   else
   {
   	strcat(path_courant,"\\aide.hlp");
   	if((fp=fopen(path_courant,"r"))==NULL)
      	printf("\n\tImpossible d'ouvrir le fichier: %c\\...\\aide.hlp",getdisk()+'A');
      else
      {
      	for( ;(c=getc(fp))!=EOF; )
         {
         	t[0]=c; t[1]='\0';
            if		 (strcmp(t,"é")==0)	printf("\202"); /*affiche é*/
            else if(strcmp(t,"è")==0)	printf("\212"); /*affiche è*/
            else if(strcmp(t,"ê")==0)	printf("\210"); /*affiche ê*/
            else if(strcmp(t,"à")==0)	printf("\205"); /*affiche à*/
            else if(strcmp(t,"ç")==0)	printf("\207"); /*affiche ç*/
            else if(strcmp(t,"\n")==0)	printf("\n\t");
           	else 								printf("%c",c);
         }
      }
      getch();
   }
}

/*==============================*/
int sortie()
/*==============================*/
{
	char rep;
	do{
   		clrscr();
   		printf("\n\n\tSORTIE...\n");
   		printf("\t      Voulez-vous vraiment sortir? O - N:  ");
         rep = toupper(getch());
         if(rep=='O')			return(5);
         else if(rep=='N') 	return(-1);
   }while((rep!='O')&&(rep!='N'));
}
/*==============================*/
void a_propos()
/*==============================*/
{
   clrscr();
	printf("\t----------------------------------------------\n");
   printf("\t--                 A PROPOS                 --\n");
   printf("\t----------------------------------------------\n\n");
 	printf("\t\tTOUR DE HANOI [TAKAM'S VERSION]\n");
   printf("\t\t                   Version 1.0 \n");
   printf("\t\t                   10-01-2006  \n\n");
   printf("\t\tAUTEURS:                       \n");
   printf("\t\t       SADIO Ethienne          \n");
   printf("\t\t       MOROKRO Paul Emma.      \n");
   printf("\t\t       N'DIBY Olivier          \n");
   printf("\t\t       YAKHINI Mohamed         \n");
   printf("\t\t       BARRY Thierno IB.       \n");
}

/*==============================*/
void accueil()
/*==============================*/
{
 	clrscr();
   printf("\n\n\n");
   printf("\t\t  TTTTTTT  OOOOO  U    U RRRR        \n");
   printf("\t\t     T    O     O U    U R   R       \n");
   printf("\t\t     T    O     O U    U RRRR        \n");
   printf("\t\t     T     OOOOO   UUUU  R   R     \n\n");
   printf("\t\t             2222222                 \n");
   printf("\t\tH    H  AAAA  NN     N  OOOOO  III   \n");
   printf("\t\tH    H A    A NN N   N O     O III   \n");
	printf("\t\tHHHHHH AAAAAA N N N  N O     O III   \n");
	printf("\t\tH    H A    A N   N NN O     O III   \n");
	printf("\t\tH    H A    A N     NN  OOOOO  III   \n");
   getch();
}
/*=============================================================================*/
/*     									Programme principal      							 */
/*=============================================================================*/

main()
{
	int choix;

   accueil();

   do{   clrscr();
   		printf("\t----------------------------------\n");
   		printf("\t------ MENU | TOUR DE HANOI ------\n");
   		printf("\t--------------------------------\n\n");
         printf("\t\t  1-Jouer\n");
         printf("\t\t  2-Meilleur score\n");
         printf("\t\t  3-Aide\n");
         printf("\t\t  4-A propos\n");
         printf("\t\t  5-Sortie\n");
         printf("\t\t  Entrez votre choix [1..5]:  ");
         choix=test_caractere();
         switch(choix)
         {
         /*==========Choix - jouer-==========*/
         	case 1:
            {
            	do{
               		jouer();
                     printf("\n\tPour sortir appuyer sur ESC");
               }while(getch()!=27);
            	break;
            }	/*fin case 1*/
         /*==========Choix - meilleur score-==========*/
            case 2:
            {
               meilleur_score();
               getch();
            	break;
            }	/*fin case 2*/
          /*==========Choix - aide-==========*/
            case 3:
            {
             	aide();
            	break;
            }  /*fin case 3*/
           /*==========Choix - a propos-==========*/
            case 4:
            {
               a_propos();
               getch();
            	break;
            }	/*fin case 4*/
           /*==========Choix - sortie-==========*/
            case 5:
            {
               choix = sortie();
            	break;
            }	/*fin case 5*/
         }/*fin swititch(choix)*/
   }while(choix!=5);
   return(SUCCES);
}