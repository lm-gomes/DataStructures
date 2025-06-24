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



