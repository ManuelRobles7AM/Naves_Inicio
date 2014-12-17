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
	delete *enemigoArreglo;

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
				nave = new Nave(screen, "../Data/minave.bmp", (WIDTH_SCREEN / 2),(HEIGHT_SCREEN - 80),MODULO_MINAVE_NAVE);
				fondo = new Objeto(screen, "../Data/fondo_juego.bmp", 0, 0, MODULO_FONDO);
				for (int i = 0; i < 10; i++)
				{
					enemigoArreglo[i] = new Objeto(screen, "../Data/enemigo.bmp", i * 60, 0, MODULO_ENEMIGO_NAVE);
					enemigoArreglo[i]->SetAutoMovimiento(false);
					enemigoArreglo[i]->SetPasoLimite(4);
					
				}
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
			estado = ESTADO_MENU;
			break;
	
		case Estado::ESTADO_MENU: //MENU
			//nave->PintarModulo(0, 0, 0, 64, 64);
			//nave->PintarModulo(0, 100, 100);
			for (int i = 0; i < 10; i++)
			{
				enemigoArreglo[i]->Actualizar();

			}
			MoverEnemigo();
			
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

			keys = SDL_GetKeyState(NULL);
			if (keys[SDLK_RIGHT])
			{
				if (!EsLimitePantalla(nave->ObtenerNaveObjeto(),BORDE_DERECHO))
				nave->MoverDerecha();
			}
			

			if (keys[SDLK_LEFT])
			{
				if (!EsLimitePantalla(nave->ObtenerNaveObjeto(), BORDE_IZQUIERDO))
				nave->MoverIzquierda();
			}
			if (keys[SDLK_UP])
			{
				if (!EsLimitePantalla(nave->ObtenerNaveObjeto(), BORDE_SUPERIOR))
				nave->MoverArriba();
			}
			if (keys[SDLK_DOWN])
			{
				if (!EsLimitePantalla(nave->ObtenerNaveObjeto(), BORDE_INFERIOR))
				nave->MoverAbajo();
			}
			//D I S P A R A R     B A L A S //
			if (keys[SDLK_SPACE])
			{
				nave->Disparar();
				
			}
			//--------------------------------//
			fondo->Pintar();
			nave->Pintar();
			
			
			for (int i = 0; i<10; i++)
			{
				enemigoArreglo[i]->Pintar();
			}
			
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

bool CGame::EsLimitePantalla(Objeto*objeto, int bandera)
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
	for (int i = 0; i < 10; i++)
	{
		if (enemigoArreglo[i]->ObtenerPasoActual() == 0)
		if (!EsLimitePantalla(enemigoArreglo[i], BORDE_DERECHO))
			enemigoArreglo[i]->Mover(1);//derecha
		else
			enemigoArreglo[i]->IncrementarPasoActual();

		if (enemigoArreglo[i]->ObtenerPasoActual() == 1)
		if (!EsLimitePantalla(enemigoArreglo[i], BORDE_INFERIOR))
			enemigoArreglo[i]->Movery(1);//abajo
		else
			enemigoArreglo[i]->IncrementarPasoActual();

		if (enemigoArreglo[i]->ObtenerPasoActual() == 2)
		if (!EsLimitePantalla(enemigoArreglo[i], BORDE_IZQUIERDO))
			enemigoArreglo[i]->Mover(-1);//izquierda
		else
			enemigoArreglo[i]->IncrementarPasoActual();

		if (enemigoArreglo[i]->ObtenerPasoActual() == 3)
		if (!EsLimitePantalla(enemigoArreglo[i], BORDE_SUPERIOR))
			enemigoArreglo[i]->Movery(-1);//Aa
		else
			enemigoArreglo[i]->IncrementarPasoActual();

	}
	

		
	
	
}
