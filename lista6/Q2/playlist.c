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

