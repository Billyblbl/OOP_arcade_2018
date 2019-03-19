##
## EPITECH PROJECT, 2019
## Arcade
## File description:
## games makefile
##

export CPPFLAGS +=	-I$(CURDIR)/include

GAMES	=

LINK	=	$(addprefix ../games/lib_arcade_, $(addsuffix .so, $(GAMES)))\
			$(addprefix $(CURDIR)/ressources, $(GAMES))\
			../ressources/games

CMDS		=	obj\
				clean

DIRS		=	ressources

all: links

dirs: $(DIRS)

links: $(LINKS)

games: $(GAMES)

$(DIRS):
	$(foreach DIR, $(DIRS), mkdir -p $(DIR))

$(LINKS): $(GAMES) $(DIRS)
	$(foreach LIB, $(GAMES), ln -sf $(CURDIR)/$(LIB)/lib_arcade_$(LIB).so ../games/lib_arcade_$(LIB).so;)
	$(foreach LIB, $(GAMES), ln -sf $(CURDIR)/$(LIB)/ressources $(CURDIR)/ressources/$(LIB);)
	ln -sf $(CURDIR)/ressources ../ressources/games

$(GAMES):
	$(MAKE) -C $@

$(CMDS):
	$(foreach DIR, $(GAMES), $(MAKE) -C $(DIR) $@;)

fclean:
	rm -f $(LINKS)
	$(foreach DIR, $(GAMES), $(MAKE) -C $(DIR) $@;)

re:	fclean all

.PHONY: all dirs links games $(GAMES) $(CMDS) fclean re
