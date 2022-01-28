using namespace std;

class MainSDLWindow {
  private:
    SDL_Window *window;
    SDL_Renderer *renderer;

  public:
    MainSDLWindow() {
      window = NULL;
      renderer = NULL;
    }

    ~MainSDLWindow(){
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      SDL_Quit();
    }

    int Init(const char* name, int width, int height){

      window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_MINIMIZED);

      renderer = SDL_CreateRenderer(window, -1, 0);

      if(!renderer || !window){//initialisation de la SDL
        cout << "Erreur d'initialisation de la SDL : "<< SDL_GetError() << endl;//on affiche l'erreur
        return EXIT_FAILURE;//on sort du programme pour éviter de plus gros problèmes
      } else {return EXIT_SUCCESS; }

      SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    }
};

/*

class Snake {
  private:
    Segment *next;
    Segment *head;

  public:

    int move(int dir){

    }

    void eat(){

    }

};

class GSnake {
  private:

  public:

    void Disp(){

    }
};
*/ 