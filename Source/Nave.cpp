#include "Nave.h"
#include "Config.h"
Nave::Nave(SDL_Surface*screen, char *RutaImagen){
	sprite = new Sprite(screen);
	sprite->CargarImagen(RutaImagen);
	x = (WIDTH_SCREEN / 2) - (sprite->WidthModule(0) / 2);
	y = (HEIGHT_SCREEN - 80) - (sprite->HeightModule(0));

}

void Nave::Pintar(){

	sprite->PintarModulo(0, x, y);
}

void Nave::Mover(int posicion){
	
	
		x += posicion;
	
	
	
}
void Nave::Movery(int posicion){
	y += posicion;

}


//"../Data/minave.bmp"