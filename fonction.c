#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"struct.h"


int menuPrincipal() {

    int iChoixMode;

    system("clear");

    printf("\t##################################################################################\n");
    printf("\t##########                      VENDEE GLOBE CHALLENGE                  ##########\n");
    printf("\t##########                          MENU GENERAL                        ##########\n");
    printf("\t##################################################################################\n");
    printf("\t########## 1/ Mode exploitation                                         ##########\n");
    printf("\t########## 2/ Mode développement                                        ##########\n");
    printf("\t########## 3/ Sortir                                                    ##########\n");
    printf("\t##################################################################################\n");
    printf("\n");

    printf("\tVeuillez saisir votre choix:\n");
    scanf("%d", &iChoixMode);

    return (iChoixMode);
}

/************************************ MENU MODE EXPLOITATION ***************************************/
int menuExploitation() {
    int iMenuExp;

    system("clear");

    printf("\t##################################################################################\n");
    printf("\t##########                    VENDEE GLOBE CHALLENGE                    ##########\n");
    printf("\t##########                      MENU D'EXPLOITATION                     ##########\n");
    printf("\t##################################################################################\n");
    printf("\t########## 1/ Créer une course                                          ##########\n");
    printf("\t########## 2/ Ajout de compétiteurs                                     ##########\n");
    printf("\t########## 3/ Supprimer un compétiteur                                  ##########\n");
    printf("\t########## 4/ Rechercher un compétiteur                                 ##########\n");
    printf("\t########## 5/ Ajouter un temps                                          ##########\n");
    printf("\t########## 6/ Trier un tableau                                          ##########\n");
    printf("\t########## 7/ Afficher la course                                        ##########\n");
    printf("\t########## 8/ Supprimer la course                                       ##########\n");
    printf("\t########## 9/ Sauvegarder une course dans un fichier                    ##########\n");
    printf("\t########## 10/ Charger une couse depuis un fichier                      ##########\n");
    printf("\t########## 11/ Quitter                                                  ##########\n");
    printf("\t##################################################################################\n");
    printf("\n");

    printf("\tVeuillez saisir votre choix:\n");
    scanf("%d%*c", &iMenuExp);

    return (iMenuExp);
}



/************************************ FONCTIONS DU MODE EXPLOITATION ***********************************************/

/***************************SKIPPER***********************************/

//Creation d'un skipper
void creerSkipper(P_SKIPPER s, char* n, char* p, char* a, uint ag)
{
    s->age = ag;
    strcpy(s->nom, n);
    strcpy(s->prenom, p);
    strcpy(s->adresse, a);
}

//Supp d'un skipper
void supprimerSKipper(P_SKIPPER s)
{
    if (s != NULL)
	{
        free(s);
    }
}

//Affichage d'un skipper
char* skipper_str(P_SKIPPER s)
{
    sprintf(s->str, "Skipper : Mr/Mme %s %s [Age : %u; Adresse : %s]", s->prenom, s->nom, s->age, s->adresse);
    return s->str;
}

/****************************BATEAU**************************************/

//Creation d'un bateau
void creerBateau(P_BATEAU b, char* mdl, char* mrk, float l)
{
    strcpy(b->modele, mdl);
    strcpy(b->marque, mrk);
    b->longueur = l;
}

//Supp d'un bateau
void supprimerBateau(P_BATEAU b)
{
    if (b != NULL)
	{
        free(b);
    }
}

//Affichage d'un bateau
char * bateau_str(P_BATEAU b)
{
    sprintf(b->str, "Bateau :  [Marque : %s; Modele : %s, Longueur : %f m]", b->marque, b->modele, b->longueur);
    return b->str;
}

/****************************TEMPS**************************************/

//Creation d'un temps
void creerDate(P_TEMPS t, uint j, uint h, uint m, uint s)
{
    t->jours = j;
    t->heures = h;
    t->minutes = m;
    t->secondes = s;
}

//Supp d'un temps
void supprimerDate(P_TEMPS t)
{
    if (t != NULL)
	{
        free(t);
    }
}

//Affichage d'un temps
char * date_str(P_TEMPS t)
{
    sprintf(t->str, "[Temps : %u j %u h %u min et %u s]", t->jours, t->heures, t->minutes, t->secondes);
    return t->str;
}


/****************************COMPETITEUR**************************************/

//Creation d'un competiteur
void creerCompetiteur(P_COMPETITEUR c, P_SKIPPER s, P_BATEAU b, P_TEMPS t, uint dossard)
{
    c->skipper = s;
    c->bateau = b;
    c->dossard = dossard + 1;
    c->temps = t;
}

