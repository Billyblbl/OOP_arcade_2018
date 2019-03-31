##
## EPITECH PROJECT, 2019
## Arcade
## File description:
## graphical libs makefile
##

export CPPFLAGS +=	-I$(CURDIR)/include

LIBS	= sfml ncurses sdl2

LINKS	=	$(addprefix ../lib/lib_arcade_, $(addsuffix .so, $(LIBS))) \
			$(addprefix $(CURDIR)/ressources/, $(LIBS)) \
			../ressources/libs

CMDS		=	obj\
				clean

DIRS		=	ressources

all: links

dirs: $(DIRS)

libs: $(LIBS)

$(DIRS):
	$(foreach DIR, $(DIRS), mkdir -p $(DIR))

links: $(LIBS) $(DIRS)
	@echo "Linking graphical libraries"
	$(foreach LIB, $(LIBS), ln -sf $(CURDIR)/$(LIB)/lib_arcade_$(LIB).so ../lib/lib_arcade_$(LIB).so;)
	@echo "Linking each graphical librairies ressources in central graphical lib ressources folder"
	$(foreach LIB, $(LIBS), ln -sf $(CURDIR)/$(LIB)/ressources $(CURDIR)/ressources/$(LIB);)
	@echo "Linking graphical lib ressources folder to root ressources folder"
	ln -sf $(CURDIR)/ressources ../ressources/libs

$(LIBS):
	$(MAKE) -C $@

$(CMDS):
	$(foreach DIR, $(LIBS), $(MAKE) -C $(DIR) $@;)

fclean:
	rm -rf $(DIRS)
	rm -f $(LINKS)
	$(foreach DIR, $(LIBS), $(MAKE) -C $(DIR) $@;)

re:	fclean all

.PHONY: all dirs links libs $(LIBS) $(CMDS) fclean re
