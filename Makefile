# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 21:04:21 by pbergero          #+#    #+#              #
#    Updated: 2023/02/27 23:03:29 by pbergero         ###   ########.fr        #
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

LIBFT	=	./libft/libft.a
# Objects are all .o files
OBJS	=	$(SRCS:.c=.o)

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS) $(LIBFT)
	$(HIDE)$(CC) $(CFLAGS) $(LIBFT) -o $@ $^

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)
	$(MAKE) -C libft clean
# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)
	$(MAKE) -C libft fclean
# Removes objects and executables and remakes
re: fclean all

visu: all
	build/push_swap_visualizer/build/bin/visualizer

$(LIBFT):
	$(MAKE) -C libft