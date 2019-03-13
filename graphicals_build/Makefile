##
## EPITECH PROJECT, 2019
## Arcade
## File description:
## graphical libs makefile
##

export CPPFLAGS +=	-I$(CURDIR)/include

LIBS	=

CMDS		=	obj\
				clean\
				fclean\
				re

all: links

links: $(LIBS)
	$(foreach LIB, $(LIBS), ln -sf $(LIBS)/lib_arcade_$(LIB).so ../lib/lib_arcade_$(LIB).so)

$(LIBS):
	$(MAKE) -C $@

$(CMDS):
	$(foreach DIR, $(LIBS), $(MAKE) -C $(DIR) $@;)

.PHONY: all links $(LIBS) $(CMDS)