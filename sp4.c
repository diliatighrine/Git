#include "Partie1.h"


void initBranch(){
	FILE* file = fopen(".current-branch","w");
	if(file == NULL){
		fprintf(stderr,"Erreur lors de l'ouverture du fichier");
		return ;
	}

	fputs("master",file);
	fclose(file);
}


int branchExists(char* branch){
	List* references = listdir(".refs");
	return searchList(references,branch) != NULL;
}


void createBranch(char* branch){

	char* hash = getRef("HEAD"); //recuperation du hash du commit de la reference HEAD 
	createUpdateRef(branch,hash);//creation de la reference branch qui pointe vers le meme commit que HEAD 

}

char* getCurrentBranch(){
	FILE* file = fopen("current_branch","r");
	char* buffer = malloc(sizeof(char) *300);
	fscanf(file,"%s",buffer);
	return buffer;
}


void printBranch(char* branch){
	char* commit_hash = getRef(branch);
	char* buffer = (char*)malloc(100);
	sprintf(buffer,"%s.c",hashToPath(commit_hash));
	Commit* commit = ftc(buffer);

	while(commit !=NULL){
		if(commitGet(commit,"message")==NULL){
			printf("hash : %s\n",commit_hash);
		}else{
			printf("hash : %s  ,  message : %s\n",commit_hash,commitGet(commit,"message"));
		      }
	}
}




List* branchList(char* branch){
	List* liste = initList();
	Commit* c; 
	char* buff;
	char* ch = getRef(branch);    //le commitHash
	buff = (char*)malloc(100);
	sprintf(buff,"%s.c",hashToPath(ch));
	c = ftc(buff);


	while(c != NULL){
		//Cell *buildCell(char *ch)
		Cell * new = buildCell(ch); //creation
		//insertion en tete
		new->next = (*liste);
		(*liste) = new ;

		ch = commitGet(c,"predecessor");
		if(ch != NULL){

			sprintf(buff,"%s.c",hashToPath(ch));
			c = ftc(buff);
		}else{
			c = NULL;
		}
	}
	return liste;
}



List* getAllCommits(){
	List* liste1 = initList();
	List* liste2 = listdir(".refs");
	Cell* tmp = (*liste2);

	while(tmp){
		if(tmp->data[0] == '.'){
			continue;
		}

		List* liste3 = branchList(tmp->data);
		Cell* tmp2 = (*liste3);

		while(tmp2){
			if(searchList(liste1,tmp2->data) == NULL){
				Cell* new = buildCell(tmp2->data);  //creation 
				new->next = (*liste1);//insertion en tete
				(*liste1) = new ;
			}

			tmp2=tmp2->next;
		}
		tmp = tmp->next;
	}
	return liste1;
}




void restoreCommit(char* hash_commit){
	
	
    char * buff = malloc ( sizeof ( char ) *100) ;
	sprintf ( buff , "%s .c" , hashToPath ( hash_commit) ) ;
	Commit* commit = ftc(buff);
	char* res=commitGet(commit,"tree");
	char* tree = strcat(hashToPath(res),".t");
	WorkTree* wt = ftwt(tree);
	restoreWorkTree(wt,".");
}


void myGitCheckoutBranch(char* branch){

	FILE* f = fopen(".current_branch","w");
	fprintf(f,"%s",branch);
	fclose(f);

	char* hash = getRef(branch);
	createUpdateRef("HEAD",hash);
	restoreCommit(hash);
}



List* filterList(List* L, char* pattern){
	List* res = initList();
	Cell* current = (*L);


	while(current != NULL){
		if(strcmp(current->data,pattern) == 0){
			Cell* new = buildCell(current->data);
			new->next = (*res);
		       (*res) = new;
		}
		current = current->next;
	}
	

	return res;
}






	

	
	
	

		


	




























	
