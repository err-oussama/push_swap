NAME = push_swap
NAME_B = checker


MAIN = push_swap.c
MAIN_B = checker.c

CC = cc
CFLAGS = -Wall -Wextra -Werror


LIB_SRC = lib_a_to_l.c lib_c_alloc.c lib_split.c lib_str_lcpy.c lib_str_len.c lib_sub_str.c lib_str_cmp.c
SRT_SRC = sort_huge_stack.c sort_tiny_stack.c  sort_indexing.c 
STK_SRC = stack_I.c stack_II.c stack_op.c

BON_SRC = checker_op.c
GNL_SRC = gnl.c  gnl_utils.c 


SRC = $(LIB_SRC) $(STK_SRC) $(SRT_SRC) parser.c
OBJ = $(SRC:.c=.o)

SRC_BON = $(BON_SRC) $(LIB_SRC) $(SRT_SRC) $(STK_SRC) $(GNL_SRC) parser.c
OBJ_BON = $(SRC_BON:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BON)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all

bonus: $(OBJ_BON)
	$(CC) $(CFLAGS) $(OBJ_BON) $(MAIN_B) -o checker


.PHONY: all clean fclean re
