/*
 *  Sdl_Main.h
 *  SDL Test
 *
 *  Created by Mark Szymczyk on 5/1/06.
 *  Copyright 2006 Me and Mark Publishing. All rights reserved.
 *
 */

#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include "SDL2/SDL_image.h"

class Sdl_Main
{
    protected:
        SDL_Window* mainWindow;
        SDL_GLContext mainGLContext;
        SDL_TimerID timer;
        bool done;

        SDL_Renderer * renderer;
        Game_Scene game_scene;
	Uint32 w;
	Uint32 h;
    
    public:
        // Constructor and destructor
        Sdl_Main (void);
        virtual ~Sdl_Main(void);

        // Initialization functions
        void InitApp(void);
        void InitializeSDL(Uint32 width, Uint32 height, Uint32 flags);
        void CreateOrthographicProjection(GLfloat width, GLfloat height);
        void InstallTimer(void);
        static Uint32 GameLoopTimer(Uint32 interval, void* param);
        
        // Cleanup functions
        void Cleanup(void);
        
        // Event-related functions
        void EventLoop(void);
        void HandleUserEvents(SDL_Event* event);
        
        // Game related functions
        void GameLoop(void);
        void RenderFrame(void);
        
};

typedef Sdl_Main* Sdl_MainPtr;
typedef Sdl_Main** Sdl_MainHandle;

const int RUN_GAME_LOOP = 1;
