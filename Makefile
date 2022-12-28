# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdiaz-ca <fdiaz-ca@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 20:39:28 by fdiaz-ca          #+#    #+#              #
#    Updated: 2022/12/09 17:19:52 by fdiaz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

FT_DIR	= ./lib/libft

INC		= -I $(FT_DIR)

LIBS	= $(FT_DIR)/libft.a

CFLAGS	= -Wextra -Wall -Werror

SRCS	= pipex.c pipex_utils.c \

SRCS_B	= pipex_bonus.c pipex_utils_bonus.c \

OBJS	= $(SRCS:.c=.o)

OBJS_B	= $(SRCS_B:.c=.o)


GRN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

all:	$(NAME)

$(NAME):	$(OBJS)
	@echo "$(YEL)==== Building Libft ====$(EOC)"
	@make -C $(FT_DIR) --silent
	@echo "$(GRN)  _==__==_Done_==__==_       $(EOC)"
	@echo "$(YEL)==== Compiling pipex ====$(EOC)"
	@gcc $(OBJS) $(CFLAGS) $(INC) $(LIBS) -o $(NAME)
	@echo "$(GRN)==== pipex Compiled ====$(EOC)"

$(OBJS):	$(SRCS)
	@gcc -c $(SRCS) $(CFLAGS) $(INC)

bonus:		$(OBJS_B)
	@echo "$(YEL)==== Building Libft ====$(EOC)"
	@make -C $(FT_DIR) --silent
	@echo "$(GRN)  _==__==_Done_==__==_       $(EOC)"
	@echo "$(YEL)==== Compiling pipex bonus ====$(EOC)"
	@gcc $(OBJS_B) $(CFLAGS) $(INC) $(LIBS) -o $(NAME)
	@echo "$(GRN)==== pipex bonus Compiled ====$(EOC)"

$(OBJS_B):	$(SRCS_B)
	@gcc -c $(SRCS_B) $(CFLAGS) $(INC)

clean:
	@echo "$(YEL)==== Deleting objects files ====$(EOC)"
	@make -C $(FT_DIR) clean --silent
	@rm -rf $(OBJS) $(OBJS_B)
	@echo "$(YEL)       ==== Done ====  $(EOC)"

fclean:	clean
	@echo "$(YEL)==== Deleting binary files ====$(EOC)"
	@make -C $(FT_DIR) fclean --silent
	@rm -rf $(NAME)
	@echo "$(YEL)       ==== Done ====  $(EOC)"

re:		fclean all

.PHONY: all, bonus, clean, fclean, re