# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/14 15:29:14 by tkara2            #+#    #+#              #
#    Updated: 2025/07/18 14:56:46 by tkara2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_strlen.s \
		srcs/ft_strcmp.s \
		srcs/ft_strcpy.s \
		srcs/ft_strdup.s \
		srcs/ft_write.s \
		srcs/ft_read.s

OBJSDIR = .objs
OBJS = $(patsubst %.s,$(OBJSDIR)/%.o,$(SRCS))

INCS = ./incs/libasm.h

NAME = libasm.a
NASM = nasm
NASM_FLAGS = -felf64
AR = ar rcs
RM = rm -rf

TEST_FILE = srcs/main.c \
			srcs/test_mandatory.c

TEST_OBJ = $(addprefix $(OBJSDIR)/,$(TEST_FILE:.c=.o))

TEST_NAME = libasm_test
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJSDIR)/%.o:	%.s
	mkdir -p $(@D)
	$(NASM) $(NASM_FLAGS) -o $@ $<

$(OBJSDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME) $(TEST_NAME)
	./$(TEST_NAME)

$(TEST_NAME): $(TEST_OBJ) $(NAME)
	$(CC) $(CFLAGS) $(TEST_OBJ) $(NAME) -o $@

clean:
	$(RM) $(OBJSDIR)

fclean: clean
	$(RM) $(NAME) $(TEST_NAME)

re: fclean
	$(MAKE) all

.PHONY: all test clean fclean re