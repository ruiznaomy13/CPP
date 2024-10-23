# ************************************************************************ #
#      ███╗   ███╗ █████╗░██╗░░██╗███████╗███████╗██╗██╗░░░░░███████╗      #
#      ████╗ ████║██╔══██╗██║░██╔╝██╔════╝██╔════╝██║██║░░░░░██╔════╝      #
#      ██╔████╔██║███████║█████═╝░█████╗░░█████╗░░██║██║░░░░░█████╗░░      #
#      ██║╚██╔╝██║██╔══██║██╔═██╗░██╔══╝░░██╔══╝░░██║██║░░░░░██╔══╝░░      #
#      ██║ ╚═╝ ██║██║  ██║██║░╚██╗███████╗██║░░░░░██║███████╗███████╗      #
#      ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝░░╚═╝╚══════╝╚═╝░░░░░╚═╝╚══════╝╚══════╝      #
# ************************************************************************ #
NAME        = template

DIR_SRC     = src
SRC         = $(DIR_SRC)/main.cpp

DIR_HDR     = hdr
HDR         = $(DIR_HDR)/Methods.hpp

DIR_OBJ     = obj
OBJ         = $(patsubst $(DIR_SRC)/%.cpp,$(DIR_OBJ)/%.o,$(SRC))
DEP         = $(patsubst $(DIR_SRC)/%.cpp,$(DIR_OBJ)/%.d,$(SRC))

CPP         = c++ -std=c++98
CPPFLAGS    = -Wall -Wextra -Werror -MMD -I$(DIR_HDR)
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
