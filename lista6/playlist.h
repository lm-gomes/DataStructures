#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct playlist Playlist;
typedef struct no No;
typedef struct musica Musica;

Playlist *criar_playlist();
void adicionar_musica(Playlist *playlist, char *titulo, char *artista, int duracao);
void remover_musica(Playlist *playlist, char *titulo);
void exibir_musicas(Playlist *playlist);
void navega_playlist(Playlist *playlist, int num);
int pertence_playlist(Playlist *playlist, char *titulo);
int duracao_playlist(Playlist *playlist);
void apagar_playlist(Playlist *playlist);

#endif
