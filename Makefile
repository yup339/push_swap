# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 21:04:21 by pbergero          #+#    #+#              #
#    Updated: 2022/12/16 05:31:21 by pbergero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re
# 'HIDE = @' will hide all terminal output from Make
HIDE =


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

# Output file name
NAME	=	push_swap

# Sources are all .c files
SRCS	=	./src/sort_utils.c \
			./src/small_sorting_algo.c\
			./src/push_swap.c\
			./src/piles.c\
			./src/piles_util.c\
			./src/big_sorting_algo.c\
			./src/big_sort_util.c\
			./src/algo_ps_s.c\
			./src/algo_ps_r.c\
			./src/algo_ps_rr.c\
			./src/algo_ps_p.c\
			./src/fastest_push.c\
			./src/sort_using_a_piles.c\
			./src/sort_using_b_piles.c\
			./src/sort_using_both_piles_rrr.c\
			./src/sort_using_both_piles_rr.c\
			./src/try_fastest_algo.c\
			./src/mix_sort_ra_rb.c\
			./src/simplify.c

libft	=	./printf/libftprintf.a
# Objects are all .o files
OBJS	=	$(SRCS:.c=.o)

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(HIDE)$(CC) $(CFLAGS) $(libft) -o $@ $^

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all
