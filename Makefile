# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabouzah <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 05:26:56 by nabouzah          #+#    #+#              #
#    Updated: 2020/01/06 17:34:10 by nabouzah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fractol
LIB= libft/libft.a
FLAGS= -Wall -Wextra -Werror
OBJ= srcs/complex_calc.o srcs/init_fractal.o srcs/keyboard.o\
	 srcs/mandelbrot.o srcs/init.o srcs/julia.o\
	 srcs/mouse.o srcs/main.o srcs/color.o srcs/image.o srcs/complex_power.o\
	 srcs/tricorn.o srcs/julia_bar_set.o srcs/zoom.o
INC= includes/

all : $(LIB) $(NAME)

%.o : %.c $(INC)
	clang $(FLAGS) -c -o $@ $< -I $(INC)
$(NAME) : $(OBJ)
	@clang -o $@ $^ -lmlx -framework OpenGL -framework AppKit\
		-I $(INC) libft/libft.a
	@printf "\033[0;32m"
	@printf "DONE COMPILING"

$(LIB) :
	@make -C libft/
	@printf "\033[0;32m"
	@printf "LIBFT.a CREATED\n"
	@printf "\033[0m"

clean :
	@rm -rf $(OBJ) && make -C libft/ clean
	@printf "\033[0;32m"
	@printf "OBJ REMOVED\n"
	@printf "\033[0m"

fclean : clean
	@rm -f $(NAME) && make -C libft/ fclean
	@printf "\033[0;32m"
	@printf "DONE CLEANING\n"
	@printf "\033[0m"

re : fclean all
