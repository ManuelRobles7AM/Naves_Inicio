#include <SDL.h>
#include <SDL_image.h>
#include "Nave.h"

class CGame
{
public:
	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();

	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZANDO
	};

private:
	void Iniciando();
	void MoverEnemigo();
	bool EsLimitePantalla(Nave*objeto, int bandera);
	
	Uint8 *keys;//Esta variable nos servira para ver si determinados teclas estan o no pulsadas
	SDL_Event event;//La variable event de tipo evento de SDL nos servira para monitorizar el teclado
	SDL_Surface *screen;
	Nave *nave;
	Nave *enemigo;  //Creamos objeto del tipo NAVE
	int tiempoFrameFinal;
	Estado estado;
	

};