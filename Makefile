SRCS = main.c splitter.c

all :
	cc $(SRCS) -L. -lft -lftprintf -lgnl -Lminilibx-linux -lmlx -lX11 -lXext