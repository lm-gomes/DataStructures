#include <stdio.h>
#include "playlist.h"

int main(){
    

    //Creating playlist
    Playlist *playlist = criar_playlist();

    //Adding musics to the playlist (you can use the same pattern to add your own music)
    adicionar_musica(playlist, "Lose Yourself", "Eminem", 300);
    adicionar_musica(playlist, "Billie Jean", "Michael Jackson", 245);
    adicionar_musica(playlist, "Wish You Were Here", "Pink Floyd", 250);
    adicionar_musica(playlist, "Televisao", "Titas", 230);
    

    //Returns 1 if the playlist contains the music and 0 if it doesn't
    if(pertence_playlist(playlist, "Wish You Were Here")){
        printf("\nV - Musica pertence a playlist! - V\n");
    }
    else{
        printf("\nX - Musica nao pertence - X!\n");
    }

    //Prints playlist duration
    printf("\nDuracao da playlist > %d\n\n", duracao_playlist(playlist));

    //Show all playlist musics
    exibir_musicas(playlist);

    //Navigates in reverse through the amount of musics specified, starting at the end of the list
    navega_playlist(playlist, 2);
    
    //Deletes the playlist
    apagar_playlist(playlist);
    
    return 0;
}
