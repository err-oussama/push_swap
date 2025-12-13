NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

# header include paths
INCLUDES = -I. -Ilib -Isort -Istack

LIB_DIR = lib
SRT_DIR = sort
STK_DIR = stack

LIB_SRC = a_to_l.c c_alloc.c split.c str_lcpy.c str_len.c sub_str.c
SRT_SRC = huge_stack.c tiny_stack.c to_top.c indexing.c 
STK_SRC = stack_I.c stack_II.c stack_op.c

# prepend directories
LIB = $(addprefix $(LIB_DIR)/,$(LIB_SRC))
SRT = $(addprefix $(SRT_DIR)/,$(SRT_SRC))
STK = $(addprefix $(STK_DIR)/,$(STK_SRC))

MAIN = push_swap.c

SRC = $(MAIN) $(LIB) $(SRT) $(STK)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
