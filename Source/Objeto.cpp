#include "Objeto.h"

 Objeto::Objeto(SDL_Surface*screen, char *RutaImagen, int x, int y, int module)
 
{
	this->module = module;
	sprite = new Sprite(screen);
	sprite->CargarImagen(RutaImagen);
	h = sprite->HeightModule(this->module);
	w = sprite->WidthModule(this->module);
	this->x = x;
    this->y = y;
	autoMovimiento = false;
	pasoLimite = 0;
	pasoActual = 0;
	IsVisible = true;
}

void Objeto::SetAutoMovimiento(bool autoMovimiento)
{
	this->autoMovimiento = autoMovimiento;
}

void Objeto::Pintar()
{
	if (IsVisible)
	{
		sprite->PintarModulo(module, x, y);
	}
		
	
}

void Objeto::Pintar(int module, int x, int y)
{
	if (IsVisible)
	{
		sprite->PintarModulo(module, x, y);
	}
}

void Objeto::SetVisible(bool IsVisible)
{
	this->IsVisible = IsVisible;
}


void Objeto::Actualizar()
{
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

void Objeto::Mover(int posicion)
{
	x += posicion;
}

void Objeto::Movery(int posicion)
{
	y += posicion;
}

int Objeto::ObtenerX()
{
	return x;
}
int Objeto::ObtenerY()
{
	return y;
}

int Objeto::ObtenerW()
{
	return w;
}

int Objeto::ObtenerH()
{
	return h;
}

void Objeto::SetPasoLimite(int pasos)
{
	this->pasoLimite = pasos;
}

int Objeto::ObtenerPasoActual()
{
	return pasoActual;
}

void Objeto::IncrementarPasoActual()
{
	pasoActual++;
}

bool Objeto::EstaColisionando(Objeto * b)
{
	return false;
}

void Objeto::PonerEn(int x, int y)
{
	this->x = x;
	this->y = y;
}
