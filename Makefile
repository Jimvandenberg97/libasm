# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jivan-de <jivan-de@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/07 20:31:59 by jivan-de      #+#    #+#                  #
#    Updated: 2020/06/23 15:16:54 by jivan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COM_COLOR   = \033[1;31m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m
OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

NAME = libasm.a
NAME_LIB = asm
NAME_TEST = tester
NA = nasm
NA_FLAGS = -f
CC_FLAGS = -Wall -Werror -Wextra

ifeq ($(OS),Windows_NT)
	NA_FLAGS += win64
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		NA_FLAGS += elf64
	endif
	ifeq ($(UNAME_S),Darwin)
		NA_FLAGS += macho64
	endif
endif

SOURCES = ft_write.s \
			ft_read.s \
			ft_strlen.s \
			ft_strcmp.s \
			ft_strcpy.s \
			ft_strdup.s

TEST_SOURCES = main.c

OBJECTS = $(SOURCES:.s=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@printf "%b" "$(COM_COLOR)Building library: $(NO_COLOR)"
	@ar rc  $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@printf "%b" "$(OK_COLOR)$(OK_STRING)\n$(NO_COLOR)"

%.o: %.s
	@$(NA) -s $(NA_FLAGS) $< -o $@; \
		RESULT=$$?; \
		if [ $$RESULT -ne 0 ]; then \
		printf "%b %b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" \
		"$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
		else  \
		printf "%b %b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" \
		"$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
		fi; \
		exit $$RESULT

clean:
	@printf "%b" "$(COM_COLOR)Cleaning up object files: $(NO_COLOR)"
	@$(RM) $(OBJECTS)
	@printf "%b" "$(OK_COLOR)$(OK_STRING)\n$(NO_COLOR)"

fclean: clean
	@printf "%b" "$(COM_COLOR)Cleaning up $(NAME): $(NO_COLOR)"
	@$(RM) $(NAME)
	@printf "%b" "$(OK_COLOR)$(OK_STRING)\n$(NO_COLOR)"

tester: all
	@printf "$(WARN_COLOR)!!! TESTER !!! $(NO_COLOR)\n"
	@$(CC) $(CC_FLAGS) -L. -l $(NAME_LIB) $(TEST_SOURCES) -o $(NAME_TEST)

re: fclean all

.PHONY: all clean fclean re tester
