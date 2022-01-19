class MainSDLWindow 
{
private:
  SDL_Window * window;
  SDL_Renderer * renderer;

public:
  MainSDLWindow () //called on when class called in main
  {
    window = NULL;
    renderer = NULL;
  }

  ~MainSDLWindow () //called at the end of main
  {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
  }

  int init (const char* name, int height, int width)
  {
    window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_MINIMIZED);

    renderer = SDL_CreateRenderer(window, -1,  SDL_RENDERER_ACCELERATED);

    if ( !renderer || !window )
    {
      cout << "An error has occured, error code : " << SDL_GetError() << endl;
      return EXIT_FAILURE;
    } else { return EXIT_SUCCESS; }

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
  }
};