#
# names
#
NAME := push_swap

RM := rm -rf

CC := gcc

CFLAGS := -Wall -Werror -Wextra

#
# rules not to mixed with similar file names
#
.PHONY: all bonus clean fclean re

#
# directories
#
INCLUDE := include/

SRC_DIR := src/

#
# necessary files
#
CFILES := stack_utils.c main.c
HFILES := $(INCLUDE)push_swap.h

SRC := $(addprefix $(SRC_DIR), $(CFILES))

OBJ := $(SRC:.c=.o)

#
# rules
#
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE) -o $@

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)

re: fclean all
