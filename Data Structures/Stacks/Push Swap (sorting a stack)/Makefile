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
.PHONY: all clean fclean re

#
# directories
#
INCLUDE := include/

SRC_DIR := src/

LIB_DIR := libft/

#
# necessary files
#
CFILES := main.c create_stack.c display.c stack_utils.c stack_utils_2.c utils.c sort.c
HFILES := $(INCLUDE)push_swap.h

SRC := $(addprefix $(SRC_DIR), $(CFILES))

OBJ := $(SRC:.c=.o)

LIB := libft/libft.a

FT := ft

#
# rules
#
all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIB_DIR) -l$(FT)

$(LIB):
	make -C $(LIB_DIR) bonus
	make -C $(LIB_DIR) clean

%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all
