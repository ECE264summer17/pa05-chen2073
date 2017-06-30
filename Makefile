##
## Makefile 
##

CC	= gcc

CFLAGS	= -Wall -Wshadow -Werror -Wvla -Wunreachable-code -g

## Build rule

pa05: pa05.o answer05.o utility.o
	$(CC) $(CFLAGS) pa05.o answer05.o utility.o -o pa05

clean:	
	rm -f pa05.o answer05.o pa05

%.o:	%.c
	$(CC) $(CFLAGS) -c $<
