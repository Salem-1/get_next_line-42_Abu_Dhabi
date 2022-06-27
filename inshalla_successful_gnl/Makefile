NAME	=	get_next_line.a
SRC	=	get_next_line.c get_next_line_utils.c
FILE = readme.txt
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=4 -g3 
CC = gcc 
OBJ	=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	ar -rcs $(NAME) $(OBJ) 

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

test:
	@gcc  mytest_gnl/test_gnl.c get_next_line.a -g3
	@cp mytest_gnl/$(FILE) .
	@./a.out
	
mem: test
		valgrind --leak-check=full ./a.out
tclean: 
	@rm $(FILE) a.out

e:	re test tclean 


m :re test mem tclean fclean
