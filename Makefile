# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 00:02:10 by mykman            #+#    #+#              #
#    Updated: 2022/08/12 04:29:33 by mykman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
CC				=	@gcc
CFLAGS				=	-Wall -Wextra -Werror

# Colors
RED					:=	\033[38;5;9m
GREEN				:=	\033[38;5;10m
BLUE				:=	\033[38;5;14m
YELLOW				:=	\033[38;5;226m
RESET				:=	\033[38;5;7m
PREFIX				=	[${YELLOW}${FT}${RESET}]\t

# Variables
LIBFT_MLX_FOLDER	:=	.
FT					:=	libft_mlx
NAME				=	${LIBFT_MLX_FOLDER}/${FT}.a
SRCS_PATH			:=	srcs
OBJS_PATH			:=	objs

LIBFT_FOLDER		:=	Libft
LIBFT_NAME			:=	libft.a
LIBFT_PATH			:=	${LIBFT_FOLDER}/${LIBFT_NAME}

MLX_FOLDER			:=	minilibx_${detected_OS}
MLX_NAME			:=	libmlx.a
LIBFT_PATH			:=	${MLX_FOLDER}/${MLX_NAME}

# Files
INCLUDES			:=	-I ./includes \
						-I ${LIBFT_FOLDER}/includes \
						-I ${MLX_FOLDER}
LIBRARIES			:=	-L ${LIBFT_FOLDER} -lft \
						-L ${MLX_FOLDER} -lmlx \
						-L ${LIBFT_MLX_FOLDER} -lft_mlx

SRCS_IMAGE			:=	ft_cpy_image.c \
						ft_new_image.c \
						ft_new_subimage.c \
						ft_xpm_file_to_image.c
SRCS_PIXEL			:=	ft_pixel_area_cpy.c \
						ft_pixel_cpy.c \
						ft_pixel_fill.c \
						ft_pixel_get_color.c \
						ft_pixel_iter.c \
						ft_pixel_put.c \
						ft_pixel_replace_color.c
SRCS_SCENE			:=	ft_scene.c
SRCS_WINDOW			:=	ft_new_window.c \
						ft_put_image_to_window.c \
						ft_update_window.c
SRCS				:=	$(addprefix ${SRCS_PATH}/image/, ${SRCS_IMAGE})
SRCS				+=	$(addprefix ${SRCS_PATH}/pixel/, ${SRCS_PIXEL})
SRCS				+=	$(addprefix ${SRCS_PATH}/scene/, ${SRCS_SCENE})
SRCS				+=	$(addprefix ${SRCS_PATH}/window/, ${SRCS_WINDOW})
OBJS				:=	$(patsubst ${SRCS_PATH}/%.c, ${OBJS_PATH}/%.o, ${SRCS})

# Rules	
${OBJS_PATH}/%.o:	${SRCS_PATH}/%.c
	${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@
	@echo "${PREFIX}Compilation of $<..."

$(NAME):			${OBJS}
	@ar -rcs $@ $^

all:				$(NAME)

clean:
	@rm -f ${OBJS}

fclean:
	@rm -f ${NAME} ${OBJS}

re:					fclean all

.PHONY:				all clean fclean re
