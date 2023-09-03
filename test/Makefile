CC = cc
CFLAGS = -Wall -Wextra -g
LIBFLAGS = -lcriterion
RM = rm -rf

MINIRT_DIR = ..
MINIRT_INC_DIR = ${MINIRT_DIR}/inc
MINIRT_OBJ_DIR = ${MINIRT_DIR}/build/obj

TEST_DIR = .
TEST_INC_DIR = ${TEST_DIR}/inc
TEST_INC_FILES = ${addprefix ${TEST_INC_DIR}/, minirt.h}
TEST_SRC_DIR = ${TEST_DIR}/src
TEST_BUILD_DIR = ${TEST_DIR}/build
TEST_OBJ_DIR = ${TEST_DIR}/build/obj

all: tuple

minirt:
	make -C ${MINIRT_DIR}

tuple: minirt ${TEST_OBJ_DIR}/tuple_test.o
	${CC} ${CFLAGS} ${TEST_OBJ_DIR}/tuple_test.o ${addprefix ${MINIRT_OBJ_DIR}/, double_ops.o point.o tuple.o vector.o} ${LIBFLAGS} -o ${TEST_BUILD_DIR}/tuple_test
	${TEST_BUILD_DIR}/tuple_test --verbose || true

${TEST_OBJ_DIR}:
	mkdir -p ${TEST_OBJ_DIR}

${TEST_OBJ_DIR}/%.o: ${TEST_SRC_DIR}/%.c | ${TEST_OBJ_DIR}
	${CC} ${CFLAGS} -I${TEST_INC_DIR} -I${MINIRT_INC_DIR} -c $< -o $@

clean:
	${RM} ${TEST_OBJ_DIR}
	make -C ${MINIRT_DIR} clean

fclean: clean
	${RM} ${TEST_BUILD_DIR}
	make -C ${MINIRT_DIR} fclean

re: fclean all

.PHONY: all clean fclean minirt re tuple