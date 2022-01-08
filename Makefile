NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
parsing/open_files.c \
parsing/parse_commands.c \
parsing/parse_exec_paths.c \
parsing/redirect_streams.c \
executing/process_commands.c \
free_memory/free_cmd.c \
free_memory/free_path.c \

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

clean:
	make clean -C libft/
	rm -f *.o
	rm -f */*.o

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all