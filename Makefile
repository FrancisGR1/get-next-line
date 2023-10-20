NAME = get_next_line


BUFFER_SIZE ?= 42
CC = cc
CFLAGS = -Werror -Wextra -Wall -D BUFFER_SIZE=$(BUFFER_SIZE)
SRC = get_next_line.c
SOURCES = get_next_line.c ft_strlcpy.c ft_strclen.c get_next_line_utils.c
OBJS = $(patsubst %.c, %.o, $(SOURCES))
EXEC = && ./a.out

all: $(SOURCES)

get: $(SOURCES) 
	$(CC) $(CFLAGS) $(SRC) $(EXEC)

fclean: 
	rm -rf  $(OBJS)





























