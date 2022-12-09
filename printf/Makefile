# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:34:27 by pbergero          #+#    #+#              #
#    Updated: 2022/11/11 13:26:02 by pbergero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#



#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f
LIBCMP	=	ar -rcs

# Output file name
NAME	=	libftprintf.a

# Sources are all .c files
SRCS	=	ft_printf.c\
			ft_printf_util.c\
			ft_printf_hexa.c\
			ft_printf_ptr.c 
			

# Objects are all .o files
OBJS	=	$(SRCS:.c=.o)
#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(LIBCMP) $(NAME) $(OBJS)

# Removes objectsm
clean:
	$(RM) $(OBJS) 

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)
# Removes objects and executables and remakes
re: fclean all

.PHONY: bonus all clean fclean re