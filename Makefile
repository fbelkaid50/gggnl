# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelkaid <fbelkaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 12:27:14 by fbelkaid          #+#    #+#              #
#    Updated: 2024/02/05 17:43:52 by fbelkaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	get_next_line.a

CC =	cc

CFLAGS =	-Wall -Wextra -Werror

RM = rm	-rf 

AR = ar rcs

HEADE	= 	get_next_line.h

SRC	=	get_next_line.c	get_next_line_utils.c 
BSRC	=	get_next_line_bonus.c	get_next_line_utils_bonus.c

OBJ	=	$(SRC:%.c=%.o)
BOBJ	=	$(BSRC:%.c=%.o)	

%.o:	%.c	$(HEADER)
	$(CC)	$(CFLAGS)	-c	$<	-o	$@

all	:	$(NAME)
bonus : $(BOBJ)
	@$(AR) $(NAME) $(BOBJ)	

$(NAME)	:	$(OBJ) 
	$(AR)	$(NAME)	$(OBJ)
    
clean	:
	@$(RM)	$(OBJ) 

fclean	:
	@$(RM)	$(NAME)	$(OBJ) $(BOBJ)

re	:	fclean	all

.PHONY :	all	clean	fclean	re
