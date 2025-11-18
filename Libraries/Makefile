NAME = lib.a

CC = cc
FLAG = -Wall -Werror -Wextra -g

# Directory
FTPRINTF_DIR = ft_printf
LIBFT_DIR = libft
GNL_DIR = Get-next-line
MLX42_DIR = MLX42
INCLUDES_DIR = Includes
TEMP_DIR = .temp_mlx_obj

# Includes
INCLUDES = -I$(INCLUDES_DIR) -I$(MLX42_DIR)/include/MLX42

# MLX42 Library
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
MLX42_FLAGS = -ldl -lglfw -pthread -lm

# Sources
SRC_FTPRINTF = dprintf/ft_dprintf.c \
				dprintf/ft_dputchar.c \
				dprintf/ft_dputhexa_upper.c \
				dprintf/ft_dputnbr.c \
				dprintf/ft_dputnbr_hexa.c \
				dprintf/ft_dputptr.c \
				dprintf/ft_dputstr.c \
				dprintf/ft_dputunbr.c \
				dprintf/ft_dselect.c

SRC_LIBFT = libft/ft_atoi.c \
		libft/ft_bzero.c \
		libft/ft_calloc.c \
		libft/ft_isalnum.c \
		libft/ft_isalpha.c \
		libft/ft_isascii.c \
		libft/ft_isdigit.c \
		libft/ft_isprint.c \
		libft/ft_itoa.c \
		libft/ft_lstadd_back_bonus.c \
		libft/ft_lstadd_front_bonus.c \
		libft/ft_lstclear_bonus.c \
		libft/ft_lstdelone_bonus.c \
		libft/ft_lstiter_bonus.c \
		libft/ft_lstlast_bonus.c \
		libft/ft_lstmap_bonus.c \
		libft/ft_lstnew_bonus.c \
		libft/ft_lstsize_bonus.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_memset.c \
		libft/ft_putchar_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_split.c \
		libft/ft_strchr.c \
		libft/ft_strdup.c \
		libft/ft_striteri.c \
		libft/ft_strjoin.c \
		libft/ft_strlcat.c \
		libft/ft_strlcpy.c \
		libft/ft_strlen.c \
		libft/ft_strmapi.c \
		libft/ft_strncmp.c \
		libft/ft_strnstr.c \
		libft/ft_strrchr.c \
		libft/ft_strtrim.c \
		libft/ft_substr.c \
		libft/ft_tolower.c \
		libft/ft_toupper.c

SRC_GNL = Get-next-line/get_next_line.c


SRC = $(SRC_FTPRINTF) $(SRC_LIBFT) $(SRC_GNL)

# Objects
OBJ = $(SRC:.c=.o)

# Rules
all: $(NAME)

$(MLX42_LIB):
	@git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR)
	@cd $(MLX42_DIR) && mkdir -p build && cmake -B build && cmake --build build -j4

$(NAME): $(OBJ) $(MLX42_LIB)
	@mkdir -p $(TEMP_DIR)
	@cd $(TEMP_DIR) && ar x ../$(MLX42_LIB)
	@ar rcs $(NAME) $(OBJ) $(TEMP_DIR)/*.o
	@rm -rf $(TEMP_DIR)

%.o: %.c
	$(CC) $(FLAG) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(TEST_NAME)
	rm -rf $(MLX42_DIR)

re: fclean all

.PHONY: all clean fclean re
