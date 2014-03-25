//Declaration d'un entier nonsigné comme uint au lieu de unsigned int 
typedef unsigned int uint;
#define LEN 100
#define MAX 10

char str1[1024];
char str2[1024];
char str3[1024];
char str4[1024];

/****** Structure skiper *******/

typedef struct {
    char str[1024];
    char nom[LEN];
    char prenom[LEN];
    char adresse[LEN];
    uint age;
} Skipper;

typedef Skipper * P_SKIPPER;
void creerSkipper(P_SKIPPER, char*, char*, char*, uint);
void supprimerSkipper(P_SKIPPER);
char* skipper_str(P_SKIPPER);

/****** Structure bateau *******/
typedef struct {
    char str[1024];
    char marque[LEN];
    char modele[LEN];
    float longueur;
} Bateau;

typedef Bateau* P_BATEAU;
void creerBateau(P_BATEAU, char*, char*, float);
void supprimerBateau(P_BATEAU);
char * bateau_str(P_BATEAU);

/****** Structure temps *******/
typedef struct {
    char str[1024];
    uint jours;
    uint heures;
    uint minutes;
    uint secondes;
} Temps;

typedef Temps* P_TEMPS;
void creerDate(P_TEMPS, uint, uint, uint, uint);
void supprimerDate(P_TEMPS);
char* date_str(P_TEMPS);

/****** Structure competiteur *****/
typedef struct {
    char str[1024];
    P_SKIPPER skipper;
    P_BATEAU bateau;
    uint dossard;
    P_TEMPS temps;
} Competiteur;
typedef Competiteur * P_COMPETITEUR;

void creerCompetiteur(P_COMPETITEUR, P_SKIPPER, P_BATEAU, P_TEMPS, uint dossard);
void supprimerCompetiteur(P_COMPETITEUR);
char * competiteur_str(P_COMPETITEUR);

/***** Stucture de course ******/
typedef struct {
    uint nb; // le nombre actuel de compétiteurs
    uint taille;
    P_COMPETITEUR * liste;
} Course;
typedef Course * P_COURSE;

void creerCourse(P_COURSE, uint);
uint echanger(P_COURSE, uint, uint);
void trier(P_COURSE, char);
void ajouterTemps(P_COURSE, uint, uint, uint, uint, uint);
void supprimer(P_COURSE, uint);
void afficherCourse(P_COURSE);