NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I. -Ilib -Isort -Istack -Iget_next_line 

LIB_DIR = lib
SRT_DIR = sort
STK_DIR = stack
GNL_DIR = get_next_line

LIB_SRC = a_to_l.c c_alloc.c split.c str_lcpy.c str_len.c sub_str.c str_cmp.c
SRT_SRC = huge_stack.c tiny_stack.c  indexing.c 
STK_SRC = stack_I.c stack_II.c stack_op.c
BON_SRC = checker.c checker_op.c
GNL_SRC = get_next_line.c  get_next_line_utils.c 

LIB = $(addprefix $(LIB_DIR)/,$(LIB_SRC))
SRT = $(addprefix $(SRT_DIR)/,$(SRT_SRC))
STK = $(addprefix $(STK_DIR)/,$(STK_SRC))
GNL = $(addprefix $(GNL_DIR)/,$(GNL_SRC))
MAIN = push_swap.c

SRC = $(MAIN) $(LIB) $(SRT) $(STK) parser.c 
OBJ = $(SRC:.c=.o)

SRC_BON = $(BON_SRC) $(LIB) $(SRT) $(STK) $(GNL) parser.c
OBJ_BON = $(SRC_BON:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BON)

fclean: clean
	rm -f $(NAME) checker

re: fclean all

bonus: $(OBJ_BON)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_BON)  -o checker


.PHONY: all clean fclean re
