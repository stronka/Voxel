/**
*/

#include <iostream>
#include <string>
#include <sstream>

#include "sdl_engine.h"
#include "logger.h"

// Constructor
Sdl_Main::Sdl_Main(void)
{
   fullscreen = false;
   done = false;
}

// Destructor
Sdl_Main::~Sdl_Main(void)
{
    Cleanup();
}


// Initialization functions
int Sdl_Main::InitApp(void)
{
    int error;
    Uint32 contextFlags = SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL;

    w = 1280.0;
    h = 720.0;
    
    // Create a 640 by 480 window.
    error = SDL_Init(SDL_INIT_EVERYTHING);
    // Turn on double buffering.
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    
    // Create the window
    mainWindow    = SDL_CreateWindow("Voxel",
                                  SDL_WINDOWPOS_UNDEFINED, 
                                  SDL_WINDOWPOS_UNDEFINED, 
                                  w, h, contextFlags);
    if (mainWindow == NULL)
    {
       Logger::get()->log_error("Could not create window");
       return 1;
    }
    renderer = SDL_CreateRenderer(mainWindow, -1, 0);
    if (renderer == NULL)
    {
       Logger::get()->log_error("Could not create window");
       return 1;
    }
    Sdl_Media::get()->init();

    std::ostringstream ss;
    ss << "sdl_engine.cpp: Created window:"<<w<<"x"<<h;
    Logger::get()->log_info(ss.str() );

    Logger::get()->log_info("sdl_engine.cpp: Initializing scene");
    if (game_scene.init(this, w, h) != 0)
    {
        Logger::get()->log_error("sdl_engine.cpp: Error initializing scene");
        return 2;
    }
    Logger::get()->log_info("sdl_engine.cpp: Initialized scene");

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset

    glOrtho(0.0,w,0,h,-1.0,1.0);

    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_TEXTURE_2D);

    InstallTimer();
    Logger::get()->log_info("SDL initialization done");

    return 0;
}

void Sdl_Main::InstallTimer(void)
{
    timer = SDL_AddTimer(30, GameLoopTimer, this);
}

Uint32 Sdl_Main::GameLoopTimer(Uint32 interval, void* param)
{
    // Create a user event to call the game loop.
    SDL_Event event;
    
    event.type = SDL_USEREVENT;
    event.user.code = RUN_GAME_LOOP;
    event.user.data1 = 0;
    event.user.data2 = 0;
    
    SDL_PushEvent(&event);
    
    return interval;
}


// Cleanup functions
void Sdl_Main::Cleanup(void)
{
    SDL_bool success;
    success = SDL_RemoveTimer(timer);

    game_scene.cleanup();
    Sdl_Media::get()->cleanup();

    SDL_DestroyWindow(mainWindow);
    SDL_Quit();
}


// Event-related functions
void Sdl_Main::EventLoop(void)
{
    SDL_Event event;
    
    while((!done) && (SDL_WaitEvent(&event))) {
        switch(event.type) {
            case SDL_USEREVENT:
                HandleUserEvents(&event);
                break;
                
            case SDL_KEYDOWN:
                game_scene.key_down(event.key.keysym.sym);
                break;
            case SDL_KEYUP:
                game_scene.key_up(event.key.keysym.sym);
                break;
            
            case SDL_QUIT:
                done = true;
                break;
                
            default:
                break;
        }   // End switch
            
    }   // End while
        
}

void Sdl_Main::HandleUserEvents(SDL_Event* event)
{
    switch (event->user.code) {
        case RUN_GAME_LOOP:
            GameLoop();
            break;
            
        default:
            break;
    }
}


// Game related functions
void Sdl_Main::GameLoop(void)
{
   game_scene.update();
   RenderFrame();    
}

void Sdl_Main::RenderFrame(void) 
{
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

   glLoadIdentity();

   game_scene.draw();

   SDL_GL_SwapWindow(mainWindow);
}
SDL_Renderer * Sdl_Main::getRenderer()
{
   return renderer;
}
void Sdl_Main::toggle_fullscreen()
{
   fullscreen = !fullscreen;
   if (fullscreen)
   {
      SDL_SetWindowFullscreen(mainWindow, SDL_WINDOW_FULLSCREEN);
   }
   else
   {
      SDL_SetWindowFullscreen(mainWindow, 0);
   }
}
void Sdl_Main::close()
{
   done = true;
}
