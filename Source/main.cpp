#include "Game.h"
#include  <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>


// La funci�n principal del juego
int main(int argc, char *argv[]){
	CGame *navesGame = new CGame();//Cra un objeto usando apuntadores

	if(navesGame->Start())   
		navesGame->Finalize(); // Liberamos los recursos utilizados.
    
    return EXIT_SUCCESS;
}
