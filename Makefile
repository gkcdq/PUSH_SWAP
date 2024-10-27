SRCS        = main.c mvt/sa.c mvt/ra.c mvt/sb.c mvt/rb.c mvt/ss.c mvt/pa.c mvt/pb.c \
				mvt/rr.c mvt/rra.c mvt/rrb.c mvt/rrr.c algo1.c parsing.c utils.c free.c \
			algo2.c algo3.c utils2.c parsing2.c
OBJS        = $(SRCS:.c=.o)
NAME        = push_swap
CC          = cc
RM          = rm -f
CFLAGS      = -Wall -Wextra -Werror
LDFLAGS     = -Llibft -lft
INCLUDES    = -Ilibft 

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

