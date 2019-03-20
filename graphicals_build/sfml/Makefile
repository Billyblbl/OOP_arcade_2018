##
## EPITECH PROJECT, 2019
## Arcade
## File description:
## SFML Graphical handler library
##

LIB	=	lib_arcade_sfml.so

SRC	=	./src/SFMLGraphic.cpp\
		./src/SFMLDisplayable.cpp\
		./src/Entity.cpp

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	+=	-I./include -fPIC

all:	$(LIB)

obj:	$(OBJ)

$(LIB): obj
	$(CXX) -shared -o $(LIB) $(LDFLAGS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)

re:	fclean all

.PHONY:	all obj clean fclean re