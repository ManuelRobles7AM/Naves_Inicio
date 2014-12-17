#ifndef __OBJETO_H__
#define __OBJETO_H__
#include "Sprite.h"

class Objeto
{
	Sprite* sprite;
	int x;
	int y;
	int h;
	int w;
	bool autoMovimiento;
	int pasoActual;
	int pasoLimite;
	int module;
	bool IsVisible;
public:
	void SetVisible(bool IsVisible);
	void Mover(int posicion);
	void Movery(int posicion);
	Objeto(SDL_Surface*screen,char *RutaImagen,int x,int y, int module);//Constructor
	void SetAutoMovimiento(bool autoMovimiento);
	void SetPasoLimite(int pasos);
	int ObtenerPasoActual();
	void IncrementarPasoActual();
	bool EstaColisionando(Objeto * b);
	void Pintar();
	void Pintar(int module, int x, int y);
	void Actualizar();
	int ObtenerX();
	int ObtenerY();
	int ObtenerW();
	int ObtenerH();
	void PonerEn(int x,int y);
	

	
	

};
#endif