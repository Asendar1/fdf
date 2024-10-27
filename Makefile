SRCS = main.c parser.c control.c utils.c draw.c draw_algo.c

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBS = -L. -lgnl -lft -lftprintf -Lminilibx-linux -lmlx -lX11 -lXext -lm
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all