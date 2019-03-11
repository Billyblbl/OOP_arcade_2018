##
## EPITECH PROJECT, 2019
## Arcade
## File description:
## core makefile
##

BIN =	arcade

LINK =	../$(BIN)

SRC	=	src/Core.cpp\
		src/main.cpp

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	+=	-I./include

LDFLAGS		+=	-ldl

all:	link

link:	$(LINK)

obj:	$(OBJ)

$(BIN):	obj
	$(CXX) -o $(BIN) $(OBJ) $(LDFLAGS)

$(LINK): $(BIN)
	ln -s $(CURDIR)/$(BIN) $(LINK)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BIN) $(LINK)

re: fclean all

.PHONY: all link obj clean fclean re
