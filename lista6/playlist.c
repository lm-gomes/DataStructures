#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "playlist.h"

struct musica{
    char *titulo;
    char *artista;
    int duracao;
};

struct no{
    No *prox;
    Musica musica;
    No *ant;
};

struct playlist{
    No *fim;
    No *inicio;
    int tam;
};

Playlist *criar_playlist(){
    Playlist *playlist = (Playlist*)malloc(sizeof(Playlist));
    if(playlist == NULL){
        printf("Nao foi possivel criar a playlist...\n");
        return NULL;
    }
    playlist->inicio = NULL;
    playlist->fim = NULL;
    playlist->tam = 0;
    printf("Playlist criada!\n");  
    return playlist;  
}



void adicionar_musica(Playlist *playlist, char *titulo, char *artista, int duracao){
    No *no = (No*)malloc(sizeof(No));

    no->musica.titulo = (char*)malloc(strlen(titulo) + 1);
    no->musica.artista = (char*)malloc(strlen(artista) + 1);

    strcpy(no->musica.titulo, titulo);
    strcpy(no->musica.artista, artista);
    no->musica.duracao = duracao;
    
    if(playlist->inicio == NULL){
        playlist->inicio = no;
        no->ant = NULL;
    }
    else{
        playlist->fim->prox = no;
        no->ant = playlist->fim;
    }

    playlist->fim = no;
    no->prox = NULL;
    playlist->tam++;
    printf("Música adicionada!\n");
}


void exibir_musicas(Playlist *playlist){
    No *noAtual = playlist->inicio;
    int id = 1;
    for(int id = 1; noAtual != NULL; id++){
        printf("- - - - %d - - - -\nTitulo: %s\nArtista: %s\nDuracao: %d\n\n", id, noAtual->musica.titulo, noAtual->musica.artista, noAtual->musica.duracao);
        noAtual = noAtual->prox;
    }

}

void remover_musica(Playlist *playlist, char *titulo){
    No *noAtual = playlist->inicio;
    
    while(noAtual != NULL && strcmp(noAtual->musica.titulo, titulo) != 0){
        noAtual = noAtual->prox;
    }    
    if(noAtual == NULL){
        printf("Musica nao encontrada na playlist...\n");
        return;
    }
    
    if(noAtual->ant == NULL){
        playlist->inicio = noAtual->prox;
        noAtual->prox->ant = NULL;
    }
    else if(noAtual->prox == NULL){
        playlist->fim = noAtual->ant;
        noAtual->ant->prox = NULL;
    }
    else{
        noAtual->ant->prox = noAtual->prox;
        noAtual->prox->ant = noAtual->ant;
    }
    free(noAtual);
    playlist->tam--;
    
}

void navega_playlist(Playlist *playlist, int num){
    No *noAtual = playlist->fim;
    for(int i = 0; i < num; i++){
        noAtual = noAtual->ant;
    }
    printf("- - Voltando %d casas - -\nTitulo: %s\nArtista: %s\nDuracao: %d\n- - - - -", num, noAtual->musica.titulo, noAtual->musica.artista, noAtual->musica.duracao);

}

int pertence_playlist(Playlist *playlist, char *titulo){
    if(playlist->inicio == NULL){
        return 0;
    }

    if(strcmp(playlist->inicio->musica.titulo, titulo) == 0){
        return 1;
    }
    
    Playlist playlistAtual = *playlist;
    
    playlistAtual.inicio = playlist->inicio->prox;

    return pertence_playlist(&playlistAtual, titulo);
    
}

int duracao_playlist(Playlist *playlist){
    if(playlist->inicio == NULL){
        return 0;
    }
       
    Playlist playlistAtual = *playlist;
    playlistAtual.inicio = playlist->inicio->prox;
    return playlist->inicio->musica.duracao + duracao_playlist(&playlistAtual);
}

void apagar_playlist(Playlist *playlist){
    No *noAtual = playlist->fim;
    while(noAtual != NULL){
        No *noAnterior = noAtual->ant;
        free(noAtual);
        noAtual = noAnterior;
    }
    playlist->inicio = NULL;
    playlist->fim = NULL;
    playlist->tam = 0;
    free(playlist);
    printf("Playlist apagada com sucesso!\n");
}



