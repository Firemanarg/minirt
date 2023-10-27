CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -g
RM				:= rm -rf

# Mandatory
MANDATORY_DIR	:= ..

# Libraries
MLX_DIR			:= ${MANDATORY_DIR}/lib/minilibx-linux
LIBFLAGS		:= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
LFTX_DIR		:= ${MANDATORY_DIR}/libft_x
LFTX			:= ${LFTX_DIR}/libft_x.a
FTLST_DIR		:= ${MANDATORY_DIR}/ft_list
FTLST			:= ${FTLST_DIR}/ft_list.a

LIBS_INC		:= -I${MLX_DIR} -I${LFTX_DIR} -I${FTLST_DIR}


# Bonus
BONUS_DIR		:= .

BUILD_DIR		:= ${MANDATORY_DIR}/build
NAME			:= ${BUILD_DIR}/minirt_bonus

# Header files
INC_DIR			:= ${BONUS_DIR}/inc
INC_FILES		= ${addprefix ${INC_DIR}/,\
				error_bonus.h \
				graphics_bonus.h \
				matrix_bonus.h \
				minirt_bonus.h \
				objects_bonus.h \
				parser_bonus.h \
				projection_bonus.h \
				shading_bonus.h \
				varray_bonus.h \
				vec3_bonus.h}

# Source files
SRC_DIR			= ${BONUS_DIR}/src
SRC_FILES		= ${addprefix ${SRC_DIR}/, minirt_bonus.c}

# MLX graphics files
SRC_FILES		+= ${addprefix ${SRC_DIR}/graphics/, \
				mlx_utils_bonus.c \
				window_bonus.c}

# Matrix operation files
SRC_FILES		+= ${addprefix ${SRC_DIR}/matrix/, \
				matrix_apply_bonus.c \
				matrix_determinant_bonus.c \
				matrix_inverse_bonus.c \
				matrix_multiply_bonus.c \
				matrix_print_bonus.c \
				matrix_rotate_translate_bonus.c \
				matrix_scaling_bonus.c \
				matrix_translation_bonus.c \
				matrix_cofactor_bonus.c \
				matrix_free_bonus.c \
				matrix_minor_bonus.c \
				matrix_new_bonus.c \
				matrix_rotation_bonus.c \
				matrix_submatrix_bonus.c \
				matrix_transpose_bonus.c \
				matrix_vec3_multiply_bonus.c}

# Object definition files
SRC_FILES		+= ${addprefix ${SRC_DIR}/objects/, \
				caps_bonus.c \
				scene_bonus.c \
				obj_utils_bonus.c \
				clean_obj_bonus.c \
				color_bonus.c \
				cone_bonus.c \
				cylinder_bonus.c \
				light_bonus.c \
				object_bonus.c \
				plane_bonus.c \
				sphere_bonus.c}

# Projection files
SRC_FILES		+= ${addprefix ${SRC_DIR}/projection/,\
				hit_bonus.c \
				ray_bonus.c}

# Scene composition files
SRC_FILES		+= ${addprefix ${SRC_DIR}/scene/,\
				camera_bonus.c \
				render_bonus.c \
				scene_bonus.c \
				view_bonus.c}

# Shading, color and lighting operation files
SRC_FILES		+= ${addprefix ${SRC_DIR}/shading/, \
				lighting_bonus.c \
				material_bonus.c \
				reflect_bonus.c \
				shadow_bonus.c}

# Varray files
SRC_FILES		+= ${addprefix ${SRC_DIR}/varray/,\
				bin_search_bonus.c \
				quicksort_bonus.c \
				var_array_bonus.c}

# Vec3 files
SRC_FILES		+= ${addprefix ${SRC_DIR}/vec3/,\
				double_ops_bonus.c \
				vec3_bonus.c \
				vec3_add_sub_bonus.c \
				vec3_misc_ops_bonus.c \
				vec3_mul_div_bonus.c \
				vec3_products_bonus.c}

# Parser files
SRC_FILES		+= ${addprefix ${SRC_DIR}/parser/,\
				parse_ambient_light_bonus.c \
				parse_camera_bonus.c \
				parse_cone_bonus.c \
				parse_cylinder_bonus.c \
				parse_light_bonus.c \
				parse_plane_bonus.c \
				parse_sphere_bonus.c \
				parser_1_bonus.c \
				parser_2_bonus.c \
				validations_bonus.c \
				parser_utils_bonus.c}

SRC_FILES		+= ${addprefix ${SRC_DIR}/error/,\
				error_bonus.c \
				progress_bar_bonus.c}

# Object files
OBJ_DIR			= ${BUILD_DIR}/obj
OBJ_FILES		= ${patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC_FILES}}
OBJ_SUBDIRS		= ${sort ${dir ${OBJ_FILES}}}

# RULES

all: ${NAME}

${OBJ_SUBDIRS}:
	mkdir -p $@

${NAME}: ${LFTX} ${FTLST} ${OBJ_FILES}
	${CC} ${CFLAGS} ${OBJ_FILES} ${LIBFLAGS} ${LFTX} ${FTLST} -o $@

${OBJ_FILES}: ${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${INC_FILES} | ${OBJ_SUBDIRS}
	${CC} ${CFLAGS} -I${INC_DIR} ${LIBS_INC} -c $< -o $@

${LFTX}: ${LFTX_DIR}
	make -C ${LFTX_DIR}

${FTLST}: ${FTLST_DIR}
	make -C  ${FTLST_DIR}

clean:
	${RM} ${OBJ_DIR}
	make -C ${LFTX_DIR} clean
	make -C  ${FTLST_DIR} clean

fclean: clean
	${RM} ${NAME}
	make -C ${LFTX_DIR} fclean
	make -C  ${FTLST_DIR} fclean

re: fclean all

.PHONY: all clean fclean re
