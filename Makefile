CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFLAGS =
RM = rm -rf

MANDATORY_DIR = .
NAME = ${MANDATORY_DIR}/build/minirt

INC_DIR = ${MANDATORY_DIR}/inc
INC_FILES = ${addprefix ${INC_DIR}/, minirt.h}

SRC_DIR = ${MANDATORY_DIR}/src
SRC_FILES = ${addprefix ${SRC_DIR}/, double_ops.c minirt.c point.c tuple.c vector.c}

BUILD_DIR = ${MANDATORY_DIR}/build
OBJ_DIR = ${BUILD_DIR}/obj
OBJ_FILES = ${addprefix ${OBJ_DIR}/, ${notdir ${SRC_FILES:.c=.o}}}

all: ${NAME}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

${NAME}: ${OBJ_FILES}
	${CC} ${CFLAGS} ${OBJ_FILES} ${LIBFLAGS} -o $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${INC_FILES} | ${OBJ_DIR}
	${CC} ${CFLAGS} -I${INC_DIR} -c $< -o $@

clean:
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re