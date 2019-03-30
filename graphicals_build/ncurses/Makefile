##
## EPITECH PROJECT, 2019
## Arcade
## File description:
## ncurses Graphical handler library
##

LIB	=	lib_arcade_ncurses.so

SRC	=	./src/ncursesDisplayable.cpp\
		./src/ncursesGraphic.cpp\
		./src/ncursesState.cpp
OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	+=	-I./include -fPIC
LDFLAGS		+=	-lncurses

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