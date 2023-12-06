SRC		=	$(wildcard ./src/*.cpp)			\

OBJ		= 	$(SRC:.cpp=.o)

CFLAGS	+=	-Iinclude --std=c++20 -ansi -pedantic -Wall -Wextra -Werror

NAME	=	analog

all:	$(NAME)

.cpp.o:
	g++ $(CFLAGS) -c $< -o $@

$(NAME):    $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\033[0;34m<deleted all .o>\033[00m"
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)
	rm -rf *.txt

fclean: clean
	rm -f $(NAME)

re: fclean all

