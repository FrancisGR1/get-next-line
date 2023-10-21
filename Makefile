NAME = get_next_line


BUFFER_SIZE ?= 42
CC = cc
CFLAGS = -Werror -Wextra -Wall -D BUFFER_SIZE=$(BUFFER_SIZE)
SRC = get_next_line.c
SOURCES = ft_strlen.c ft_strclen.c  concatenate.c locate_newline.c get_next_line.c get_next_line_utils.c
OBJS = $(patsubst %.c, %.o, $(SOURCES))
EXEC = && ./a.out

all: $(SOURCES)
get: $(SOURCES) 
	$(CC) $(CFLAGS) $(SOURCES) $(EXEC)
fclean: 
	rm -rf  $(OBJS)





























