# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:34:27 by pbergero          #+#    #+#              #
#    Updated: 2023/02/27 23:01:49 by pbergero         ###   ########.fr        #
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
NAME	=	libft.a

# Sources are all .c files
SRCS	=	base_libft/ft_calloc.c base_libft/ft_isalnum.c \
			base_libft/ft_isalpha.c base_libft/ft_isascii.c \
			base_libft/ft_isdigit.c \
			base_libft/ft_isprint.c base_libft/ft_itoa.c \
			base_libft/ft_memchr.c base_libft/ft_memcpy.c \
			base_libft/ft_memmove.c \
			base_libft/ft_memset.c base_libft/ft_putchar_fd.c \
			base_libft/ft_putendl_fd.c base_libft/ft_putnbr_fd.c \
			base_libft/ft_putstr_fd.c base_libft/ft_split.c \
			base_libft/ft_strchr.c base_libft/ft_strdup.c \
			base_libft/ft_striteri.c \
			base_libft/ft_strjoin.c base_libft/ft_strlcat.c \
			base_libft/ft_strlcpy.c base_libft/ft_strlen.c \
			base_libft/ft_strmapi.c \
			base_libft/ft_strncmp.c base_libft/ft_strnstr.c \
			base_libft/ft_strrchr.c base_libft/ft_strtrim.c \
			base_libft/ft_substr.c \
			base_libft/ft_tolower.c base_libft/ft_toupper.c \
			base_libft/ft_atoi.c base_libft/ft_bzero.c \
			base_libft/ft_memcmp.c base_libft/ft_strcmp.c\
			gnl/get_next_line.c\
			gnl/get_next_line_utils.c\
			new_utils_functions/free_double_array.c\
			new_utils_functions/square_power.c\
			new_utils_functions/write_error.c\
			new_utils_functions/str_is_int.c\
# Objects are all .o files
OBJS	=	$(SRCS:.c=.o)
OBJSB	=	$(SRCSB:.c=.o)
#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS) $(OBJSB)
	$(LIBCMP) $(NAME) $(OBJS) $(OBJSB) $(INC)
	
# Removes objectsm
clean:
	$(RM) $(OBJS) $(OBJSB)

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all

.PHONY: bonus all clean fclean re