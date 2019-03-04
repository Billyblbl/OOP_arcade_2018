##
## EPITECH PROJECT, 2019
## Arcade
## File description:
## core makefile
##

BIN =	arcade

LINK =	../$(BIN)

SRC	=	src/main.cpp

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	+=	-I./include

all:	link

link:	$(LINK)

obj:	$(OBJ)

$(BIN):	obj
	$(CXX) -o $(BIN) $(LDFLAGS) $(OBJ)

$(LINK): $(BIN)
	ln -s $(CURDIR)/$(BIN) $(LINK)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BIN) $(LINK)

re: fclean all

.PHONY: all link obj clean fclean re
