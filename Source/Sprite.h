#ifndef __SPRITE_H__
#define __SPRITE_H__
#include <SDL.h>
#include "SpriteDef.h"

class Sprite
{
	SDL_Surface *imagen; //Imagen a manipular
	SDL_Surface *screen;//Pantalla donde imprimiremos la imagen
	SpriteDef spriteDef;//Definiciones de sprite 
	
public:
	Sprite(SDL_Surface*screen); //Constructor que recibe la pantalla
	~Sprite();//Destructor, se llama con delete
	void CargarImagen(char * path);//Direccion de la imagen
	void PintarModulo(int nombre, int x, int y);
	int WidthModule(int module);
	int HeightModule(int module);
	

};

#endif