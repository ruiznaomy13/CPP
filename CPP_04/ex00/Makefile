# ************************************************************************ #
#      ███╗   ███╗ █████╗░██╗░░██╗███████╗███████╗██╗██╗░░░░░███████╗      #
#      ████╗ ████║██╔══██╗██║░██╔╝██╔════╝██╔════╝██║██║░░░░░██╔════╝      #
#      ██╔████╔██║███████║█████═╝░█████╗░░█████╗░░██║██║░░░░░█████╗░░      #
#      ██║╚██╔╝██║██╔══██║██╔═██╗░██╔══╝░░██╔══╝░░██║██║░░░░░██╔══╝░░      #
#      ██║ ╚═╝ ██║██║  ██║██║░╚██╗███████╗██║░░░░░██║███████╗███████╗      #
#      ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝░░╚═╝╚══════╝╚═╝░░░░░╚═╝╚══════╝╚══════╝      #
# ************************************************************************ #
NAME        = Animal

DIR_SRC     = src
SRC         = $(DIR_SRC)/main.cpp $(DIR_SRC)/Animal.cpp $(DIR_SRC)/Cat.cpp \
              $(DIR_SRC)/Dog.cpp $(DIR_SRC)/WrongCat.cpp $(DIR_SRC)/WrongAnimal.cpp

DIR_HDR     = hdr
HDR         = $(DIR_HDR)/Animal.hpp $(DIR_HDR)/Dog.hpp $(DIR_HDR)/Cat.hpp \
              $(DIR_HDR)/WrongCat.hpp $(DIR_HDR)/WrongAnimal.hpp

DIR_OBJ     = obj
OBJ         = $(patsubst $(DIR_SRC)/%.cpp,$(DIR_OBJ)/%.o,$(SRC))
DEP         = $(patsubst $(DIR_SRC)/%.cpp,$(DIR_OBJ)/%.d,$(SRC))

CPP         = c++ -std=c++98
CPPFLAGS    = -Wall -Wextra -Werror -MMD
RM          = rm -rf

######## COLORS ########
GREEN       = \033[1;92m
RED         = \033[1;91m
NC          = \033[0m

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)\n✨ COMPILED ✨\n$(NC)"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.cpp
	@mkdir -p $(DIR_OBJ)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

-include $(DEP)

clean:
	$(RM) $(DIR_OBJ)
	@echo "$(RED)\nDELETED\n $(NC)"

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
