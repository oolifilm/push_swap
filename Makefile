NAME		=	push_swap
CCF			=	clang -Wall -Wextra -Werror
LIBFT_PATH  =	libft/
LIBFT_FILE  =	libft.a
LIBFT_LIB	=	$(LIBFT_PATH)$(LIBFT_FILE)

C_FILE		=	check.c \
				find.c \
				free.c \
				init.c \
				push_swap.c \
				push.c \
				rev_rotate.c \
				rotate.c \
				sort_more.c \
				sort_stack.c \
				swap.c

INC		=	-I ./includes/ \

SRC_PATH	 =	./sources/
SRC		 =	$(addprefix $(SRC_PATH),$(C_FILE))

OBJ		 =	$(SRC:.c=.o)

ROSE		=	\033[1;38;5;206m
LILA		=	\033[1;38;5;177m
NC		  =	\033[0m

all: $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	@echo "$(LILA)COMPILATION DE LIBFT$(NC)"
	@make -sC $(LIBFT_PATH)
	@echo "$(ROSE)LIBFT CRÉÉE $(NC)"

$(NAME): $(OBJ)
	@echo "$(LILA)COMPILATION DE PUSH_SWAP$(NC)"
	$(CCF) -o $(NAME) $(OBJ) $(LIBFT_LIB) $(INC)
	@echo "$(ROSE)PUSH_SWAP CRÉÉ$(NC)"

clean:
	@echo "$(LILA)SUPPRESSION DES OBJECTS DANS LIBFT$(NC)" 
	@make clean -sC $(LIBFT_PATH)
	@echo "$(ROSE)DONE$(NC)"
	@echo "$(LILA)SUPPRESSION DES OBJECTS DANS PUSH_SWAP$(NC)"
	@rm -f $(OBJ)
	@rm -rf $(NAME)
	@echo "$(ROSE)DONE$(NC)"

fclean: clean
	@echo "$(LILA)SUPPRESSION DE L'EXÉCUTABLE DE PUSH_SWAP$(NC)"
	@rm -rf $(NAME)
	@rm -rf $(LIBFT_PATH)$(LIBFT_FILE)
	@echo "$(ROSE)DONE$(NC)"

re: fclean all

.PHONY: all clean fclean re
