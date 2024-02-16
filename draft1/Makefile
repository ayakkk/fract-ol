NAME = fractol
# NAME_OBJ=($))
HEADER= ./include/
# SERVER   = server
# CLIENT   = client
SRC=colors.c fractol.c main.c render.c 
OBJ=$(SRC:.c=.o)
BONUS_OBJ=$(BONUS:.c=.o)

ifeq ($(MAKECMDGOALS), bonus)
OBJ += $(BONUS_OBJ)
endif

FLAGS=-Wall -Wextra -Werror

all : $(NAME) 

# minilibx_mms_20191025_beta

# server: server.o $(OBJ)
# 	$(CC) $(FLAGS) -I $(HEADER) $^ -o $@

# client: client.o $(OBJ)
	# $(CC) $(FLAGS) -I $(HEADER) $^ -o $@

$(NAME) : $(OBJ)
		$(MAKE)  -C libft
		$(MAKE)  -C minilibx_mms_20191025_beta

bonus: all 

%.o : %.c
	cc $(FLAGS) -I $(HEADER) -c $< -o $@ 
clean:
	rm -f $(OBJ) $(BONUS_OBJ) $(NAME_OBJ)

fclean: clean
	rm -f $(NAME) 

re: fclean all