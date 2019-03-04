##
## EPITECH PROJECT, 2019
## Arcade
## File description:
## games makefile
##

export CPPFLAGS +=	-I$(CURDIR)/include

GAMES	=

CMDS		=	obj\
				clean\
				fclean\
				re

all: links

games:	$(GAMES)

links: $(GAMES)
	$(foreach GAME, $(GAMES), ln -s $(GAMES)/lib_arcade_$(GAME).so ../games/lib_arcade_$(GAME).so)

$(GAMES):
	$(MAKE) -C $@

$(CMDS):
	$(foreach DIR, $(GAMES), $(MAKE) -C $(DIR) $@;)

.PHONY: all games links $(GAMES) $(CMDS)