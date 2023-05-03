#include "Partie1.h"

int hashFile(char *source, char *dest)
{/*hashfile calcule le hash du contenu du premier fichier grace a la commande sha256 et stocke le resultat dans le deuxieme fichier 
-source et dest sont les chemins des deux fichiers en question  
cette fonction construit dabord la commande voulue en la stockant dans la variable commande ensuite on l'execute grace a la commande system*/

    char commande[2000]; // stockage de la commande qui permet de hasher ele contenu du fichier source puis redirection pour l'ecrire dans le fichier dest
    sprintf(commande, "sha256sum %s | cut -d' ' -f1 > %s", source, dest);
    return system(commande); // execution de la commande et retour de la valeur retournée par la fonction system
}

char *sha256file(char *file)
{/*cette fonction execute la commande sha256 avec le fichier file et le stocke dans un fichier temporaire ensuite alloue un espace memoire pour lire la chaine du fichier temporaire et la retourner  */

    static char template[] = "/tmp/myfileXXXXXX";
    char fname[1000];
    strcpy(fname, template);
    int fd = mkstemp(fname);
    char commande[2000];
    char hash[200];

    // stocker la commande à éxécuter dans le parametre commande (string)
    sprintf(commande, "sha256sum %s > %s", file, template);
    // execution de la commande
    system(commande);
    // ouverture du fichier temporaire resultat du hash
    FILE *fich = fopen(template, "r");
    // stocker le hash dans une variable hash
    fscanf(fich, "%s", hash);
    // allocation dynamique de mémoire sinon gcc nous crie dessus
    char *resultat = (char *)malloc(200);
    strcpy(resultat, hash);
    // suppression du fichier tmp
    fclose(fich);
    remove(template);
    return resultat;
}

List *initList()
{/*initialisation d'une liste vide   */ 
    List *liste = (List *)malloc(sizeof(List));
    (*liste) = NULL;
    return liste;
}
void freeList(List* liste){
	
	Cell* current = *liste;
	while(current!=NULL){
		Cell* next = current->next;
		free(current->data);
		free(current);
		current =next;
	}
	*liste = NULL;
	
}

Cell* buildCell(char *ch)
{ /*allocation et retour de la cellule d'une liste  */
    Cell* new = (Cell*)malloc(sizeof(Cell));
    new->data = strdup(ch);
    new->next = NULL;
    return new;
}

void insertFirst(List *L, Cell *C)
{/*fonction permettant l'insertion en tete  */

    if ((*L) == NULL)
    {
        (*L) = C;
    }
    else
    {
        C->next = (*L);
        (*L) = C;
    }
}

char* ctos(Cell* c)
{ /*retourne la chaine de caracteres correspondante a la cllule  */
    return c->data;
}

char* ltos(List *L)
{	/*transforme une liste en une chaine de caracteres  */
	if(*L ==NULL){
		return " ";
	}
	
    char *resultat = malloc(MAX);
    Cell *current = (*L);

    while (current != NULL)
    {                              // parcourir la liste de Cell
        char *res = ctos(current); // application de la fonction ctos sur chaque cell
        
        strcat(res, "|");
        strcat(resultat, res); // concatenation avec le resultat precedent
        //free(res);
        current = current->next; // increment
    }
    return resultat;
}

Cell* listGet(List *L, int i)
{/* retourne le i eme element de la liste */
    Cell *tmp = (*L);
    while ((tmp!=NULL) && (i > 0)){
        tmp++;
        i--;
    }
    return tmp;
}

Cell* searchList(List *L, char *str){
    List ptr = (*L);
    Cell *current = (*L);
    while((ptr !=NULL) && (strcmp(str,ptr->data) !=0)){
        ptr=ptr->next;
    }
    



    
    while (current){
        if (strcmp(current->data, str) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return ptr;
}


List* stol(char *s)
{
    List *liste = malloc(sizeof(List));
    char *debut = s;
    while (*s != '\0')
    {
        if (*s == '|')
        {
            // on vient de trouver un nouveau mot
            Cell *new = (Cell *)malloc(sizeof(Cell));
            new->data = strndup(debut, s - debut);
            new->next = *liste;
            // ajout de la cellule créée
            *liste = new;
            debut = s + 1; // mise a jour du depart
        }
        s++;
    }
    return liste;
}

void ltof(List *L, char *path)
{
    /*ecriture de la liste L dans le fichier path */
    FILE *file = fopen(path, "w");
    Cell *tmp = *L;
    while (tmp)
    {
        fprintf(file, "%s\n", tmp->data);
        tmp = tmp->next;
    }
    fclose(file);
}

List* ftol(char *path){

    FILE *file = fopen(path, "r");
    List *liste = (List *)malloc(sizeof(List));
    char buffer[256];
    while (fgets(buffer, 256, file) != NULL)
    {
        char *tmp = strchr(buffer, '\n');
        *tmp = '\0'; // remplacement du \n par le marqueur de fin de chaine
        Cell *new = (Cell *)malloc(sizeof(Cell));
        new->data = strdup(buffer);
        new->next = *liste;
        *liste = new;
    }
    fclose(file);
    return liste;
}

List* listdir(char *root_dir)
{
    List *liste = (List *)malloc(sizeof(List));
    DIR *dp = opendir(root_dir);
    struct dirent *ep;
    if (dp != NULL)
    {
        while ((ep = readdir(dp)) != NULL)
        {
            Cell *new = (Cell *)malloc(sizeof(Cell));
            char *nom = (char *)malloc((strlen(ep->d_name) + 1));
            strcpy(nom, ep->d_name);
            new->data = nom;
            new->next = (*liste);
            (*liste) = new; // insertion en tete
        }
    }
    return liste;
}

int file_exists1(char *file){

 	List* listDir = listdir(".");
 	Cell* tmp = (*listDir);
 	while(tmp){
 		
 	//parcourir la liste et chercher la chaine correspondante 
 	
    	if (strcmp(tmp->data, file) == 0)
            {
            	freeList(listDir);
                return 1;
            }
        tmp = tmp->next;
     }
     
	 freeList(listDir);    
     return 0;
}

int file_exists(char* file){
	struct stat buffer;
	return (stat(file,&buffer)==0);
}


void cp(char *to, char *from)
{
    FILE *src = fopen(from, "r");
    if (!src)
    {
        fprintf(stderr, "erreur ouverture du fichier source\n");
        return;
    }
    FILE *dest = fopen(to, "w");
    char buffer[2000];
    while (fgets(buffer, 2000, src))
    {
        fputs(buffer, dest);
    }
    fclose(src);
    fclose(dest);
}

char* hashToPath(char *hash)
{
    char *path = (char *)malloc(strlen(hash) + 2);
    strncpy(path, hash, 2); // on commence par copier les deux premiers caracteres du hash
    path[2] = '/';
    strncpy(path + 3, hash + 2, strlen(hash) - 2);
    path[strlen(hash)] = '\0';
    return path;
}



char* blobFile(char *file)
{
    char *hash = sha256file(file);
    char* tmp = strdup(hash);
 
    if (!file_exists(tmp))
    {
        char buff[1000];
        sprintf(buff, "mkdir %s", tmp);
        system(buff);
    }
    char *ch = hashToPath(hash);
    cp(ch, file);
    return tmp;
}










