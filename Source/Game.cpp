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
				nave = new Nave(screen, "../Data/minave.bmp");
				
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

				/*nave= IMG_LoadJPG_RW(SDL_RWFromFile("../Data/cuadro.jpg","rb"));
				SDL_Rect fuente;
				    fuente.x=582;
					fuente.y=383;
					fuente.w=321;
					fuente.h=16;
				SDL_Rect destino;
				    destino.x=100;
					destino.y=100;
					destino.w=fuente.w;
					destino.h=fuente.h;
				SDL_BlitSurface(nave, &fuente, screen, &destino);*/

			};
			estado = ESTADO_MENU;
			break;
	
		case Estado::ESTADO_MENU: //MENU
			//nave->PintarModulo(0, 0, 0, 64, 64);
			//nave->PintarModulo(0, 100, 100);
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

			keys = SDL_GetKeyState(NULL);
			if (keys[SDLK_RIGHT])
			{
				nave->Mover(1);
			}
			

			if (keys[SDLK_LEFT])
			{
				nave->Mover(-1);
			}
			if (keys[SDLK_UP])
			{
				nave->Movery(-1);
			}
			if (keys[SDLK_DOWN])
			{
				nave->Movery(1);
			}
			nave->Pintar();
			break;
		case Estado::ESTADO_JUGANDO://JUGANDO
			break;
		case Estado::ESTADO_TERMINANDO: //TERMINANDO
			break;
			
		case Estado::ESTADO_FINALIZANDO://FINALIZANDO
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
    }
	
		return true;
}
