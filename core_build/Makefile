##
## EPITECH PROJECT, 2019
## Arcade
## File description:
## core makefile
##

BIN		=	arcade

LINK	=	../$(BIN)

RESS	=	../ressources/core

SRC	=	src/Core.cpp\
		src/Control.cpp\
		src/DirectoryMenu.cpp\
		src/MenuEntry.cpp\
		src/MainMenu.cpp\
		src/MainMenuCursor.cpp\
		src/MainMenuKeybinds.cpp\
		src/main.cpp

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	+=	-I./include

LDFLAGS		+=	-ldl -lstdc++fs

all:	link

link:	$(LINK)

obj:	$(OBJ)

$(BIN):	obj
	$(CXX) -o $(BIN) $(OBJ) $(LDFLAGS)

$(LINK): $(BIN) $(RESS)
	ln -sf $(CURDIR)/$(BIN) $(LINK)

$(RESS):
	ln -sf $(CURDIR)/ressources $(RESS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BIN) $(LINK)

re: fclean all

.PHONY: all link obj clean fclean re
