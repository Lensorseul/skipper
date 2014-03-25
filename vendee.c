#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"

#define MODE_EXP 1
#define MODE_DEV 2
#define SORTIR 3

#define CREER_COURSE 1
#define AJOUTER_COMPETITEUR 2
#define SUPPRIMER_COMPETITEUR 3
#define RECHERCHER_COMPETITEUR 4
#define AJOUTER_TEMPS 5
#define TRIER_TABLEAU 6
#define AFFICHER_COURSE 7
#define SUPPRIMER_COURSE 8
#define SAUVEGARDER 9
#define CHARGER 10
#define QUITTER 11


/******************************************************************************************************/
int main(int argc, char** argv)
{
//Déclaration de variables

    int iChoixMode;
	iChoixMode = 0;
    int iMenuExp;
	iMenuExp = 0;
    int iMenuSL;
	iMenuSL=0;
    int nbComp;
    int i;
    int iCreationCourse;
    iCreationCourse = 0;

    uint iNb;
    P_COURSE course;
    P_COMPETITEUR c;
    P_SKIPPER sk;
    P_BATEAU b;
    P_TEMPS t;
    uint dossard;
    uint dossCompSupp;
    dossard = 0;

    char n[LEN];
    char p[LEN];
    char ad[LEN];
    uint ag;

    char mdl[LEN];
    char mrk[LEN];
    float l;

    uint j;
    uint h;
    uint m;
    uint s;



    while (iChoixMode != SORTIR)
	{

        iChoixMode = menuPrincipal();

        switch (iChoixMode)
		{

            case MODE_EXP:

                while (iMenuExp != QUITTER)
				{

                    iMenuExp = menuExploitation();

                    switch (iMenuExp)
					{
                        case CREER_COURSE:
                            system("clear");
                            printf("\t*********************************************************\n");
                            printf("\t**                    CREATION COURSE                  **\n");
                            printf("\t*********************************************************\n");
							printf("\tNote:Les numeros de dossard son attribués automatiquements aux compétiteurs\n");
                            printf("\tCombien de compétiteurs pour cette course?\n");
                            scanf("%u%*c", &nbComp);
                            P_COURSE course = (P_COURSE) malloc(sizeof (Course));
                            creerCourse(course, nbComp);
                            iCreationCourse = 1;
                            printf("\tCourse créée avec succes\n");
                            printf("\tAppuyez sur ENTREE pour continuer\n");
                            scanf("%*c");
                            break;

                        case AJOUTER_COMPETITEUR:
			    system("clear");
                            printf("\t*********************************************************\n");
                            printf("\t**                   AJOUT COMPETITEUR                 **\n");
                            printf("\t*********************************************************\n");

                            for (i = 0; i < nbComp; i++)
							{

                                sk = (Skipper*) malloc(sizeof (Skipper));
                                printf("\tNom du skipper\n");
                                scanf("%s", n);
                                printf("\tPrenom du skipper\n");
                                scanf("%s", p);
                                printf("\tAdresse complete du skipper (rue, ville, code postal)\n");
                                scanf("%s%*c", ad);
                                printf("\tAge du skipper\n");
                                scanf("%u", &ag);
                                creerSkipper(sk, n, p, ad, ag);
                                printf("\t*************************************\n");

                                b = (Bateau*) malloc(sizeof (Bateau));
                                printf("\tMarque\n");
                                scanf("%s", mrk);
                                printf("\tModele du bateau\n");
                                scanf("%s", mdl);
                                printf("\tLongueur du bateau\n");
                                scanf("%f", &l);
                                creerBateau(b, mdl, mrk, l);
                                printf("\t*************************************\n");

                                t = (P_TEMPS) malloc(sizeof (Temps));
                                j = 0;
                                h = 0;
                                m = 0;
                                s = 0;
                                creerDate(t, j, h, m, s);

                                c = malloc(sizeof (Competiteur));
                                creerCompetiteur(c, sk, b, t, dossard);
                                printf("Competiteur : %s ", competiteur_str(c));
                                dossard++;
                                ajouter(course, c, dossard);
								printf("\t<<<<<     Compétiteur suivant     >>>>>\n");
                            }
                            printf("\tAppuyez sur ENTREE pour continuer\n");
                            scanf("%*c");
                            scanf("%*c");
                            break;

                        case SUPPRIMER_COMPETITEUR:
							system("clear");
                            printf("\t*********************************************************\n");
                            printf("\t**                SUPPRESSION COMPETITEUR              **\n");
                            printf("\t*********************************************************\n");
                            printf("\tEntrez le dossard du compétiteur à supprimer\n");
                            scanf("%u%*c", &dossCompSupp);
                            supprimer(course, dossCompSupp);
							printf("\tAppuyez sur ENTREE pour continuer\n");
                            scanf("%*c");
                            break;
                        case RECHERCHER_COMPETITEUR:
			    system("clear");
                            printf("\t*********************************************************\n");
                            printf("\t**                 RECHERCHE COMPETITEUR               **\n");
                            printf("\t*********************************************************\n");
                            break;

                        case AJOUTER_TEMPS:
			    system("clear");
                            printf("\t*********************************************************\n");
                            printf("\t**                     AJOUT TEMPS                     **\n");
                            printf("\t*********************************************************\n");

                            uint dossAjouTemp;
							uint j;
							uint h;
							uint min;
							uint s;
							printf("\tEntrez le numero de dossard du compétiteur auquel vous voulez ajouter un temps de course\n");
							scanf("%u%*c",&dossAjouTemp);
							printf("\tNombre de jours\n");
							scanf("%u%*c",&h);
							printf("\tNombre d'heures\n");
							scanf("%u%*c",&j);
							printf("\tNombre de minutes\n");
							scanf("%u%*c",&min);
							printf("\tNombre de secondes\n");
							scanf("%u%*c",&s);
								ajouterTemps(course,dossAjouTemp, j, h, min, s);
							printf("\tAppuyez sur ENTREE pour continuer\n");
								scanf("%*c");
								break;

                        case TRIER_TABLEAU:
							system("clear");
                            printf("\t*********************************************************\n");
                            printf("\t**                     TRI TABLEAU                     **\n");
                            printf("\t*********************************************************\n");
								trierTemps(course);
							printf("\tAppuyez sur ENTREE pour continuer\n");
                            scanf("%*c");
                            break;

                        case AFFICHER_COURSE:
							system("clear");
                            printf("\t*********************************************************\n");
                            printf("\t**                   AFFICHAGE COURSE                  **\n");
                            printf("\t*********************************************************\n");
                            if (iCreationCourse)
							{
                                afficher(course);
                            }
							else
							{
                                printf("\tIl n'y a aucune course à afficher\n");
                            }
                            printf("\tAppuyez sur ENTREE pour continuer\n");
                            scanf("%*c");
                            break;

                        case SUPPRIMER_COURSE:
							system("clear");
                            printf("\t*********************************************************\n");
                            printf("\t**                  SUPPRESSION COURSE                 **\n");
                            printf("\t*********************************************************\n");
                            if (iCreationCourse)
							{
                                suppCourse(course);
                                printf("\tSuppression de la course effectuée avec succes!!");
                            }
							else
							{
                                printf("\tIl n'y a aucune course à supprimer\n");
                            }
                            printf("\tAppuyez sur ENTREE pour continuer\n");
                            scanf("%*c");
                            break;

                        case SAUVEGARDER:
							system("clear");
                            printf("\t*********************************************************\n");
                            printf("\t**                   SAUVEGARDE COURSE                 **\n");
                            printf("\t*********************************************************\n");
                            char nom[LEN];
							printf("\tEntrez le nom du fichier dans lequel vous sauvegardez\n");
							scanf("%s",nom);

                            strcat(nom, ".txt");

                            FILE * saveFile = fopen(nom, "w");

                            if(saveFile){

                                // on ecris d'abord le nombre de compétiteur
                                fprintf(saveFile, "%u\n", course->nb);


                                // et on ajoute les competiteur un par un dans le fichier
                                uint i = 0;
                                for(i; i < course->nb; i++){
                                    P_COMPETITEUR c = course->liste[i];
                                    // on sauvegarde le skipper
                                    fprintf(saveFile, "%s\n", c->skipper->nom);
                                    fprintf(saveFile, "%s\n", c->skipper->prenom);
                                    fprintf(saveFile, "%s\n", c->skipper->adresse);
                                    fprintf(saveFile, "%u\n", c->skipper->age);

                                    //ensuite le bateau
                                    fprintf(saveFile, "%s\n", c->bateau->marque);
                                    fprintf(saveFile, "%s\n", c->bateau->modele);
                                    fprintf(saveFile, "%f\n", c->bateau->longueur);

                                    //au tour du Temps
                                    fprintf(saveFile, "%u\n", c->temps->jours);
                                    fprintf(saveFile, "%u\n", c->temps->heures);
                                    fprintf(saveFile, "%u\n", c->temps->minutes);
                                    fprintf(saveFile, "%u\n", c->temps->secondes);

                                    //et enfin le dossard
                                    fprintf(saveFile, "%u\n",c->dossard);
                                }

                                // on ferme le fichier à la fin
                                fclose(saveFile);


                            }else{
								printf("\tEchec de la sauvegarde\n");
                                // sinon si la crétion du fichier n'as pas marché, il faudra le dire à l'utilisateur FIN
                            }


                            printf("\tAppuyez sur ENTREE pour continuer\n");
                            scanf("%*c");
                            break;

			case CHARGER:
			    system("clear");
                            printf("\t*********************************************************\n");
                            printf("\t**                CHARGEMENT COURSE                    **\n");
                            printf("\t*********************************************************\n");

			    break;
                        case QUITTER:
                            //Sortie du programme
                            system("clear");
                            exit(EXIT_SUCCESS);
                            break;
                        default:
                            printf("\t!! Choix invalide !!\n");
                            printf("\tAppuyez sur ENTREE pour continuer\n");
                            scanf("%*c");
                            break;
                    }
                }
                break;
            case MODE_DEV:
                system("clear");
                printf("\tEn cours de développement\n");
                printf("\tAppuyez sur ENTREE pour continuer\n");
                scanf("%*c");
                break;
            case SORTIR:
                //Sortie du programme
                system("clear");
                exit(EXIT_SUCCESS);
                break;
	    default:
	        printf("\tAttention !! choix invalide .\n");
                printf("\tAppuyez sur ENTREE pour continuer\n");
                scanf("%*c");
                break;
        }
    }
    return 0;
}
