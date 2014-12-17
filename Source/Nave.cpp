#include "Nave.h"
#include "Config.h"

Nave::Nave(SDL_Surface * screen, char *RutaImagen, int x, int y, int module)
{
	nave = new Objeto(screen, RutaImagen, x, y, module);
	bala = new Objeto(screen, "../Data/balas.bmp", 0, 0, MODULO_BALAS_BALA);
	bala_enemigo = new Objeto(screen, "../Data/balas_enemigo.bmp", 0, 0, MODULO_BALAS_ENEMIGO);
	bala_enemigo->SetVisible(false);
	bala->SetVisible(false);
}

void Nave::Pintar()
{
	nave->Pintar();
	bala->Pintar();
	bala_enemigo->Pintar();
	bala_enemigo->Movery(2);
	bala->Movery(-2);
}

void Nave::Disparar()
{
	
	bala->SetVisible(true);
	bala->PonerEn(nave->ObtenerX()+nave->ObtenerW()/2, nave->ObtenerY());
	
}
void Nave::Disparar_Enemigo()
{

	bala_enemigo->SetVisible(true);
	bala_enemigo->PonerEn(nave->ObtenerX() + nave->ObtenerW() / 2, nave->ObtenerY());

}

void Nave::Autodispara(int Balas)
{
	if ((rand() % 100) < 1)
		Disparar_Enemigo();
}

void Nave::MoverAbajo()
{
	nave->Movery(5);
}

void Nave::MoverArriba()
{
	nave->Movery(-5);
}
void Nave::MoverDerecha()
{
	nave->Mover(5);
}
void Nave::MoverIzquierda()
{
	nave->Mover(-5);
}

Objeto * Nave::ObtenerNaveObjeto()
{
	return nave;
}