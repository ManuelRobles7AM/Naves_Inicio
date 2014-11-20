#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>



CGame::CGame()
{
	estado = Estado::ESTADO_INICIANDO;// Estado inicial del juego (corregido)
	atexit(SDL_Quit); 
}


// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize()
{
	delete(nave);
	delete (enemigo);

	SDL_FreeSurface(screen);
	SDL_Quit();
}

void CGame::Iniciando()
{
	
				if (SDL_Init(SDL_INIT_VIDEO))
				
				{
					printf("Eror %s ", SDL_GetError());
					exit(EXIT_FAILURE);
				}

				screen= SDL_SetVideoMode(WIDTH_SCREEN,HEIGHT_SCREEN,24,SDL_HWSURFACE);
				
				if (screen==NULL)
				{
					printf("Error %s ", SDL_GetError());
					exit(EXIT_FAILURE);
				}

				SDL_WM_SetCaption( "Mi primer Juego", NULL);
				/*x = (WIDTH_SCREEN / 2) - (sprite->WidthModule(0) / 2);
				y = (HEIGHT_SCREEN - 80) - (sprite->HeightModule(0));*/
				nave = new Nave(screen, "../Data/minave.bmp", (WIDTH_SCREEN / 2) /*- (sprite->WidthModule(0) / 2)*/, (HEIGHT_SCREEN - 80) /*- (sprite->HeightModule(0))*/);
				enemigo = new Nave(screen, "../Data/enemigo.bmp",0,0);//Crear objeto
				enemigo->SetAutoMovimiento(false);
				enemigo->SetPasoLimite(4);
				//delete nave;
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
          
	while (salirJuego == false){
		
		//Maquina de estados
		switch(estado)
		{
		case Estado::ESTADO_INICIANDO: //INICIALIZAR
			Iniciando();
			{

				printf("\n1. ESTADO_INICIANDO");

			};
			estado = ESTADO_MENU;
			break;
	
		case Estado::ESTADO_MENU: //MENU
			//nave->PintarModulo(0, 0, 0, 64, 64);
			//nave->PintarModulo(0, 100, 100);
			enemigo->Actualizar();
			MoverEnemigo();
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

			keys = SDL_GetKeyState(NULL);
			if (keys[SDLK_RIGHT])
			{
				if (!EsLimitePantalla(nave,BORDE_DERECHO))
				nave->Mover(2);
			}
			

			if (keys[SDLK_LEFT])
			{
				if (!EsLimitePantalla(nave, BORDE_IZQUIERDO))
				nave->Mover(-2);
			}
			if (keys[SDLK_UP])
			{
				if (!EsLimitePantalla(nave, BORDE_SUPERIOR))
				nave->Movery(-2);
			}
			if (keys[SDLK_DOWN])
			{
				if (!EsLimitePantalla(nave, BORDE_INFERIOR))
				nave->Movery(2);
			}
			nave->Pintar();
			enemigo->Pintar();
			
			//estado = ESTADO_JUGANDO;
			break;
		case Estado::ESTADO_JUGANDO://JUGANDO
			
			estado = ESTADO_TERMINANDO;
			break;
		case Estado::ESTADO_TERMINANDO: //TERMINANDO
			
			 
			break;
			
		case Estado::ESTADO_FINALIZANDO://FINALIZANDO
			printf("finalizando");
			salirJuego = true;
			
			Finalize();

			break;
		};
		while (SDL_PollEvent(&event))//SDL creara una lista de eventos ocurridos
		{
			if (event.type==SDL_QUIT){salirJuego = true;} //Si se detecta una salida de SDL
			if (event.type == SDL_KEYDOWN){}
		}
		SDL_Flip(screen);
		//while (tiempoFrameFinal < (tiempoFrameInicial + FPS_DELAY))
		//{
		//	tiempoFrameFinal = SDL_GetTicks();
		//	SDL_Delay(1);
		//}

		//printf("Frames:%d Tiempo:%d Tiempo Promedio:%f Tiempo por Frame:%d FPS:%f \n",tick, SDL_GetTicks(),(float)SDL_GetTicks() / (float)tick, tiempoFrameFinal - tiempoFrameInicial, 1000.0f / (float)(tiempoFrameFinal - tiempoFrameInicial;);
		//tiempoFrameInicial = tiempoFrameFinal;//Marcamos inicio de nuevo
		//tick++;
		
    }
	
		return true;

		
}

bool CGame::EsLimitePantalla(Nave*objeto, int bandera)
{
	if (bandera & BORDE_IZQUIERDO)
		if (objeto->ObtenerX() <= 0)
		return true;
	if (bandera & BORDE_SUPERIOR)
		if (objeto->ObtenerY() <= 0)
			return true;
	if (bandera & BORDE_DERECHO)
		if (objeto->ObtenerX() >= WIDTH_SCREEN-objeto->ObtenerW())
		return true;
	if (bandera & BORDE_INFERIOR)
		if (objeto->ObtenerY() >= HEIGHT_SCREEN-objeto->ObtenerH())
		return true;
	return false;
	



}

void CGame::MoverEnemigo(){
	if (enemigo->ObtenerPasoActual()== 0)
	if (!EsLimitePantalla(enemigo, BORDE_DERECHO))
		enemigo->Mover(1);//derecha
	else
		enemigo->IncrementarPasoActual();

	if (enemigo->ObtenerPasoActual()==1)
		if (!EsLimitePantalla(enemigo, BORDE_INFERIOR))
		enemigo->Movery(1);//abajo
		else
			enemigo->IncrementarPasoActual();

	if (enemigo->ObtenerPasoActual() == 2)
		if (!EsLimitePantalla(enemigo, BORDE_IZQUIERDO))
		enemigo->Mover(-1);//izquierda
		else
			enemigo->IncrementarPasoActual();

	if (enemigo->ObtenerPasoActual() == 3)
	if (!EsLimitePantalla(enemigo, BORDE_SUPERIOR))
		enemigo->Movery(-1);//Aa
	else
		enemigo->IncrementarPasoActual();

		
	
	
}
