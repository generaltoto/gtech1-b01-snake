CC=g++
# Adapt the variables below to your needs:
EXE=snake
CPP=main.cpp application.cpp mainSDLWindow.cpp segment.cpp snake.cpp fruit.cpp
HPP=application.hpp mainSDLWindow.hpp segment.hpp snake.hpp fruit.hpp

# The default is build the executable file:
default: $(EXE)

# The executable file must be rebuilt if source files changed:
$(EXE): $(CPP) $(HPP)
	$(CC) $(CPP) -lSDL2 -o $(EXE)

# Run of the (always up-to-date) executable:
run: $(EXE)
	./$(EXE)

uml/classes.png: *.hpp
	./uml/mk_uml.sh uml/classes.png *.hpp

nblines:
	@wc -l *.h *.[ch]pp
