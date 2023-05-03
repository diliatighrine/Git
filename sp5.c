#include "Partie1.h"

WorkTree* mergeWorkTrees(WorkTree* wt1,WorkTree* wt2,List** conflicts){
    WorkTree* new = initWorkTree(); //initialisation du workTree resultat 
    for(int i = 0;i<wt1->n;i++){ //parcours du premier worKTree 
        WorkFile file1 = wt1->tab[i] ;
        int found = inWorkTree(wt2,file1.name);
        if(found!=-1){ //si fichier/repertoire present dans wt2
            if(strcmp(wt2->tab[found].hash , file1.hash) != 0){//les deux hash sont differents 
               Cell* cell = buildCell(file1.name);
               cell->next = (*conflicts);
               *conflicts = cell;
            }else{   //ajout du fichier/repertoire au nouveau workTree
                appendWorkTree(new,file1.name,file1.hash,file1.mode); 
            }

               


        }
    }
    for(int j =0;j<wt2->n;j++){
        WorkFile file2 = wt2->tab[j];
        int found2 = inWorkTree(wt1,file2.name);
        if(found2==-1){ //on ne traite pas le cas ou c'est different de -1 car il a deja traité dans le premier Worktree
            appendWorkTree(new,file2.name,file2.hash,file2.mode);//ajout de ce fichier/repertoire au nouveau workTree

        }

    }

    return new;
}

List* merge(char* remote_branch,char* message){
    List* conflicts = (List*)malloc(sizeof(List));

    conflicts = NULL;
    char* current = getCurrentBranch();
    WorkTree* fusion = mergeWorkTrees(,,conflicts);
    if(conflicts != NULL){
        return conflicts;
    }else{

    }



}

void createDeletionCommit(char* branch , List* conflicts , char* message){
    myGitCheckoutBranch(branch); //deplacement sur la branche voulue 
    char* current = getCurrentBranch();
    char* last_commit = getRef("master"); //getLastCommit
    restoreCommit(lastWt,last_commit);//workTree associé au dernier commit 

    







}
