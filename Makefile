SRCS = main.c parser.c control.c

all :
	cc $(SRCS) -L. -lft -lftprintf -lgnl -Lminilibx-linux -lmlx -lX11 -lXext -lm