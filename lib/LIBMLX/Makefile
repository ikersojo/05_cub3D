# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 16:19:35 by isojo-go          #+#    #+#              #
#    Updated: 2022/12/24 08:26:58 by isojo-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Makefile structure ---

## Program Name:
NAME	=	libmlx.a

## Libraries:

## Header Files (dedicated and from libraries):
HEADERS	=	-I ./inc

## Source Files:
SRCS1	=	$(shell find ./src -name "*.c")
SRCS2	=	$(shell find ./src -name "*.m")
OBJS1	=	$(SRCS1:.c=.o)
OBJS2	=	$(SRCS2:.m=.o)
OBJS	=	$(OBJS2) $(OBJS1)

## Compilation flags:
CC			=	gcc
CFLAGS		+=	-O2
CFLAGS		+=	-DSTRINGPUTX11 # add to match string put with X11 in size and position
RM			=	rm -rf
AR			=	ar rc
DEBUG		=	-g3 -fsanitize=address

## Extras:
### Colors:
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# **************************************************************************** #

# --- Makefile instructions ---

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

%.o: %.c
			@echo $(OBJS)
			@echo -n "$(BLUE)Compiling: $(notdir $<) ...$(DEF_COLOR)"
			@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
			@echo "$(GREEN)Done!$(DEF_COLOR)"

%.o: %.m
			@printf "$(BLUE)Compiling: $(notdir $<) ...$(DEF_COLOR)"
			@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
			@echo "$(GREEN)Done!$(DEF_COLOR)"

clean:
			@$(RM) $(OBJS)
			@echo "$(YELLOW)$(NAME) object files removed!$(DEF_COLOR)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED)$(NAME) removed!$(DEF_COLOR)"


re:			fclean all

.PHONY:		all clean fclean re 
