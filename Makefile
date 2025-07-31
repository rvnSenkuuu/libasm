# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/14 15:29:14 by tkara2            #+#    #+#              #
#    Updated: 2025/07/31 12:02:30 by tkara2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_strlen.s \
	   srcs/ft_strcmp.s \
	   srcs/ft_strcpy.s \
	   srcs/ft_strdup.s \
	   srcs/ft_write.s \
	   srcs/ft_read.s \
	   srcs/ft_atoi_base_bonus.s \
	   srcs/ft_list_size_bonus.s \
	   srcs/ft_list_push_front_bonus.s \
	   srcs/ft_list_sort_bonus.s \
	   srcs/ft_list_remove_if_bonus.s

OBJSDIR = .objs
OBJS = $(SRCS:%.s=$(OBJSDIR)/%.o)

INCS = ./incs/libasm.h

NAME = libasm.a
NASM = nasm
NASM_FLAGS = -felf64 -I incs/
AR = ar rcs
RM = rm -rf

TEST_FILES = tests/main.c \
			tests/test_mandatory.c \
			tests/test_bonus.c \
			tests/test_utils.c

TEST_OBJ = $(TEST_FILES:%.c=$(OBJSDIR)/%.o)
TEST_DEPS = $(TEST_OBJ:.o=.d)

TEST_NAME = libasm_test
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincs -MMD -MP

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJSDIR)/%.o: %.s
	mkdir -p $(@D)
	$(NASM) $(NASM_FLAGS) -o $@ $<

$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

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

-include $(TEST_DEPS)

.PHONY: all bonus test clean fclean re
