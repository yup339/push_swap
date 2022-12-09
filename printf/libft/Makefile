# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:34:27 by pbergero          #+#    #+#              #
#    Updated: 2022/11/30 04:41:48 by pbergero         ###   ########.fr        #
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
SRCS	=	ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_itoa.c ft_memchr.c ft_memcpy.c ft_memmove.c \
			ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
			ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
			ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
			ft_tolower.c ft_toupper.c ft_atoi.c ft_bzero.c ft_memcmp.c \
			ft_long_atoi.c ft_isnumber.c
			
SRCSB	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
			ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c 
# Objects are all .o files
OBJS	=	$(SRCS:.c=.o)
OBJSB	=	$(SRCSB:.c=.o)

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(LIBCMP) $(NAME) $(OBJS)

# Removes objectsm
clean:
	$(RM) $(OBJS) $(OBJSB)

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)

# bonus functions
bonus: $(OBJSB) $(OBJS)
	 $(LIBCMP) $(NAME) $(OBJSB) $(OBJS)
# Removes objects and executables and remakes
re: fclean all

.PHONY: bonus all clean fclean re