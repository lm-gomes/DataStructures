#include <stdio.h>
#include <stdlib.h>



typedef struct no{
	int chave;
	struct no *esq;
	struct no *dir;
}No;

typedef struct arv {
	No *raiz;
}Arv;

No *minSubTree(No *raiz);


Arv *criar_arv(){
	Arv *arv = (Arv*)malloc(sizeof(Arv));
	if (arv != NULL){
		arv->raiz = NULL;
	}
	return arv;
}

int buscar(No *no, int chave){
	if (no == NULL)
		return 0;
	if (no->chave == chave)
		return chave;
	if (chave < no-> chave)
		return buscar(no->esq, chave);
	else{
		return buscar(no->dir, chave);
	}
}

No *inserir(No *raiz, int chave){
	if(raiz == NULL){
		No *no = (No*)malloc(sizeof(No));
		if(no != NULL){
			no->chave = chave;
			no->esq = NULL;
			no->dir = NULL;
			return no;
		}
		return NULL;	
	}

	if (chave < raiz->chave){
		raiz->esq = inserir(raiz->esq, chave);
	}
	else if(chave > raiz->chave){	
		raiz->dir = inserir(raiz->dir, chave);
	}
	return raiz;
}

No *remover(No *raiz, int chave){
	if(raiz == NULL){
			printf("Nao existe na arvore!\n");		
			return NULL;

	}
	
	if(raiz->chave == chave){
		if(raiz->esq == NULL && raiz->dir == NULL){
			No *raizTemp = NULL;
			free(raiz);
			return raizTemp;
		}
		else if(raiz->esq == NULL || raiz->dir == NULL){
			if(raiz->esq == NULL){
				No *raizTemp = raiz->dir;
				free(raiz);
				return raizTemp;
			}
			else{
				No *raizTemp = raiz->esq;
				free(raiz);
				return raizTemp;
			}	
		}
		else{
			No *menorDir = minSubTree(raiz->dir);
			
			raiz->chave = menorDir->chave;
			raiz->dir = remover(raiz->dir, menorDir->chave);
			return raiz;
		}
	}
	else{
		if(chave < raiz->chave){
				raiz->esq = remover(raiz->esq, chave);
		}
		else{
				raiz->dir = remover(raiz->dir, chave);
		}
	}
	return raiz;
}

No *minSubTree(No *raiz){
	raiz = raiz->esq;
	while(raiz->esq != NULL){
		raiz = raiz->esq;
	}
	return raiz;
}

int main(){
	Arv *myTree = (Arv*)malloc(sizeof(Arv));
	
	myTree->raiz = inserir(myTree->raiz, 10);
	myTree->raiz = inserir(myTree->raiz, 5);
	myTree->raiz = inserir(myTree->raiz, 4);
	myTree->raiz = inserir(myTree->raiz, 6);
	
	myTree->raiz = remover(myTree->raiz, 5);
	
	printf("%d\n", buscar(myTree->raiz, 4, 0));
	return 0;
}
