#include "Nave.h"

Nave::Nave(SDL_Surface*screen, char *RutaImagen, int x, int y){
	sprite = new Sprite(screen);
	sprite->CargarImagen(RutaImagen);
	h = sprite->HeightModule(0);
	w = sprite->WidthModule(0);
	this->x = x;
    this->y = y;
	autoMovimiento = false;
	pasoLimite = 0;
	pasoActual = 0;
}
void Nave::SetAutoMovimiento(bool autoMovimiento){
	this->autoMovimiento = autoMovimiento;
}
void Nave::Pintar(){

	sprite->PintarModulo(0, x, y);
}


void Nave::Actualizar(){
	if (autoMovimiento)
	{
		Mover(1);
	}
	if (pasoLimite>0)
	{
		//pasoActual++;
		if (pasoActual >= pasoLimite)
			pasoActual = 0;
	}
	
}

void Nave::Mover(int posicion){
	
	
		x += posicion;
	
	
	
}
void Nave::Movery(int posicion){
	y += posicion;

}

int Nave::ObtenerX()
{
	return x;
}
int Nave::ObtenerY()
{
	return y;
}

int Nave::ObtenerW()
{
	return w;
}

int Nave::ObtenerH()
{
	return h;
}

void Nave::SetPasoLimite(int pasos)
{
	this->pasoLimite = pasos;
}

int Nave::ObtenerPasoActual()
{
	return pasoActual;
}
void Nave::IncrementarPasoActual()
{
	pasoActual++;
}

//bool Nave::EstaColisionando(Nave*b)
//{
//
//
//}



//"../Data/minave.bmp"