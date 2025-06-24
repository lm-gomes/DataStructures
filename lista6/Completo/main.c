#include <stdio.h>
#include "playlist.h"

int main(){
    

    //Criando a playlist
    Playlist *playlist = criar_playlist();

    //Adicionando músicas à playlist (você pode seguir o mesmo padrão para adicionar a sua própria música)
    adicionar_musica(playlist, "Lose Yourself", "Eminem", 300);
    adicionar_musica(playlist, "Billie Jean", "Michael Jackson", 245);
    adicionar_musica(playlist, "Wish You Were Here", "Pink Floyd", 250);
    adicionar_musica(playlist, "Televisao", "Titas", 230);
    

    //Retorna 1 se a playlist conter a música especificada e 0 se não contém
    if(pertence_playlist(playlist, "Wish You Were Here")){
        printf("\nV - Musica pertence a playlist! - V\n");
    }
    else{
        printf("\nX - Musica nao pertence - X!\n");
    }

    //Mostra a duração da playlist inteira em segundos
    printf("\nDuracao da playlist > %d\n\n", duracao_playlist(playlist));

    //Exibir todas as musicas da playlist
    exibir_musicas(playlist);

    //Navega em reverso pela quantidade de casas especificadas, começando do final da lista
    navega_playlist(playlist, 2);
    
    //Apaga a playlist
    apagar_playlist(playlist);
    
    return 0;
}
