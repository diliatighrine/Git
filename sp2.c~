#include "Partie1.h"
int getChmod(const char *path)
{
    struct stat ret;

    if (stat(path, &ret) == -1)
    {
        return -1;
    }
    return (ret.st_mode & S_IRUSR) | (ret.st_mode & S_IWUSR) | (ret.st_mode & S_IXUSR) | (ret.st_mode & S_IRGRP) | (ret.st_mode & S_IWGRP) | (ret.st_mode & S_IXGRP) | (ret.st_mode & S_IROTH) | (ret.st_mode & S_IWOTH) | (ret.st_mode & S_IXOTH);
}

void setMode(int mode, char *path)
{
    char buff[100];
    sprintf(buff, "chmod %d %s", mode, path);
    system(buff);
}



WorkFile *createWorkFile(char *name)
{
    WorkFile* new = (WorkFile*)malloc(sizeof(WorkFile));
	new->name=strdup(name);
	new->hash=sha256file(name);
	new->mode=getChmod(name);
	return new;
}

char *wfts(WorkFile *wf)
{
    char *resultat = (char *)malloc(1000); // 10 a verifier
    sprintf(resultat, "%s\t%s\t%d", wf->name, wf->hash, wf->mode);
    return resultat;
}

WorkFile *stwf(char *ch){
    WorkFile *wf = (WorkFile *)malloc(sizeof(WorkFile));
    char* tmp = ch;
    char* tmp2 = NULL;
    while (*tmp != '\t' && *tmp != '\0'){
        tmp++;
    }

    if (*tmp != '\0')
    {

        int taille = tmp - ch;
        wf->name = (char *)malloc(taille + 1);
		int i=0;
        for ( i = 0; i < taille; i++)
        {
            wf->name[i] = ch[i];
        }
        wf->name[i] = '\0';
        // traitement du deuxieme champ :
        tmp2 = tmp + 1;
        while (*tmp2 != '\t' && *tmp2 != '\0')
        {
            tmp2++;
        }

        if (*tmp2 != '\0')
        {
            taille = tmp2 - (tmp + 1);
            wf->hash = (char *)malloc(taille + 1);
            for (int j = 0; j < taille; j++)
            {
                wf->hash[j] = tmp[1 + j];
            }
            wf->hash[taille] = '\0';
        }
        // conversion du mode en entier
        int mode = 0;
        tmp = tmp2 + 1;
        while (*tmp >= '0' && *tmp <= '9')
        {
            mode = 10 * mode + (*tmp - '0');
            tmp++;
        }
        wf->mode = mode;

       
    }
     return wf;
}

    WorkTree *initWorkTree()
    {
        WorkTree *wt = (WorkTree *)malloc(sizeof(WorkTree));
        wt->tab = malloc(SIZE * sizeof(WorkFile));
        wt->size = SIZE;
        wt->n = 0;

        return wt;
    }
    
    
    void freeWorkTree(WorkTree* wt){
    	for(int i=0;i<wt->n;i++){
    		
    		free(wt->tab[i].name);
    		free(wt->tab[i].hash);
    	}
    	free(wt->tab);
    	free(wt);
    }
    		

    int inWorkTree(WorkTree * wt, char *name)
    {
        for (int i = 0; i < wt->n; i++)
        {
            if (strcmp(wt->tab[i].name, name) == 0)
            {
                return i;
            }
        }

        return -1;
    }

    int appendWorkTree(WorkTree * wt, char *name, char *hash, int mode)
    {

        if (inWorkTree(wt, name) != -1)
        {
            return -1;
        }

        if (wt->n < wt->size)
        {
            WorkFile *new = malloc(sizeof(WorkFile));
            new->name = strdup(name);
            new->hash = strdup(hash);
            new->mode = mode;
            wt->tab[wt->n] = (*new);
            wt->n++;

            return 0;
        }
    }

    char *wtts(WorkTree * wt)
    {
        char *res = (char *)malloc(wt->n * 300);
        res="";
        for (int i = 0; i < wt->n; i++)
        {
            sprintf(res + strlen(res), "%s %s %d\n", (wt->tab[i]).name, (wt->tab[i]).hash, (wt->tab[i]).mode);
        }
        return res;
    }

    int wttf(WorkTree * wt, char *file)
    {
        FILE *f = fopen(file, "w");
        if (f == NULL)
        {
            printf("erreur ouverture fichier");
            return -1;
        }
        // convertir le WorkTree en une chaine de caracteres en utilisant la fonction précédente
        char *string = wtts(wt);
        fputs(string, f);
        fclose(f);
        free(string);

        return 0;
    }
    
     
    
    
    WorkTree* stwt(char* ch){
    	int i = 0;
    	int n=0;
    	WorkTree* wt = initWorkTree();
    	char* tmp;
    	char* res=(char*)malloc(1000);
    	while(i < strlen(ch)){
    		tmp= strchr(ch+i,'\n');
    		if(tmp==NULL){
    			n=strlen(ch)+1;
    		}else{
    			n=tmp-ch+1;
    		}
    		
    		
    		memcpy(res,ch+i,n-i-1);
    		res[n-i-1]='\0';
    		i=n;
    		WorkFile* wf = stwf(res);
    		appendWorkTree(wt,wf->name,wf->hash,wf->mode);
    	}
    	return wt;
    }
    
    	
    
    
    
    
    
    
    

    WorkTree *ftwt(char *file)
    {
        FILE *f = fopen(file, "r");
        WorkTree* wt = initWorkTree();

        char *ligne =NULL;
        size_t len = 0;
        int numChamp = 1; // champ actuel 1:nom 2:hash 3:mode

        while (getline(&ligne, &len, f) != -1)
        {
            if (numChamp == 1)
            {
                if(ligne!=NULL){
                
                	wt->tab[wt->n].name = strdup(ligne);
                	numChamp++;
                }
            }

            else if (numChamp == 2)
            {
                if(ligne !=NULL){
                
                	wt->tab[wt->n].hash = strdup(ligne);
                	numChamp++;
                }
            }

            else if (numChamp == 3)
            {
                if(ligne!=NULL){
                  
                wt->tab[wt->n].mode = atoi(ligne);
                numChamp = 0;
                wt->n++;
                if (wt->n == wt->size)
                {
                    break;
                }
              }
            }
        }
        fclose(f);
        return wt;
    }


    char *blobWorkTree(WorkTree * wt)
    {
        // creation du fichier temporaire :
        static char template[] = "/tmp/myfileXXXXXX";
        char fname[1000];
        strcpy(fname, template);
        int fd = mkstemp(fname);

        // ecriture du WorkTree dans le fichier temporaire
         wttf(wt, template);
        // calcul du hash du fichier temporaire

        char *resultat = sha256file(template);
        remove(template);
        return resultat;
    }

    char *saveWorkTree(WorkTree * wt, char *path)
    {
        char *hash;
        for (int i = 0; i < wt->n; i++)
        {
            WorkFile *wf = &(wt->tab[i]);
            if (wf->hash == NULL)
            {                                                               // pas encore enregisté
                char *fullpath = malloc(strlen(path) + strlen(wf->name) + 2); // 2 pour '\0' et '/'
                    sprintf(fullpath, "%s/%s", path, wf->name);
                List *lst = listdir(fullpath);
                if (lst != NULL)
                {                                // il s'agit d'un repertoire
                    char *chaineRep = ltos(lst); // fich1|fich2|rep1...
                    WorkTree *wt2 = initWorkTree();
                    char *organise = strtok(chaineRep, "|");
                    while (organise)
                    {
                        // on cree un workFile pour chaque nom
                        WorkFile *wf = createWorkFile(organise);
                        appendWorkTree(wt2, wf->name, wf->hash, wf->mode);
                        organise = strtok(NULL, "|"); // on met ici NULL car lorsqu'on appelle la fonction strtok pour la deuxieme fois , ca luiindique qu'il faut continuer a extraire la prochaine sous chaine a partir de la derniere position d'arret
                    }
                    char *rechash = saveWorkTree(wt2, fullpath);
                    wf->hash = rechash;
                    wf->mode = getChmod(fullpath);
                    freeWorkTree(wt2);
                    free(chaineRep);
                }
                else
                { // il s'agit d'un fichier
                    char *fichhash = blobFile(fullpath);
                    wf->hash = fichhash;
                    wf->mode = getChmod(fullpath);
                    
                }

                free(fullpath);
            }
            else
            {
                continue;
            }
        }

        hash = blobWorkTree(wt);
        freeWorkTree(wt);
      
        return hash;
    }
    
    int isWorkTree(char* hash){
    	if(file_exists(strcat(hashToPath(hash),".t"))){ //c'est le repertoire existe
    		return 1;
    	}
    	if(file_exists(hashToPath(hash))){  //c'est le fichier qui existe
    		return 0;
    	}
    	//ni l'un ni l'autre => il est out 
    	return -1;
    	
	}
	
    void restoreWorkTree(WorkTree * wt, char *path){
    	for(int i=0;i<wt->n;i++){
    		//concatenation du path:
    		char *fullpath = malloc(strlen(path) + strlen(wt->tab[i].name) + 2); // 2 pour '\0' et '/'
            sprintf(fullpath, "%s/%s", path, wt->tab[i].name);
            char* patho = hashToPath(wt->tab[i].hash);
            char* hash=wt->tab[i].hash;
            
            if(isWorkTree(hash) == 0){ //s'il s'agit d'un fichier 
            	cp(fullpath,patho);
            	setMode(getChmod(patho),fullpath);
            }else{
            	if(isWorkTree(hash)==1){ //s'il s'agit d'un repertoire 
            		strcat(patho,".t");
            		WorkTree* new = ftwt(patho);
            		restoreWorkTree(new,fullpath);
            		setMode(getChmod(patho),fullpath);
            	}
            }
         }
    }  
     
     
    		
    		
    		
    		
    		
    		
    		
    		
    	
    
