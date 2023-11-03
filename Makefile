CC = cc
NAME = get_next_line
SRCS = get_next_line.c get_next_line_utils.c
SIZE ?= 100 
CFLAGS = -g -Wall -Werror -Wextra -D BUFFER_SIZE=$(SIZE)

get: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o main 

all: 

clean:
	rm main
fclean:

bonus:
