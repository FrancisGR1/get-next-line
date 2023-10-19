NAME = get_next_line

CC = cc
CFLAGS = -Werror -Wextra -Wall
SRC = get_next_line.c
SOURCES = get_next_line.c get_next_line_utils.c
OBJS = $(patsubst %.c, %.o, $(SOURCES))
EXEC = && ./a.out

all: $(SOURCES)

get: 
	$(CC) $(CFLAGS) $(SRC) $(EXEC)

fclean: 
	rm -rf  $(OBJS)





























