Creating a snake using C++ (with SDL2 library)
Made for Linux environment 

# SDL2 library and G++ compiler 
 
Install SDL2 and SDL_image : (graphical library)
```bash
sudo apt install libsdl2-dev libsdl2-image-dev
```

Install G++ compiler and Make : 
```bash
sudo apt install g++ make 
```
note : the program should be able to run with other compilers.

# Launch the game & controls

### Launching 

Use Make to compile your code 
```
make run
```
The use of make isn't mandatory, you can just compile it manually
```
g++ main.cpp application.cpp mainSDLWindow.cpp segment.cpp snake.cpp fruit.cpp -l SDL2 -o snake && ./snake
```

### Controls
```W``` -> UP   
```S``` -> DOWN   
```A``` -> LEFT   
```D``` -> RIGHT   