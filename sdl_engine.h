/*
 * This is SDL window management file
 *
 * Author: Piotr Zielinski
 */

#ifndef __H_SDL_MAIN_H_
#define __H_SDL_MAIN_H_

#include <string>

#include "game.h"

class Sdl_Main
{
    protected:
        SDL_Window* mainWindow;
        SDL_GLContext mainGLContext;
        SDL_TimerID timer;

        bool done;
        bool fullscreen;

        SDL_Renderer * renderer;
        Game_Scene game_scene;
	Uint32 w;
	Uint32 h;
    
    public:
        // Constructor and destructor
        Sdl_Main (void);
        virtual ~Sdl_Main(void);

        // Initialization functions
        int InitApp(void);
        int InitializeSDL(Uint32 width, Uint32 height, Uint32 flags);
        void CreateOrthographicProjection(GLfloat width, GLfloat height);
        void InstallTimer(void);
        static Uint32 GameLoopTimer(Uint32 interval, void* param);
        void toggle_fullscreen();
        void close();

        SDL_Renderer * getRenderer();
        
        // Cleanup functions
        void Cleanup(void);
        
        // Event-related functions
        void EventLoop(void);
        void HandleUserEvents(SDL_Event* event);
        
        // Game related functions
        void GameLoop(void);
        void RenderFrame(void);
        
	void ErrorMessage(std::string text);
};

typedef Sdl_Main* Sdl_MainPtr;
typedef Sdl_Main** Sdl_MainHandle;

const int RUN_GAME_LOOP = 1;

#endif
