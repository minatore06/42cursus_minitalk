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

all: $(NAME)

$(NAME): $(OBJECTS_C) $(OBJECTS_S)
	$(MAKE) bonus -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS_S) $(LIBFT)$(LIBFTNAME) -o $(NAME_S)
	$(CC) $(CFLAGS) $(OBJECTS_C) $(LIBFT)$(LIBFTNAME) -o $(NAME_C)

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -f $(OBJECTS_S) $(OBJECTS_C)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -f $(NAME_C) $(NAME_S)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
