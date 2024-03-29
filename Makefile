CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME_S=server
NAME_C=client

FILES_S=server.c
FILES_C=client.c
OBJECTS_S=$(FILES_S:.c=.o)
OBJECTS_C=$(FILES_C:.c=.o)

LIBFT=libft/
LIBFTNAME=libft.a

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJECTS_S)
	$(MAKE) bonus -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS_S) $(LIBFT)$(LIBFTNAME) -o $(NAME_S)

$(NAME_C): $(OBJECTS_C)
	$(MAKE) bonus -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS_C) $(LIBFT)$(LIBFTNAME) -o $(NAME_C)

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -f $(OBJECTS_S) $(OBJECTS_C)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -f $(NAME_C) $(NAME_S)

re:	fclean all

bonus: $(NAME_S) $(NAME_C)

.PHONY:	all clean fclean re bonus
