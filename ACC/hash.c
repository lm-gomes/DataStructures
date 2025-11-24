#include <stdio.h>
#include <stdlib.h>

#Árvore de Busca Binária

typedef struct no{
	int chave;
	struct no *esq;
	struct no *dir;
}No;

typedef struct arv {
	No *raiz;
}Arv;

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
		return 1;
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

	if (chave < raiz){
		raiz->esq = inserir(raiz->esq, chave);
	}
	else if(chave > raiz){
		raiz->dir = inserir(raiz->dir, chave);
	}
	return raiz;
}

int main(){
	
	return 0;
}