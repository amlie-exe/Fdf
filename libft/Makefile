NAME = libft.a

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I.

AR = ar rcs
RM = rm -rf

#---------- PATH MANAGEMENT ----------

OBJ_DIR = objs/
VPATH = .:ft_printf:get_next_line

#---------- SOURCES FILES (.c) ----------

SRCS_LIBFT = ft_isalpha.c \
	 		ft_isdigit.c \
	 		ft_isalnum.c \
	 		ft_isascii.c \
	 		ft_isprint.c \
	 		ft_strlen.c \
	 		ft_memset.c \
	 		ft_bzero.c \
	 		ft_memcpy.c \
	 		ft_memmove.c \
	 		ft_strlcpy.c \
	 		ft_strlcat.c \
	 		ft_toupper.c \
	 		ft_tolower.c \
	 		ft_strchr.c \
	 		ft_strrchr.c \
	 		ft_strncmp.c \
	 		ft_memchr.c \
	 		ft_atoi.c \
	 		ft_memcmp.c \
	 		ft_strnstr.c \
	 		ft_calloc.c \
	 		ft_strdup.c \
	 		ft_putchar_fd.c \
	 		ft_putstr_fd.c \
			 ft_putendl_fd.c \
	 		ft_putnbr_fd.c \
	 		ft_itoa.c \
	 		ft_strjoin.c \
	 		ft_substr.c \
	 		ft_strtrim.c \
	 		ft_split.c \
	 		ft_strmapi.c \
	 		ft_striteri.c \
			free_tab.c \

SRCS_PRINTF = ft_printf/ft_printf.c \
              ft_printf/ft_print_c.c \
              ft_printf/ft_print_s.c \
              ft_printf/ft_print_d.c \
              ft_printf/ft_print_u.c \
              ft_printf/ft_print_p.c \
              ft_printf/ft_print_hexlower.c \
              ft_printf/ft_print_hexupper.c

SRCS_GNL = get_next_line/get_next_line.c \
           get_next_line/get_next_line_utils.c \

SRCS_BONUS_LIBFT = ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c \

SRCS_BONUS_GNL = get_next_line/get_next_line_bonus.c \
                 get_next_line/get_next_line_utils_bonus.c \

#---------- CONVERSION : FROM (.c) TO (.o) ----------

ALL_SRCS_NAMES = $(notdir $(SRCS_LIBFT) $(SRCS_PRINTF) $(SRCS_GNL))
ALL_SRCS_BONUS_NAMES = $(notdir $(SRCS_BONUS_LIBFT) $(SRCS_BONUS_GNL))

OBJS = $(addprefix $(OBJ_DIR)/, $(ALL_SRCS_NAMES:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(ALL_SRCS_BONUS_NAMES:.c=.o))

#---------- COMPILATION RULES ----------

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJ_DIR) $(OBJS) $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re