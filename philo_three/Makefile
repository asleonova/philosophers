NAME = philo_three

INCLUDES = ./includes

HEADER = ./philo_three.h \
		

SRCS = ./srcs/philo_three.c \
		./srcs/errors.c \
		./srcs/get_time.c \
		./srcs/init_philo.c \
		./srcs/init_sems.c \
		./srcs/philo_processes.c \
		./srcs/philo_cycle.c \
		./srcs/parsing.c \
		./srcs/print_status.c \
		./srcs/clear.c \
		./srcs/utils.c

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