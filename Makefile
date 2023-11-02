<<<<<<< HEAD
NAME = get_next_line


BUFFER_SIZE ?= 42 
CC = cc
CFLAGS = -g -Werror -Wextra -Wall -D BUFFER_SIZE=$(BUFFER_SIZE)
SRC = get_next_line.c
SOURCES = get_next_line.c get_next_line_utils.c
#SOURCES = get_next_line_bonus.c get_next_line_utils_bonus.c
#OBJS = $(patsubst %.c, %.o, $(SOURCES))
EXEC = && ./a.out

all: $(SOURCES)
bonus: $(BSOURCES) 
get: $(SOURCES) 
	$(CC) $(CFLAGS) $(SOURCES) $(EXEC)
fclean: 
	rm -rf  $(OBJS)





























=======
CC = cc
NAME = get_next_line
SRCS = get_next_line.c get_next_line_utils.c
SIZE ?= 100 
CFLAGS = -g -Wall -Werror -Wextra -D BUFFER_SIZE=$(SIZE)

get: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o main 

all: 

clean:

fclean:
>>>>>>> gnl3/main
