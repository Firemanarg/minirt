CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_DIR	= lib/minilibx-linux
LIBFLAGS = -L${MLX_DIR} -lmlx -lXext -lX11 -lm -lz
RM = rm -rf

MANDATORY_DIR = .
SRC_DIR = ${MANDATORY_DIR}/src
INC_DIR = ${MANDATORY_DIR}/inc
BUILD_DIR = ${MANDATORY_DIR}/build
OBJ_DIR = ${BUILD_DIR}/obj

NAME = ${MANDATORY_DIR}/build/minirt

INC_FILES = ${addprefix ${INC_DIR}/, \
				error.h \
				graphics.h \
				matrix.h \
				minirt.h \
				objects.h \
				projection.h \
				shading.h \
				varray.h \
				vec3.h}

SRC_FILES = ${addprefix ${SRC_DIR}/, minirt.c}
SRC_FILES += ${addprefix ${SRC_DIR}/graphics/, \
				mlx_utils.c \
				window.c}
SRC_FILES += ${addprefix ${SRC_DIR}/matrix/, \
				matrix_apply.c \
				matrix_determinant.c \
				matrix_inverse.c \
				matrix_multiply.c \
				matrix_print.c \
				matrix_scaling.c \
				matrix_translation.c \
				matrix_cofactor.c \
				matrix_free.c \
				matrix_minor.c \
				matrix_new.c \
				matrix_rotation.c \
				matrix_submatrix.c \
				matrix_transpose.c \
				matrix_vec3_multiply.c}
SRC_FILES += ${addprefix ${SRC_DIR}/objects/, \
				caps.c \
				cleanup.c \
				color.c \
				cone.c \
				cylinder.c \
				object.c \
				plane.c \
				sphere.c}
SRC_FILES += ${addprefix ${SRC_DIR}/projection/, \
				hit.c \
				ray.c}
SRC_FILES += ${addprefix ${SRC_DIR}/shading/, \
				lighting.c \
				material.c \
				reflect.c}
SRC_FILES += ${addprefix ${SRC_DIR}/varray/, \
				bin_search.c \
				quicksort.c \
				var_array.c}
SRC_FILES += ${addprefix ${SRC_DIR}/vec3/, \
				double_ops.c \
				vec3.c \
				vec3_add_sub.c \
				vec3_misc_ops.c \
				vec3_mul_div.c \
				vec3_products.c}

OBJ_FILES = ${patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC_FILES}}
OBJ_SUBDIRS = ${sort ${dir ${OBJ_FILES}}}

all: ${NAME}

${OBJ_SUBDIRS}:
	mkdir -p $@

${NAME}: ${OBJ_FILES}
	${CC} ${CFLAGS} ${OBJ_FILES} ${LIBFLAGS} -o $@

${OBJ_FILES}: ${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${INC_FILES} | ${OBJ_SUBDIRS}
	${CC} ${CFLAGS} -I${INC_DIR} -I${MLX_DIR} -c $< -o $@

clean:
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re