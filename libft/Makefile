# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: absela <absela@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 22:31:46 by absela            #+#    #+#              #
#    Updated: 2021/12/02 20:54:14 by absela           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC = gcc

SRC := ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memcmp.c \
	   ft_strlcat.c \
	   ft_bzero.c \
	   ft_strrchr.c \
	   ft_strchr.c \
	   ft_toupper.c  \
	   ft_tolower.c \
	   ft_strdup.c \
	   ft_memchr.c \
	   ft_strncmp.c \
	   ft_strnstr.c \
	   ft_strlcpy.c \
	   ft_atoi.c 	\
	   ft_calloc.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_strmapi.c \
	   ft_split.c \
	   ft_striteri.c \
	   ft_itoa.c \


OBJ := $(SRC:.c=.o)

INC := libft.h 

FLAGS := -Wall -Wextra -Werror

$(NAME) : all

all : $(OBJ) 
	ar -rsc $(NAME) $(OBJ) 

%.o : %.c $(INC)
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)

fclean : clean 
	rm -rf $(NAME)

re : fclean all

# credit :
# 	@echo "\033[92m                                                                                                           \033[0m"
# 	@echo "\033[92mLLLLLLLLLLL               999999999          ZZZZZZZZZZZZZZZZZZZEEEEEEEEEEEEEEEEEEEEEEDDDDDDDDDDDDD        \033[0m"
# 	@echo "\033[92mL:::::::::L             99:::::::::99        Z:::::::::::::::::ZE::::::::::::::::::::ED::::::::::::DDD     \033[0m"
# 	@echo "\033[92mL:::::::::L           99:::::::::::::99      Z:::::::::::::::::ZE::::::::::::::::::::ED:::::::::::::::DD   \033[0m"
# 	@echo "\033[92mLL:::::::LL          9::::::99999::::::9     Z:::ZZZZZZZZ:::::Z EE::::::EEEEEEEEE::::EDDD:::::DDDDD:::::D  \033[0m"
# 	@echo "\033[92m  L:::::L            9:::::9     9:::::9     ZZZZZ     Z:::::Z    E:::::E       EEEEEE  D:::::D    D:::::D \033[0m"
# 	@echo "\033[92m  L:::::L            9:::::9     9:::::9             Z:::::Z      E:::::E               D:::::D     D:::::D\033[0m"
# 	@echo "\033[92m  L:::::L             9:::::99999::::::9            Z:::::Z       E::::::EEEEEEEEEE     D:::::D     D:::::D\033[0m"
# 	@echo "\033[92m  L:::::L              99::::::::::::::9           Z:::::Z        E:::::::::::::::E     D:::::D     D:::::D\033[0m"
# 	@echo "\033[92m  L:::::L                99999::::::::9           Z:::::Z         E:::::::::::::::E     D:::::D     D:::::D\033[0m"
# 	@echo "\033[92m  L:::::L                     9::::::9           Z:::::Z          E::::::EEEEEEEEEE     D:::::D     D:::::D\033[0m"
# 	@echo "\033[92m  L:::::L                    9::::::9           Z:::::Z           E:::::E               D:::::D     D:::::D\033[0m"
# 	@echo "\033[92m  L:::::L         LLLLLL    9::::::9         ZZZ:::::Z     ZZZZZ  E:::::E       EEEEEE  D:::::D    D:::::D \033[0m"
# 	@echo "\033[92mLL:::::::LLLLLLLLL:::::L   9::::::9          Z::::::ZZZZZZZZ:::ZEE::::::EEEEEEEE:::::EDDD:::::DDDDD:::::D  \033[0m"
# 	@echo "\033[92mL::::::::::::::::::::::L  9::::::9           Z:::::::::::::::::ZE::::::::::::::::::::ED:::::::::::::::DD   \033[0m"
# 	@echo "\033[92mL::::::::::::::::::::::L 9::::::9            Z:::::::::::::::::ZE::::::::::::::::::::ED::::::::::::DDD     \033[0m"
# 	@echo "\033[92mLLLLLLLLLLLLLLLLLLLLLLLL99999999             ZZZZZZZZZZZZZZZZZZZEEEEEEEEEEEEEEEEEEEEEEDDDDDDDDDDDDD        \033[0m"
# 	@echo "\033[92m                                                                                                           \033[0m"
# 	@echo "\033[92m                                                                                                           \033[0m"
# 	@echo "\033[92m                                                                                                           \033[0m"
