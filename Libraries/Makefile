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
SRC_FTPRINTF = $(wildcard $(FTPRINTF_DIR)/*.c)
SRC_LIBFT = $(wildcard $(LIBFT_DIR)/*.c)
SRC_GNL = $(wildcard $(GNL_DIR)/*.c)
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