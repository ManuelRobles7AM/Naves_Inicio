#ifndef __NAVE_H__
#define __NAVE_H__
#include "Objeto.h"


class Nave
{
	Objeto * nave;
	Objeto * bala;
	Objeto * bala_enemigo;
	
public:
	Nave(SDL_Surface*screen, char *RutaImagen, int x, int y,int module);
	void Pintar();
	void Disparar();
	void Disparar_Enemigo();
	void MoverIzquierda();
	void MoverDerecha();
	void MoverArriba();
	void MoverAbajo();
	void Autodispara(int balas);
	
	Objeto * ObtenerNaveObjeto();

};

#endif