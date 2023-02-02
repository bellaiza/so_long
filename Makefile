NAME =		so_long
CC   =		gcc
FLAGS =		-Wall -Wextra -Werror
RM = 		/bin/rm -f
LIB_FLAGS =  -lft -lmlx -lXext -lX11
LIBFT_PATH = libft
MLX_PATH = 	mlx
LIBFT =		$(LIBFT_PATH)/libft.a
MLX = 		$(MLX_PATH)/libmlx.a
MLX_LIBFT = -L $(LIBFT_PATH) -L $(MLX_PATH) $(LIB_FLAGS) $(MLX)

INCLUDE =	includes/get_next_line.h \
			includes/so_long.h

SRCS =	srcs/so_long.c \
		srcs/map_read.c \
		srcs/map_error_deal.c\
		srcs/map_print.c\
		srcs/player_move.c \
		srcs/key_input_deal.c \
		srcs/free_all.c \
		srcs/exit_key_deal.c \
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME) $(INCLUDE)

$(NAME): 	$(OBJS) $(LIBFT) $(MLX)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJS) -g $(MLX_LIBFT)
		

$(LIBFT):
		make -C $(LIBFT_PATH)

$(MLX):
		make -C $(MLX_PATH)

clean:
			@$(RM) $(OBJS)
			make clean -C $(LIBFT_PATH)
			make clean -C $(MLX_PATH)

fclean:		clean
			@$(RM) $(NAME) $(OBJS)
			make fclean -C $(LIBFT_PATH)

norminette: 
			norminette libft gnl srcs 

re: fclean all

.PHONY:		all clean fclean re