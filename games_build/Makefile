##
## EPITECH PROJECT, 2019
## Arcade
## File description:
## games makefile
##

export CPPFLAGS +=	-I$(CURDIR)/include

GAMES	=

LINKS	=	$(addprefix ../games/lib_arcade_, $(addsuffix .so, $(GAMES)))\
			$(addprefix $(CURDIR)/ressources/, $(GAMES))\
			../ressources/games

CMDS		=	obj\
				clean

DIRS		=	ressources

all: links

dirs: $(DIRS)

games: $(GAMES)

$(DIRS):
	$(foreach DIR, $(DIRS), mkdir -p $(DIR))

links: $(GAMES) $(DIRS)
	@echo "Linking games libraries"
	$(foreach LIB, $(GAMES), ln -sf $(CURDIR)/$(LIB)/lib_arcade_$(LIB).so ../games/lib_arcade_$(LIB).so;)
	@echo "Linking each game librairies ressources in central games lib ressources folder"
	$(foreach LIB, $(GAMES), ln -sf $(CURDIR)/$(LIB)/ressources $(CURDIR)/ressources/$(LIB);)
	@echo "Linking game lib ressources folder to root ressources folder"
	ln -sf $(CURDIR)/ressources ../ressources/games

$(GAMES):
	$(MAKE) -C $@

$(CMDS):
	$(foreach DIR, $(GAMES), $(MAKE) -C $(DIR) $@;)

fclean:
	rm -rf $(DIRS)
	rm -f $(LINKS)
	$(foreach DIR, $(GAMES), $(MAKE) -C $(DIR) $@;)

re:	fclean all

.PHONY: all dirs links games $(GAMES) $(CMDS) fclean re
