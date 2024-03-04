NAME = fractol
HEADER= ./include/ 
SRC=colors.c fractol.c main.c render.c utils.c ft_atof.c key_press.c
OBJ=$(SRC:.c=.o)
BONUS_OBJ=$(BONUS:.c=.o)
MINI_DIR= minilibx-linux
MINI_LIB = libmlx.a	
# MINI_DIR = ./minilibx_mms_20191025_beta
# MINI_LIB = libmlx.dylib

ifeq ($(MAKECMDGOALS), bonus)
OBJ += $(BONUS_OBJ)
endif

# FLAGS=-Wall -Wextra -Werror
FLAGS = -Wall -Wextra -Werror -I/usr/X11R6/include

MLX_CFLAGS    =    -L/usr/X11R6/lib -lX11 -lXext -lm #REMOVE IF NOT ON M1

$(NAME) : $(OBJ)
		$(MAKE)  -C libft
		$(MAKE)  -C $(MINI_DIR)
		cp $(MINI_DIR)/$(MINI_LIB) ./
		$(CC) -I $(HEADER) $(MINI_DIR)/$(MINI_LIB) $(MLX_CFLAGS) ./libft/libft.a $(OBJ) -o $@

all : $(NAME) 

bonus: all 

%.o : %.c
	cc $(FLAGS) -I $(MINI_DIR) -I $(HEADER) -c $< -o $@ 
clean:
	rm -f $(OBJ) $(BONUS_OBJ) $(NAME_OBJ) -C libft/*.o

fclean: clean
	rm -f $(NAME) $(MINI_LIB) -C libft/*.a

norm	:
	norminette ${SRC} include libft

re: fclean all
