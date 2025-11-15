NAME = so_long

CC = cc
FLAG = -Wall -Werror -Wextra -g

# Directories
LIB_DIR = Libraries
INCLUDES_DIR = includes
INCLUDES_LIB_DIR = Libraries/Includes
INCLUDES_MLX42_DIR = Libraries/MLX42/include/MLX42

# Library
LIB = $(LIB_DIR)/lib.a

# Sources
SRC = $(wildcard source/*.c)

# Includes
INCLUDES = -I$(INCLUDES_DIR) -I$(INCLUDES_MLX42_DIR) -I$(INCLUDES_LIB_DIR)

# Objects
OBJ = $(SRC:.c=.o)

# MLX42 Flags
MLX_FLAGS = -ldl -lglfw -pthread -lm
# Rules
all: $(LIB) $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(FLAG) $(OBJ) $(LIB) $(INCLUDES) $(MLX_FLAGS) -o $(NAME)

$(LIB):
	@$(MAKE) -C $(LIB_DIR)

%.o: %.c
	$(CC) $(FLAG) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re