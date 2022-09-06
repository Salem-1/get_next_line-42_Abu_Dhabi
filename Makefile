NAME	=	get_next_line.a
SRC	=	get_next_line.c get_next_line_utils.c
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=5 -g3
CC = gcc 
OBJ	=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	ar -rcs $(NAME) $(OBJ) 

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean allq

test:
	@gcc  mytest_gnl/test_gnl.c get_next_line.a -g3
	@cp mytest_gnl/readme.txt .
	@./a.out
	
mem: test
		valgrind ./a.out
tclean:
	@rm readme.txt a.out

e:	re test tclean
