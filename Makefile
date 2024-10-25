SRCS = main.c parser.c control.c

all :
	cc $(SRCS) -o fdf -L. -lft -lftprintf -lgnl -Lminilibx-linux -lmlx -lX11 -lXext -lm