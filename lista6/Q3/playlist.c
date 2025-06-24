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

int duracao_playlist(Playlist *playlist){
    if(playlist->inicio == NULL){
        return 0;
    }
       
    Playlist playlistAtual = *playlist;
    playlistAtual.inicio = playlist->inicio->prox;
    return playlist->inicio->musica.duracao + duracao_playlist(&playlistAtual);
}





