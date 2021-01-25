NAME = philo_one

INCLUDES = ./includes

HEADER = ./philo_one.h \
		

SRCS = ./srcs/philo_one.c \
		./srcs/errors.c \
		./srcs/parsing.c \
		./srcs/utils.c \
		./srcs/init_mutex.c \
		./srcs/init_philo.c

OBJ = $(SRCS:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

%.o: %.c $(HEADER) 
	$(CC) -c $(CFLAGS) -I $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean flean re