#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>

CGame::CGame()
{
	estado = Estado::ESTADO_INICIANDO;// Estado inicial del juego (corregido)
	atexit(SDL_Quit); 
}

// Con esta función eliminaremos todos los elementos en pantalla
void CGame::Finalize(){
	SDL_Quit();
}

void CGame::Iniciando()
{
	
				if (SDL_Init(SDL_INIT_VIDEO)<0)
				
				{
					printf("Eror %s ", SDL_GetError());
					exit(EXIT_FAILURE);
				}

				screen= SDL_SetVideoMode(640,480,24,SDL_SWSURFACE);
				
				if (screen==NULL)
				{
					printf("Error %s ", SDL_GetError());
					exit(EXIT_FAILURE);
				}

				SDL_WM_SetCaption( "Mi primer Juego", NULL);
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

				nave= IMG_LoadJPG_RW(SDL_RWFromFile("../Data/cuadro.jpg","rb"));
				SDL_Rect fuente;
				    fuente.x=582;
					fuente.y=383;
					fuente.w=321;
					fuente.h=16;
				SDL_Rect destino;
				    destino.x=200;
					destino.y=200;
					destino.w=200;
					destino.h=200;
				SDL_BlitSurface(nave, &fuente, screen, &destino);

			};
	
		case Estado::ESTADO_MENU: //MENU
			break;
		case Estado::ESTADO_JUGANDO://JUGANDO
			break;
		case Estado::ESTADO_TERMINANDO: //TERMINANDO
		    break;
		case Estado::ESTADO_FINALIZANDO://FINALIZANDO
			salirJuego = true;
		};
		
		SDL_Flip(screen);
    }
	
		return true;
}
