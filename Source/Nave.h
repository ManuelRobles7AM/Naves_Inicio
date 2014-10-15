#ifndef __NAVE_H__
#define __NAVE_H__
#include "Sprite.h"
class Nave{
	Sprite* sprite;
	int x;
	int y;
public:
	void Mover(int posicion);
	void Movery(int posicion);
	Nave(SDL_Surface*screen,char *RutaImagen);//Constructor
	void Pintar();
	
	

};
#endif