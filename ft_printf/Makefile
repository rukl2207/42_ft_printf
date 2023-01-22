# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scornhol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 15:21:40 by scornhol          #+#    #+#              #
#    Updated: 2021/12/05 15:21:42 by scornhol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

INCS_DIR	= ./include

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCS		= -I$(INCS_DIR) -I$(LIBFT_DIR)
LFLAGS		= -L$(LIBFT_DIR) -lft
LIB			= ar -rcs
LIB1		= ranlib
RM			= /bin/rm -f

SRC_DIR		= ./srcs
SRCS		= $(SRC_DIR)/ft_printf.c		\
			$(SRC_DIR)/ft_parse.c			\
			$(SRC_DIR)/ft_convert.c			\
			$(SRC_DIR)/ft_convert_c_s_pct.c	\
			$(SRC_DIR)/ft_convert_d_i.c		\
			$(SRC_DIR)/ft_convert_p_ux.c	\

OBJS		= $(SRCS:.c=.o)

.PHONY:		all clean fclean re bonus rebonus

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(LIB)	$(NAME) $(OBJS)
			$(LIB1) $(NAME)

.c.o:
			$(CC) $(CFLAGS) $(INCS) -c $< -o $(<:.c=.o)

$(LIBFT):
			make -C $(LIBFT_DIR)
			cp $(LIBFT) $(NAME)

bonus:		all

clean:
			make clean -C $(LIBFT_DIR)
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus