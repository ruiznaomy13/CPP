NAME		= phonebook

SRC			= main.cpp PhoneBook.cpp #Contact.cpp

OBJ			= $(SRC:.cpp=.o)
DEP			= $(SRC:.cpp=.d)

CPP			= g++ -std=c++98

CPPFLAGS	= -Wall -Wextra -Werror -MMD

RM			= rm -rf

######## COLORS ########
GREEN		= \033[1;92m
RED			= \033[1;91m
NC			= \033[0m

all:	$(NAME)

$(NAME): $(OBJ) Makefile
	${CPP} ${CPPFLAGS} ${OBJ} -o ${NAME}
	@echo "$(GREEN)\n✨ COMPILED ✨\n$(DEF_COLOR)"

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(DEP)
	@echo "$(RED)\nDELETED\n $(NC)"

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
