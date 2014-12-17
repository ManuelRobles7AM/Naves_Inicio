#include "SpriteDef.h"
#include "Config.h"

SpriteDef::SpriteDef()
{
	modulos[0].id = MODULO_MINAVE_NAVE;
	modulos[0].x = 0;
	modulos[0].y = 0;
	modulos[0].w = 64;
	modulos[0].h = 64;

	modulos[1].id = MODULO_ENEMIGO_NAVE;
	modulos[1].x = 0;
	modulos[1].y = 0;
	modulos[1].w = 54;
	modulos[1].h = 61;
	
	modulos[2].id = MODULO_BALAS_BALA;
	modulos[2].x = 0;
	modulos[2].y = 0;
	modulos[2].w = 5;
	modulos[2].h = 21;

	modulos[3].id = MODULO_FONDO;
	modulos[3].x = 0;
	modulos[3].y = 0;
	modulos[3].w = 640;
	modulos[3].h = 480;

	modulos[4].id = MODULO_BALAS_ENEMIGO;
	modulos[4].x = 0;
	modulos[4].y = 0;
	modulos[4].w = 5;
	modulos[4].h = 21;


	
}