##
## EPITECH PROJECT, 2019
## Arcade
## File description:
## SDL2 Graphical handler library
##

LIB	=	lib_arcade_sdl2.so

SRC	=	./src/SDL2Graphic.cpp\
		./src/SDL2Sprite.cpp\
		./src/SDL2Sprite.LoadableTexture.cpp\
		./src/SDL2State.cpp\
		./src/SDL2Character.cpp\
		./src/SDL2CharState.cpp

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	+=	-I./include -fPIC
LDFLAGS		+=	-lSDL2 -lSDL2_image -lSDL2_ttf

all:	$(LIB)

obj:	$(OBJ)

$(LIB): obj
	$(CXX) -shared -o $(LIB) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)

re:	fclean all

.PHONY:	all obj clean fclean re