# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adube <marvin@42quebec.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 10:00:24 by adube             #+#    #+#              #
#    Updated: 2023/01/25 14:18:05 by adube            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	ft_printf.c ft_printf_utils.c hexa_ft_printf.c ft_ptr_print.c u_print.c

OBJ = ${SRC:.c=.o}

CC = clang
CFLAGS = -Wall -Werror -Wextra

ARCHIVE = ar -rcs $(NAME) $(OBJ)

LIBERATE = rm -rf

LIBFT  = libft.a
LIBDIR = libft/

all: libft $(NAME)

$(NAME): $(OBJ)
	cp $(LIBDIR)$(LIBFT) $(NAME)
	$(ARCHIVE)
	@echo "\nPrintf Archived\n"

clean:
	$(LIBERATE) $(OBJ)
	$(LIBERATE) $(LIBDIR)*.o

fclean: clean
	$(LIBERATE) $(NAME)
	$(LIBERATE) $(LIBDIR)$(LIBFT)

re: fclean all

libft: 
	$(MAKE) -C $(LIBDIR)

.PHONY: all libft
