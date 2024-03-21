####### DECLARATIONS ######

NAME = sample

FLAGS = -std=c++98 -Wall -Werror -Wextra



########### RULES ##########

$(NAME): main.o Sample.o
	g++ ${FLAGS} main.o Sample.o -o ${NAME}

main.o: main.cpp
	g++ -c ${FLAGS} main.cpp

Sample.o: Sample.cpp
	g++ -c ${FLAGS} Sample.cpp

clean:
	rm -rf *.o

fclean: clean
	rm -rf ${NAME}

.PHONY: all clean fclean re
