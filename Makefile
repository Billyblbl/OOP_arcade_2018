##
## EPITECH PROJECT, 2019
## arcade
## File description:
## Makefile
##

export CPPFLAGS	+=	-Werror
export CPPFLAGS	+=	-W -Wall -Wextra -std=c++17
export CPPFLAGS +=	-I$(shell pwd)/interfaces
#export CPPFLAGS	+=	-g3

SUBSYSTEM	=	core\
				games\
				graphicals

CMDS		=	obj\
				clean\
				fclean\
				re

all: $(SUBSYSTEM)

debug: export CPPFLAGS += -g3
debug: re

$(SUBSYSTEM):
	$(MAKE) -C $@_build

$(CMDS):
	$(foreach DIR, $(SUBSYSTEM), $(MAKE) -C $(DIR)_build $@;)

.PHONY: all $(SUBSYSTEM) $(CMDS)
