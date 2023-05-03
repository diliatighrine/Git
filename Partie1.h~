#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <unistd.h> //gestion des fichiers temporaires 
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#define SIZE 1000
#define MAX 1000


typedef struct cell{

    char* data;
    struct cell* next;

}Cell;

typedef Cell* List;

typedef struct{
	char* name;
	char* hash;
	int mode;
}WorkFile;

typedef struct {
	WorkFile* tab;
	int size;
	int n;
}WorkTree;

typedef struct key_value_pair
{
	char *key;
	char *value;

} kvp;
typedef struct hash_table
{
	kvp **T;
	int n;
	int size;

} HashTable;

typedef HashTable Commit;

int hashFile(char *source, char *dest); //calcule le hash(en utilisant la commande sha256sum) du fichier source et l'ecrit dans le fichier dest 
char *sha256file(char *file); //renvoie une chaine de caracteres qui correspond au hash ddu fichier donné en parametres 
List* initList();
void freeList(List* liste);
Cell* buildCell(char* ch);
void insertFirst(List* L, Cell* C);
char* ctos ( Cell* c);
char* ltos ( List* L);
Cell* listGet(List* L, int i);
Cell* searchList(List* L, char*  str) ;
List* stol(char* s);
void ltof(List* L, char* path);
List* ftol(char* path);
List* listdir(char* root_dir);
int file_exists(char* file);
void cp(char* to, char* from);
char* hashToPath(char* hash);
char* blobFile(char* file);
int getChmod ( const char* path);
void setMode ( int mode , char* path);
WorkFile* createWorkFile(char* name);
void freeWorkTree(WorkTree* wt);
char* wfts(WorkFile *wf);
WorkFile*  stwf(char *ch);
WorkTree* initWorkTree();
int inWorkTree(WorkTree* wt, char* name);
int appendWorkTree(WorkTree *wt, char *name, char *hash, int mode);
char *wtts(WorkTree *wt);
WorkTree * stwt ( char * ch);
int wttf(WorkTree *wt, char *file);
WorkTree *ftwt(char *file);
char * hashToFile ( char * hash);
char* blobWorkTree(WorkTree *wt);
char* saveWorkTree(WorkTree *wt, char *path);
int isWorkTree(char *hash);
void restoreWorkTree ( WorkTree * wt , char * path);
kvp *createKeyVal(char *key, char *val);
void freeKeyVal(kvp *kv);
char *kvts(kvp *k);
kvp *stkv(char *str);
Commit *initCommit();
unsigned long hash(unsigned char *str);
void commitSet(Commit *c, char *key, char *value);
Commit* createCommit(char *hash);
char* commitGet(Commit *c, char *key);
char* cts(Commit *c);
Commit* stc(char *ch);
void ctf(Commit *c, char *file);
Commit* ftc(char *file);
char* blobCommit(Commit *c);
void initRefs ();
void createUpdateRef ( char * ref_name , char * hash);
void deleteRef(char *ref_name);
char* getRef(char *ref_name);
void createFile(char *file);
void myGitAdd(char *file_or_folder);
void myGitCommit(char *branch_name, char *message);

