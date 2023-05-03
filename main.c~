#include "Partie1.h"

int main(void){
	
	//test de la fonction hashFile:
	int res1 = hashFile("/users/nfs/Etu7/28721597/fichier1","/users/nfs/Etu7/28721597/fichier2");
	printf("resultat du hash : %d \n",res1);
	
	//test de la fonction sha256:
	char* res2 = sha256file("/users/nfs/Etu7/28721597/fichier1");
	printf("resultat de sha256file : %s\n", res2);
	
	//test de initList:
	List* res3 = initList();
	
	
	//test de buildCell:
    Cell* res4;
    res4 = buildCell("diliazelie");
    
	Cell* r = buildCell("ffgf");
	printf("check\n");
	
	printf("%s",r->data);
	
	
	//test de insertFirst
	insertFirst(res3,res4);
	printf("insertion reussie\n");
    
	//test de ctos
	char* res5 =NULL;
	res5= ctos(res4);
	
	
	
	//test de ltos 
	char* res6 = ltos(res3);
	
	//test de listGet
	Cell* elem = listGet(res3,1);
	
	//test de searchList
	Cell*res7= searchList(res3,"diliazelie");
	
	//test de stol
	List* res8 = stol("sdfhj|svfss|gfddg|");
	
	//test ltof
	ltof(res3,"/users/nfs/Etu7/28721597/ProjetSDD/fichier1");
	
	//test ftol
	List* res9 = ftol("/users/nfs/Etu7/28721597/ProjetSDD/fichier1");
	
	//test listdir
	List* res10 = listdir("/users/Etu7/28721597/tpBDD");
	//test de file_exists
	int e = file_exists("work.c");
	
	//test de la fonction cp :
	//cp("/users/Etu7/28721597/fichier1","/users/Etu7/28721597/fichier2");
	
	char* res11 = hashToPath("hgffddt");
	printf("resultat : %s",res11); // un slash entre le 2eme et 3 eme caractere 
	
	//blobFile("/users/Etu7/28721597/nouveau");
	
	//test createWorkFile
	WorkFile* wf= createWorkFile("ddd");
	
	//test wfts
	char* res12 = wfts(wf);
	//printf("%s\n",*res12);
	
	
	//test stwf
	WorkFile* w = stwf(res12);
	
	//test initWorktree
	
	WorkTree* wt = initWorkTree();
	
	//test inWorkTree 
	
	int res13 = inWorkTree(wt,"ddd");
	
	//test appendWorkTree
	int res14 = appendWorkTree(wt,"hhh","jjj",777);
	
	
	//test wtts
	char* res15 = wtts(wt);
	
	//test stwt 
	WorkTree* wt2 = stwt(res15);
	//test wttf
	
	int res16=wttf(wt,"/users/Etu7/28721597/ProjetSDD/nouveau");
	//test ftwt
	WorkTree* res17=ftwt("/users/Etu7/28721597/ProjetSDD/nouveau");
	//test blobWorkTree
	char* res18 = blobWorkTree(wt2);
	//test saveWorkTree
	char* enregi = saveWorkTree(wt,"/users/Etu7/28721597/ProjetSS/nouveau");
	//test restoreWorkTree
	restoreWorkTree(wt,"/users/Etu7/28721597/ProjetSDD/nouveau");
	
	//test createKeyVal
	kvp* k = createKeyVal("cle","valeur");
	//test kvts
	char* s= kvts(k);
	//test stkv
	kvp* retour = stkv(s);
	
	//test initCommit
	
	Commit* c = initCommit();
	
	//test commitSet
	commitSet(c,"hjk","hjj");
	
	//test createCommit 
	Commit* c2= createCommit("hjjk");
	
	
	//test commitGet
	
	char* c3=commitGet(c2,"tree");
	//test cts
	char* cc=cts(c);
	//test stc
	Commit* cr = stc(cc);
	
	//test ftc 
	ctf(cr,"/users/Etu7/28721597/ProjetSDD/nouveau");
	
	//test ctf
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}


