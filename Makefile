# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 17:29:19 by lsilva-q          #+#    #+#              #
#    Updated: 2023/09/26 17:29:19 by lsilva-q         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -g -fms-extensions
RM				:= rm -rf

# Libraries
MLX_DIR			:= lib/minilibx-linux
LIBFLAGS		:= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
LFTX_DIR		:= ./libft_x
LFTX			:= $(LFTX_DIR)/libft_x.a

# Mandatory
MANDATORY_DIR	:= .
NAME			:= ${MANDATORY_DIR}/build/minirt

# Header files
INC_DIR			:= ${MANDATORY_DIR}/inc
INC_FILES		= ${addprefix ${INC_DIR}/,\
				error.h\
				graphics.h\
				matrix.h\
				minirt.h\
				objects.h\
				projection.h\
				varray.h\
				vec3.h\
				shading.h\
				parser.h}

# Source files
SRC_DIR			= ${MANDATORY_DIR}/src
SRC_FILES		= ${addprefix ${SRC_DIR}/, minirt.c}

# MLX graphics files
SRC_FILES		+= ${addprefix ${SRC_DIR}/graphics/,\
				mlx_utils.c\
				window.c}

# Matrix files
SRC_FILES		+= ${addprefix ${SRC_DIR}/matrix/,\
				matrix_apply.c\
				matrix_determinant.c\
				matrix_inverse.c\
				matrix_multiply.c\
				matrix_print.c\
				matrix_scaling.c\
				matrix_translation.c\
				matrix_cofactor.c\
				matrix_free.c\
				matrix_minor.c\
				matrix_new.c\
				matrix_rotation.c\
				matrix_submatrix.c\
				matrix_transpose.c}

# Objects files
SRC_FILES		+= ${addprefix ${SRC_DIR}/objects/,\
				color.c\
				sphere.c}

# Projection files
SRC_FILES		+= ${addprefix ${SRC_DIR}/projection/,\
				hit.c\
				ray.c}

# Varray files
SRC_FILES		+= ${addprefix ${SRC_DIR}/varray/,\
				bin_search.c\
				quicksort.c\
				var_array.c}

# Vec3 files
SRC_FILES		+= ${addprefix ${SRC_DIR}/vec3/,\
				double_ops.c\
				vec3.c\
				vec3_add_sub.c\
				vec3_misc_ops.c\
				vec3_mul_div.c\
				vec3_products.c}

BUILD_DIR		:= ${MANDATORY_DIR}/build

# Object files
OBJ_DIR			= ${BUILD_DIR}/obj
OBJ_FILES		= ${patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC_FILES}}
OBJ_SUBDIRS		= ${sort ${dir ${OBJ_FILES}}}

# RULES

all: ${NAME}

${OBJ_SUBDIRS}:
	mkdir -p $@

${NAME}: $(LFTX) ${OBJ_FILES}
	${CC} ${CFLAGS} ${OBJ_FILES} ${LIBFLAGS} -o $@

${OBJ_FILES}: ${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${INC_FILES} | ${OBJ_SUBDIRS}
	${CC} ${CFLAGS} -I${INC_DIR} -I${MLX_DIR} -c $< -o $@

$(LFTX): $(LFTX_DIR)
	make -C $(LFTX_DIR)

clean:
	${RM} ${OBJ_DIR}
	make -C $(LFTX_DIR) clean

fclean: clean
	${RM} ${NAME}
	make -C $(LFTX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