//Supp d'un competiteur
void supprimerCompetiteur(P_COMPETITEUR c)
{
    if (c != NULL)
	{
        free(c->skipper);
        free(c->bateau);
        free(c->temps);
        free(c);
    }
}

//Affichage d'un competiteur
char * competiteur_str(P_COMPETITEUR comp)
{
    sprintf(comp->str, "COMPETITEUR n° %u :\n\t-> %s\n\t -> %s\n\t-> %s\n\n", comp->dossard, skipper_str(comp->skipper), bateau_str(comp->bateau), date_str(comp->temps));
    return comp->str;
}

/******************************COURSE*******************************************/

//Creation d'une course
void creerCourse(P_COURSE course, uint nb)
{
    course->liste = malloc(nb * sizeof (P_COMPETITEUR)); // on crée une liste de taille nb mais vide
    course->nb = 0;
}

//Ajout d'un competiteur dans la course
void ajouter(P_COURSE course, P_COMPETITEUR comp, uint dossard)
{
    comp->dossard = dossard;
    course->liste[course->nb] = comp;
    course->nb++;
}

//Ajout d'un temps a un competiteur dans la course
void ajouterTemps(P_COURSE c, uint dos, uint j, uint h, uint min, uint s)
{
    uint i;
	uint max;
	uint trouve;
	i = 0;
	max = c->nb;
	trouve = 0;

    while (i < max)
	{
        if (c->liste[i]->dossard == dos)
		{
            trouve = 1;
            break;
        }
        i++;
    }
    // si on n'a pas trouvé de compétiteur avec le dossard "dos" on sort de la donction
    if (!trouve) return; 
    // si on est ici, c'est qu'on l'a trouvé :)
    P_COMPETITEUR comp = c->liste[i];
    comp->temps->heures += j;
    comp->temps->jours += h;
    comp->temps->minutes += min;
    comp->temps->secondes += s;
}

//Supp d'une course si non vide
void supprimerCourse(P_COURSE c)
{
    if (c == NULL) return;

    uint l = c->nb;
    for (l = l - 1; l <= 0; l--)
	{
        supprimerCompetiteur(c->liste[l]);
    }
    free(c);
}

//Supp d'une course si vide
void suppCourse(P_COURSE c)
{
    if (c != NULL)
	{
        free(c);
    }
}

//Supp de competiteur par rapport a son dossard
void supprimer(P_COURSE c, uint dos)
{
    uint i;
	uint max;
	uint trouve;
	i=0;
	max = c->nb;
	trouve = 0;

    while (i < max)
	{
        if (c->liste[i]->dossard == dos)
		{
            trouve = 1;
            break;
        }
        i++;
    }

    if (trouve)
	{
        supprimerCompetiteur(c->liste[i]);
        while (i < max - 1)
		{
            c->liste[i] = c->liste[i + 1];
            i++;
        }
        c->liste[max - 1] = NULL;
        c->nb--;
    }
}

//Affiche une course
void afficher(P_COURSE c)
{
    uint i;
	i = 0;
    printf("\tEtat actuel de la course\n");
    printf("\n");
    printf("%d competiteur en course\n", c->nb);
    for (i; i < c->nb; i++)
	{
        printf("%s", competiteur_str(c->liste[i]));
    }
}

//Tri selon temps
void trierTemps(P_COURSE c)
{
	uint i;
	uint j;
	uint t;
	
	P_COMPETITEUR temp;
	for(i = 0; i < c->nb-2; i++)
	{
		for(j = i+1; j < c->nb-1; i++)
		{
		
		P_COMPETITEUR c1 = c->liste[i];
		P_COMPETITEUR c2 = c->liste[j];
		
		if(c1->temps->jours < c2->temps->jours) t = i;
			else if(c1->temps->jours > c2->temps->jours) t = j;
		else{
		if(c1->temps->heures < c2->temps->heures) t = i;
			else if (c1->temps->heures > c2->temps->heures) t = j;
		else
		{
			if(c1->temps->minutes < c2->temps->minutes) t = i;
				else if (c1->temps->minutes > c2->temps->minutes) t = j;
					else if(c1->temps->secondes <= c2->temps->secondes) t = i;
			else t = j;
		}
		}
		}
		if(t != i)
		{
			temp = c->liste[i];
			c->liste[i] = c->liste[j];
			c->liste[j] = temp;
		}
	}
}
