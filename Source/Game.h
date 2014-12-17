#ifndef __GAME_H__
#define __GAME_H__

#include <SDL.h>
#include <SDL_image.h>
#include "Objeto.h"
#include "Nave.h"

class CGame
{
public:
	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();

	enum Estado
	{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZANDO
	};

private:
	void Iniciando();
	void MoverEnemigo();
	bool EsLimitePantalla(Objeto*objeto, int bandera);
	
	Uint8 *keys;//Esta variable nos servira para ver si determinados teclas estan o no pulsadas
	SDL_Event event;//La variable event de tipo evento de SDL nos servira para monitorizar el teclado
	
	SDL_Surface *screen;
	Nave*nave;
	Objeto *enemigoArreglo[10];  //Creamos objeto del tipo NAVE
	Estado estado;
	Objeto *fondo;
	
	//int tiempoFrameFinal;
	
};
#endif