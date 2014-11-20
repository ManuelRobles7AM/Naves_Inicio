#include "Sprite.h"
#include <SDL.h>
Sprite::Sprite(SDL_Surface*screen) //Constructor
{
	screen;
	this->screen= screen;
}
//Destructor
Sprite::~Sprite() //Elimina puntero de Imagen
{
	SDL_FreeSurface(imagen);
}

void Sprite::CargarImagen(char * path) 
{
	imagen=SDL_LoadBMP(path);
	SDL_SetColorKey(imagen, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(imagen->format, 255, 0, 0));
	
	
}


void Sprite::PintarModulo(int nombre, int x, int y)
{
	SDL_Rect source;
	source.x = spriteDef.modulos[nombre].x;
	source.y = spriteDef.modulos[nombre].y;
	source.w = spriteDef.modulos[nombre].w;
	source.h = spriteDef.modulos[nombre].h;
	SDL_Rect destino;
	destino.x=x;
	destino.y=y;
	
	SDL_BlitSurface(imagen, &source, screen, &destino);
}

int Sprite::WidthModule(int module){
	return spriteDef.modulos[module].w;
}

int Sprite::HeightModule(int module){
	return spriteDef.modulos[module].h;


}


