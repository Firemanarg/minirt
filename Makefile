CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -g
RM				:= rm -rf

# Libraries
LIB_DIR			:= lib
MLX_DIR			:= ${LIB_DIR}/minilibx-linux
MLX				:= ${MLX_DIR}/libmlx.a
LIBFLAGS		:= -L${MLX_DIR} -lmlx -lXext -lX11 -lm -lz
LFTX_DIR		:= ${LIB_DIR}/libft_x
LFTX			:= ${LFTX_DIR}/libft_x.a
FTLST_DIR		:= ${LIB_DIR}/ft_list
FTLST			:= ${FTLST_DIR}/ft_list.a

LIBS_INC		:= -I${MLX_DIR} -I${LFTX_DIR} -I${FTLST_DIR}

# Mandatory
MANDATORY_DIR	:= .

BUILD_DIR		:= ${MANDATORY_DIR}/build
NAME			:= ${BUILD_DIR}/minirt

# Bonus
BONUS_DIR		:= bonus

# Header files
INC_DIR			:= ${MANDATORY_DIR}/inc
INC_FILES		= ${addprefix ${INC_DIR}/,\
				error.h\
				graphics.h\
				matrix.h\
				minirt.h\
				objects.h\
				parser.h\
				projection.h\
				shading.h\
				varray.h\
				vec3.h}

# Source files
SRC_DIR			= ${MANDATORY_DIR}/src
SRC_FILES		= ${addprefix ${SRC_DIR}/, minirt.c}

# MLX graphics files
SRC_FILES		+= ${addprefix ${SRC_DIR}/graphics/,\
				mlx_utils.c\
				window.c}

# Matrix operation files
SRC_FILES += ${addprefix ${SRC_DIR}/matrix/, \
				matrix_apply.c \
				matrix_cofactor.c \
				matrix_determinant.c \
				matrix_free.c \
				matrix_inverse.c \
				matrix_new.c \
				matrix_minor.c \
				matrix_multiply.c \
				matrix_rotation.c \
				matrix_scaling.c \
				matrix_submatrix.c \
				matrix_translation.c \
				matrix_transpose.c \
				matrix_vec3_multiply.c}

# Object definition files
SRC_FILES += ${addprefix ${SRC_DIR}/objects/, \
				caps.c \
				clean_obj.c \
				color.c \
				cylinder.c \
				light.c \
				obj_utils.c \
				object.c \
				plane.c \
				scene.c \
				sphere.c}

# Projection files
SRC_FILES		+= ${addprefix ${SRC_DIR}/projection/,\
				hit.c\
				ray.c}

# Scene composition files
SRC_FILES		+= ${addprefix ${SRC_DIR}/scene/,\
				camera.c \
				scene.c \
				render.c \
				view.c}

# Shading, color and lighting operation files
SRC_FILES		+= ${addprefix ${SRC_DIR}/shading/, \
				lighting.c \
				material.c \
				shadow.c}

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

# Parser files
SRC_FILES		+= ${addprefix ${SRC_DIR}/parser/,\
				parse_ambient_light.c\
				parse_camera.c\
				parse_cylinder.c\
				parse_light.c\
				parse_plane.c\
				parse_sphere.c\
				parser_1.c\
				parser_2.c\
				parser_utils.c \
				validations.c}

SRC_FILES		+= ${addprefix ${SRC_DIR}/error/,\
				error.c \
				progress_bar.c}

# Object files
OBJ_DIR			= ${BUILD_DIR}/obj
OBJ_FILES		= ${patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC_FILES}}
OBJ_SUBDIRS		= ${sort ${dir ${OBJ_FILES}}}

# RULES

all: ${NAME}

${OBJ_SUBDIRS}:
	mkdir -p $@

${NAME}: ${LFTX} ${FTLST} ${MLX} ${OBJ_FILES}
	${CC} ${CFLAGS} ${OBJ_FILES} ${LIBFLAGS} ${LFTX} ${FTLST} -o $@

${OBJ_FILES}: ${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${INC_FILES} | ${OBJ_SUBDIRS}
	${CC} ${CFLAGS} -I${INC_DIR} ${LIBS_INC} -c $< -o $@

${LFTX}: ${LFTX_DIR}
	make -C ${LFTX_DIR}

${FTLST}: ${FTLST_DIR}
	make -C ${FTLST_DIR}

${MLX}: ${MLX_DIR}
	make -C ${MLX_DIR}

bonus:
	make -C ${BONUS_DIR}

clean:
	${RM} ${OBJ_DIR}
	make -C ${LFTX_DIR} clean
	make -C ${FTLST_DIR} clean
	make -C ${MLX_DIR} clean
	make -C ${BONUS_DIR} clean

fclean: clean
	${RM} ${NAME}
	make -C ${FTLST_DIR} fclean
	make -C ${BONUS_DIR} fclean

re: fclean all

.PHONY: all bonus clean fclean re
