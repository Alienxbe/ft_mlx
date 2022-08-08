# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 00:02:10 by mykman            #+#    #+#              #
#    Updated: 2022/08/08 16:06:12 by mykman           ###   ########.fr        #
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
PREFIX			=	[${YELLOW}${FT}${RESET}]\t

# Variables
FT				:=	libftmlx
NAME			=	${FT}.a
MAIN			:=	test
LIBFT_FOLDER	=	Libft/
LIBFT_NAME		=	libft.a
MAKE_LIBFT		=	@make -s -C ${LIBFT_FOLDER}
MLX_FOLDER		=	minilibx_${detected_OS}
MLX_NAME		=	libmlx.a
MAKE_MLX		=	@make -s -C ${MLX_FOLDER}

# Files
INCLUDES		:=	-I./includes \
					-I./${LIBFT_FOLDER}/includes/general_functions \
					-I./${MLX_FOLDER} \
					-I./${LIBFT_FOLDER}/includes/ft_printf
LIBRARIES		:=	-L./Libft/ -lft \
					-L./minilibx_Darwin -lmlx \
					-L./ -lftmlx
SRCS_IMAGE		:=	ft_new_image.c \
					ft_new_subimage.c \
					ft_xpm_file_to_image.c
SRCS_PIXEL		:=	ft_get_pixel_color.c \
					ft_pixel_fill.c \
					ft_pixel_put.c \
					ft_pixel_replace_color.c
OBJS_IMAGE		:=	$(addprefix srcs/image/, ${SRCS_IMAGE:.c=.o})
OBJS_PIXEL		:=	$(addprefix srcs/pixel/, ${SRCS_PIXEL:.c=.o})
OBJS			=	${OBJS_IMAGE} ${OBJS_PIXEL}

# Rules
%.o:		%.c
	${CC} ${CFLAGS} -D OS=\"${detected_OS}\" -c ${INCLUDES} $< -o $@
	@echo "${PREFIX}Compilation of $<..."

$(NAME):	${OBJS}
	${MAKE_LIBFT}
	${MAKE_MLX}
	@ar -rcs $@ $^

main:	$(NAME)
	${CC} ${CFLAGS} ${MLXFLAGS} main.c ${INCLUDES} ${LIBRARIES}

all:		$(NAME)

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
