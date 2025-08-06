NAME = fdf

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

HEADER = -I./includes/ -I./libft/ -I./minilibx-linux/

#----------------------- LIBFT -----------------------

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

#--------------------- MINILIBX ----------------------

MINILIBX_DIR = minilibx-linux/
MINILIBX = $(MINILIBX_DIR)libmlx.a

#---------------- SOURCES FILES (.c) -----------------

SRCS_DIR = srcs/
SRCS = main.c \
	parsing.c \
	drawing.c \
	bounds.c \
	utils.c \

#---------- CONVERSION : FROM (.c) TO (.o) -----------

OBJ_DIR = objs/
OBJS = $(SRCS:.c=.o)
FULL_OBJS = $(addprefix $(OBJ_DIR), $(OBJS))

#---------------- COMPILATION RULES ------------------

all: $(NAME)

$(NAME): $(FULL_OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(FULL_OBJS) $(LIBFT) $(MINILIBX) -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(FULL_OBJS): | $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@


#------------------- CLEAN RULES --------------------

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIBX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(MINILIBX_DIR) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re