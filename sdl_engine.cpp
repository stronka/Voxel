
#include <iostream>

#include "sdl_engine.h"


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
    Uint32 contextFlags;
    contextFlags = SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL;
    
    // Create a 640 by 480 window.
    int result = InitializeSDL(640, 480, contextFlags);
    if (result != 0)
    {
       std::cout<<"sdl_main.cpp Cannot initalize SDL"<<std::endl;
       return result;
    }

    CreateOrthographicProjection(1.0, 1.0);
    InstallTimer();

    return 0;
}

int Sdl_Main::InitializeSDL(Uint32 width, Uint32 height, Uint32 flags)
{
    int error;

    w = width;
    h = height;
    
    error = SDL_Init(SDL_INIT_EVERYTHING);
    // Turn on double buffering.
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
    // Create the window
    mainWindow    = SDL_CreateWindow("SDL2 OpenGL Example", 
                                  SDL_WINDOWPOS_UNDEFINED, 
                                  SDL_WINDOWPOS_UNDEFINED, 
                                  w, h, flags);
    mainGLContext = SDL_GL_CreateContext(mainWindow);

    renderer = SDL_CreateRenderer(mainWindow, -1, 0);

    //Initialize SDL_mixer 
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) 
    { 
       std::cout << "Cannot open audio"<<std::endl;
       //return false; 
    }

    game_scene.init(renderer, w, h);

    return 0;
}

void Sdl_Main::CreateOrthographicProjection(GLfloat width, GLfloat height)
{
    // I use a near plane value of -1, and a far plane value of 1, which is what works best for 2D games.
    glOrtho(0.0, width*2, 0.0, height*2, -1.0, 1.0);
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

    SDL_GL_DeleteContext(mainGLContext);
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
    RenderFrame();    
}

void Sdl_Main::RenderFrame(void) 
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);

    game_scene.draw();

    SDL_GL_SwapWindow(mainWindow);
}
void Sdl_Main::ErrorMessage(std::string text)
{
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