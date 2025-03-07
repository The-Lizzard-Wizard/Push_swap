NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRC = main.c utils.c utils_2.c swap.c rotate.c reverse.c push.c error.c init.c sort.c
DEPS = push_swap.h
ODIR = obj/
OBJ = $(SRC:%.c=$(ODIR)%.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re libft_comp

all: libft_comp $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

libft_comp :
	$(MAKE) -C $(LIBFT_DIR)

$(ODIR)%.o: %.c Makefile push_swap.h | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR):
	mkdir $(ODIR)

clean:
	rm -rf $(ODIR)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C ./libft fclean

re:
	fclean
	all
