##
## EPITECH PROJECT, 2019
## arcade
## File description:
## Makefile
##

export CPPFLAGS	+=	-Werror
export CPPFLAGS	+=	-W\
					-Wall\
					-Wextra\
					-Wshadow\
					-Wold-style-cast\
					-Wcast-align\
					-Wunused\
					-Woverloaded-virtual\
					-Wpedantic\
					-Wsign-conversion\
					-Wlogical-op\
					-Wuseless-cast\
					-Wno-non-virtual-dtor\
					-std=c++17

export CPPFLAGS +=	-I$(shell pwd)/interfaces -I$(shell pwd)/include
#export CPPFLAGS	+=	-g3

SUBSYSTEM	=	core\
				games\
				graphicals

CMDS		=	obj\
				clean

DIRS		=	./lib/\
				./games/\
				./ressources/

all: $(SUBSYSTEM)

debug: export CPPFLAGS += -g3 #-D_GLIBCXX_DEBUG
debug: re

$(DIRS):
	$(foreach DIR, $(DIRS), mkdir -p $(DIR);)

$(SUBSYSTEM): $(DIRS)
	$(MAKE) -C $@_build

$(CMDS):
	$(foreach DIR, $(SUBSYSTEM), $(MAKE) -C $(DIR)_build $@;)

fclean: clean
	$(foreach DIR, $(SUBSYSTEM), $(MAKE) -C $(DIR)_build $@;)
	rm -rf $(DIRS)

re: fclean all

.PHONY: all $(SUBSYSTEM) $(CMDS) fclean re
