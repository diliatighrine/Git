#include "Partie1.h"

kvp *createKeyVal(char *key, char *val)
{
    kvp *k = (kvp *)malloc(sizeof(kvp));
    k->key = strdup(key);
    k->value = strdup(val);
    return k;
}

void freeKeyVal(kvp *kv)
{
    free(kv->key);
    free(kv->value);
    free(kv);
}

char *kvts(kvp *k)
{
    char *buff = (char *)malloc(100);
    sprintf(buff, "%s : %s", k->key, k->value);
    return buff;
}

kvp *stkv(char *str)
{
    char key[100], val[100];
    sscanf(str, "%s : %s", key, val);
    return createKeyVal(key, val);
}

Commit *initCommit()
{
    Commit *c = (Commit *)malloc(sizeof(Commit));
    c->T = malloc(SIZE * sizeof(Commit));
    c->size = SIZE;
    for (int i = 0; i < c->size; i++)
    {
        c->T[i] = NULL;
    }
    c->n = 0;
    return c;
}

// fonction de hashage choisie
unsigned long hash(unsigned char *str)
{
    unsigned int hash = 0;
    int c;

    while (c = *str++)
        hash += c;

    return hash;
}

void commitSet(Commit *c, char *key, char *value)
{
    unsigned long p= hash(key) % (c->size);
    while (c->T[p] != NULL)
    {
        p = (p + 1) % (c->size); // probing lineaire
    }
    c->T[p] = createKeyVal(key, value);
    c->n++;
}

Commit *createCommit(char *hash)
{
    Commit *c = initCommit();
    commitSet(c, "tree", hash);
    return c;
}

char *commitGet(Commit *c, char *key)
{
    int p = hash(key) % (c->size);
    int cpt = 0;
    while ((c->T[p] != NULL) && (cpt < c->size))
    {
        if (strcmp(c->T[p]->key, key) == 0)
        {
            return c->T[p]->value;
        }

        p = (p + 1) % (c->size);
        cpt++;
    }
    return NULL;
}

char *cts(Commit *c)
{
    char *str = (char *)malloc(c->n * 100);
    for (int i = 0; i < c->size; i++)
    {
        if (c->T[i] != NULL)
        {
            strcat(str, kvts(c->T[i]));
            strcat(str, "\n");
        }
    }
    return str;
}

Commit *stc(char *ch)
{
    int pos = 0;
    int n = 0;
    char sep = '\n';
    char *ptr;
    char *res = (char *)malloc(1000);
    Commit *c = initCommit();
    while (pos < strlen(ch))
    {
        ptr = strchr(ch + pos, sep);
        if (ptr == NULL)
        {
            n = strlen(ch) + 1;
        }
        else
        {
            n = ptr - ch + 1;
        }
        memcpy(res, ch + pos, n - pos - 1);
        res[n - pos - 1] = '\0';
        pos = n;
        kvp *element = stkv(res);
        commitSet(c, element->key, element->value);
    }
    return c;
}

void ctf(Commit *c, char *file)
{
    FILE *fp = fopen(file, "w");
    if (fp != NULL)
    {
        fputs(cts(c), fp);
        fclose(fp);
    }
}


//Commit* ftc(char* file){
	
	

char *blobCommit(Commit *c)
{
    char fname[100] = "/tmp/myfileXXXXXX";
    int fd = mkstemp(fname);
    ctf(c, fname);
    char *hash = sha256file(fname);
    char *ch = hashToPath(hash);
    strcat(ch, ".c");
    cp(ch, fname);
    return hash;
}

void initRefs()
{
    if (!file_exists(" .refs"))
    {
        system("mkdir .refs");
        system("touch .refs/master");
        system("touch .refs/HEAD");
    }
}

void createUpdateRef(char *ref_name, char *hash)
{
    char buff[100];
    sprintf(buff, "echo %s > .refs/%s", hash, ref_name);
    system(buff);
}

void deleteRef(char *ref_name)
{
    char buff[256];
    sprintf(buff, ".refs/%s", ref_name);
    if (!file_exists(buff))
    {
        printf("The reference %s does not exist", ref_name);
    }
    else
    {
        sprintf(buff, "rm .ref/%s ", ref_name);
        system(buff);
    }
}

char *getRef(char *ref_name)
{

    char *res = (char *)malloc(256);
    res="";
    char buff[256];
    sprintf(buff, ".refs/%s", ref_name);
    if (!file_exists(buff))
    {
        printf("The reference %s does not exist", ref_name);
        return res;
    }
    FILE *fp = fopen(buff, "r");
    if (fp == NULL)
    {
        printf("Erreur ouverture fichier");
        return res;
    }
    fgets(res, 256, fp);
    fclose(fp);
    return res;
}

void createFile(char *file)
{
    char buff[256];
    sprintf(buff, "touch %s", file);
    system(buff);
}

void myGitAdd(char *file_or_folder)
{
    WorkTree *wt;
    if (!file_exists(".add"))
    {
        createFile(".add");
        wt = initWorkTree();
    }
    else
    {
        wt = ftwt(".add");
    }
    if (file_exists(file_or_folder))
    {
        appendWorkTree(wt, file_or_folder, NULL,0);
        wttf(wt, ".add");
        freeWorkTree(wt);
    }
    else
    {
        printf("file_or_folder %s does not exist \n", file_or_folder);
        freeWorkTree(wt);
    }
}

void myGitCommit(char *branch_name, char *message)
{
    if (!file_exists(".refs"))
    {
        printf("Il faut d'abord initialiser les references du projet ");
        return;
    }

    char buff[256];
    sprintf(buff, ".refs/%s", branch_name);
    if (!file_exists(buff))
    {
        printf("La branche nexiste pas");
        return;
    }

    char *last_hash = getRef(branch_name);
    char *first_hash = getRef("HEAD");
    printf("%s\n",last_hash);
     printf("%s\n",first_hash);
    
    if (strcmp(last_hash, first_hash) != 0)
    {
        printf("HEAD doit pointer sur le dernier commit de la branche");
        return;
    }

    WorkTree *wt = ftwt(".add");
    char *hashwt = saveWorkTree(wt, ".");
    Commit *c = createCommit(hashwt);
    if (strlen(last_hash) != 0)
    {
        commitSet(c, "pred", last_hash);
    }
    if (message != NULL)
    {
        commitSet(c, "message", message);
    }

    char *hashdd = blobCommit(c);
    createUpdateRef(branch_name, hashdd);
    createUpdateRef("HEAD", hashdd);
    system("rm .add");
    freeWorkTree(wt);
}
