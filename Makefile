# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 16:19:35 by isojo-go          #+#    #+#              #
#    Updated: 2023/05/04 11:09:52 by isojo-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Makefile structure ---

## Program Name:
NAME	=	cub3D

## Folder Structure:
SRCDIR		=	src
OBJDIR		=	obj
BINDIR		=	bin

SRC_BDIR	=	src_bonus
OBJ_BDIR	=	obj_bonus
BIN_BDIR	=	bin_bonus

## Libraries:
LIBMLX	=	./lib/LIBMLX
LIBFT	=	./lib/LIBFT
LIBS	=	$(LIBFT)/libft.a $(LIBMLX)/libmlx.a -framework OpenGL -framework AppKit

## Header Files (dedicated and from libraries):
HEADERS	=	-I ./inc -I $(LIBFT)/inc -I $(LIBMLX)/inc

## Source Files:
SRC		=	$(wildcard $(SRCDIR)/*.c)
OBJ		=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

SRC_B	=	$(wildcard $(SRC_BDIR)/*.c)
OBJ_B	=	$(SRC_B:$(SRC_BDIR)/%.c=$(OBJ_BDIR)/%.o)

## Compilation flags:
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address
RM			=	rm -rf

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

$(NAME):	libft libmlx $(OBJ)
			@mkdir -p $(BINDIR)
			@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(HEADERS) -o ./$(BINDIR)/$(NAME)
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

bonus:		libft libmlx $(OBJ_B)
			@mkdir -p $(BIN_BDIR)
			@$(CC) $(CFLAGS) $(OBJ_B) $(LIBS) $(HEADERS) -o ./$(BIN_BDIR)/$(NAME)
			@echo "$(GREEN)$(NAME) bonus compiled!$(DEF_COLOR)"

libmlx:
			@$(MAKE) -C $(LIBMLX)

libft:
			@$(MAKE) -C $(LIBFT)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			@mkdir -p $(OBJDIR)
			@printf "$(BLUE)Compiling: $< ...$(DEF_COLOR)"
			@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
			@echo "$(GREEN)Done!$(DEF_COLOR)"

$(OBJ_BDIR)/%.o: $(SRC_BDIR)/%.c
			@mkdir -p $(OBJ_BDIR)
			@printf "$(BLUE)Compiling: $< ...$(DEF_COLOR)"
			@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
			@echo "$(GREEN)Done!$(DEF_COLOR)"

clean:
			@$(RM) $(OBJ) $(OBJDIR) $(OBJ_B) $(OBJ_BDIR)
			@echo "$(YELLOW)$(NAME) object files removed!$(DEF_COLOR)"
			@$(MAKE) -C $(LIBFT) clean
			@$(MAKE) -C $(LIBMLX) clean

fclean:
			@$(MAKE) -C $(LIBFT) fclean
			@$(MAKE) -C $(LIBMLX) fclean
			@if [ -d $(OBJDIR) ]; then \
				$(RM) $(OBJ) $(OBJDIR) $(OBJ_B) $(OBJ_BDIR); \
				echo "$(YELLOW)$(NAME) object files removed!$(DEF_COLOR)"; \
			fi
			@$(RM) $(NAME) $(BINDIR) $(BIN_BDIR)
			@echo "$(RED)$(NAME) removed!$(DEF_COLOR)"

re:			fclean all

.PHONY:		all clean fclean re libft libmlx
