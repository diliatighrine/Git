#include "Partie1.h"

void main(int argc,char* argv[]){
	
	if(argc==1){
		printf("il faut un parametre \n");
		return ;
	}
	
	if(strcmp(argv[1],"init")==0){
		initRefs();
		
		return;
	}
	
	if(strcmp(argv[1],"refs_list")==0){
		printf("Refs : \n");
		if(file_exists(".refs")){
			List* liste = listdir(".refs");
			Cell* tmp = (*liste);
			for(tmp=(*liste);tmp!=NULL;tmp=tmp->next){
				if(tmp->data[0] == '.'){
					continue;
				}
				
				char* ref = getRef(tmp->data);
				printf(" %s \t %s \n",tmp->data,ref);
				free(ref);
				
			}
		freeList(liste);
		
		}
		
		return;
	}
	
	if(strcmp(argv[1],"create_ref")==0){
		createUpdateRef(argv[2],argv[3]);
		return;
	}
	
	if(strcmp(argv[1],"delete_ref")==0){
		deleteRef(argv[2]);
		return;
	}
	
	if(strcmp(argv[1],"add")==0){
		for(int i = 2;i<argc;i++){
			myGitAdd(argv[i]);
		}
		return;
	}
	
	
	if(strcmp(argv[1],"clear_add")==0){
		
		system("rm .add");
		return;
	}
	
	if(strcmp(argv[1],"list_add")==0){
		printf("Preparation\n");
		if(file_exists(".add")){
				WorkTree* wt= ftwt(".add");
				char* chaine=wtts(wt);
				printf("%s\n",chaine);
				freeWorkTree(wt);
				//if(chaine !=NULL){
					//free(chaine);
				//}  //attention munmap_chunk(): invalid pointer erreur 
		}
		return;
	}
	
	if(strcmp(argv[1],"commit")==0){
		if(argc==4){
			myGitCommit(argv[2],argv[4]);
		}else{
			myGitCommit(argv[2],NULL);
		}
	}
	return;
    
	
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
