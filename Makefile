CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_DIR	= lib/minilibx-linux
LIBFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
RM = rm -rf

MANDATORY_DIR = .
NAME = ${MANDATORY_DIR}/build/minirt

INC_DIR = ${MANDATORY_DIR}/inc
INC_FILES = ${addprefix ${INC_DIR}/, minirt.h graphics.h}

SRC_DIR = ${MANDATORY_DIR}/src
SRC_FILES = ${addprefix ${SRC_DIR}/, minirt.c}
SRC_FILES += ${addprefix ${SRC_DIR}/graphics/, graphics.c}
SRC_FILES += ${addprefix ${SRC_DIR}/math_utils/, double_ops.c point.c tuple.c vector.c}
SRC_FILES += ${addprefix ${SRC_DIR}/math_utils/, tuple_misc_ops.c tuple_mul_div.c tuple_products.c}

BUILD_DIR = ${MANDATORY_DIR}/build
OBJ_DIR = ${BUILD_DIR}/obj
OBJ_FILES = ${patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC_FILES}}
OBJ_SUBDIRS = ${dir ${OBJ_FILES}}

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