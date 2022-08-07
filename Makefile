# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 00:02:10 by mykman            #+#    #+#              #
#    Updated: 2022/08/07 18:55:27 by mykman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OS
ifeq ($(OS),Windows_NT) 
	detected_OS := Windows
else
	detected_OS := $(shell uname)
endif

# Compilation
CC				=	@gcc
CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address
ifeq ($(detected_OS), Linux)
	MLXFLAGS	:=	-lXext -lX11 -lm -lz
else ifeq ($(detected_OS), Darwin)
	MLXFLAGS	:=	-framework OpenGL -framework AppKit
endif

# Colors
RED				:=	\033[38;5;9m
GREEN			:=	\033[38;5;10m
BLUE			:= 	\033[38;5;14m
YELLOW			:=	\033[38;5;226m
RESET			:=	\033[38;5;7m
PREFIX			=	[${YELLOW}${NAME}${RESET}]\t\t

# Variables
NAME			=	ft_mlx
LIBFT_FOLDER	=	Libft/
LIBFT_NAME		=	libft.a
MAKE_LIBFT		=	@make -s -C ${LIBFT_FOLDER}
MLX_FOLDER		=	minilibx_${detected_OS}
MLX_NAME		=	libmlx.a
MAKE_MLX		=	@make -s -C ${MLX_FOLDER}

# Files
INCLUDES		=	-I./includes \
					-I./${LIBFT_FOLDER}/includes/general_functions \
					-I./${MLX_FOLDER}
SRCS			=	main.c \
					ft_new_image.c \
					ft_pixel_put.c
OBJS			=	$(addprefix srcs/, ${SRCS:.c=.o})

# Rules
%.o:		%.c
	${CC} ${CFLAGS} -D OS=\"${detected_OS}\" -c ${INCLUDES} $< -o $@
	@echo "${PREFIX}Compilation of $<..."

$(NAME):	${OBJS}
	${MAKE_LIBFT}
	${MAKE_MLX}
	${CC} ${CFLAGS} ${MLXFLAGS} ${INCLUDES} $^ ${LIBFT_FOLDER}/${LIBFT_NAME} \
		${MLX_FOLDER}/${MLX_NAME} -o $@

all:	$(NAME)

clean:
	${MAKE_LIBFT} clean
	${MAKE_MLX} clean
	@rm -f ${OBJS}

fclean:
	${MAKE_LIBFT} fclean
	${MAKE_MLX} clean
	@rm -f ${NAME} ${OBJS}

re:		fclean all

.PHONY:	all clean fclean re
