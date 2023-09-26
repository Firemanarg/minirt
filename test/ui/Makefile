CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -g -O2
MINIRT_DIR = ../..
MLX_DIR	= ${MINIRT_DIR}/lib/minilibx-linux
LIBFLAGS = -L${MLX_DIR} -lmlx -lXext -lX11 -lm -lz

MINIRT_INC_DIR = ${MINIRT_DIR}/inc
MINIRT_OBJ_DIR = ${MINIRT_DIR}/build/obj
TEST_DIR = .
TEST_INC_DIR = ${TEST_DIR}/inc
TEST_INC_FILES = ${addprefix ${TEST_INC_DIR}/, ui.h}
TEST_SRC_DIR = ${TEST_DIR}/src
TEST_BUILD_DIR = ${TEST_DIR}/build
TEST_OBJ_DIR = ${TEST_DIR}/build/obj

minirt:
	@make -s -C ${MINIRT_DIR}

mlx_window: minirt ${TEST_OBJ_DIR}/mlx_window_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/mlx_window_test.o \
		${MINIRT_OBJ_DIR}/graphics/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/mlx_window_test
	@${TEST_BUILD_DIR}/mlx_window_test ${CRFLAGS} || true

project_on_wall: minirt ${TEST_OBJ_DIR}/project_on_wall.o
	${CC} ${CFLAGS} ${TEST_OBJ_DIR}/project_on_wall.o \
		${MINIRT_OBJ_DIR}/graphics/*.o \
		${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/shading/*.o \
		${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o \
		${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/project_on_wall
	${TEST_BUILD_DIR}/project_on_wall ${CRFLAGS} || true

project_on_wall_with_light: minirt ${TEST_OBJ_DIR}/project_on_wall_with_light.o
	${CC} ${CFLAGS} ${TEST_OBJ_DIR}/project_on_wall_with_light.o \
		${MINIRT_OBJ_DIR}/graphics/*.o \
		${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/shading/*.o \
		${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o \
		${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/project_on_wall_with_light
	${TEST_BUILD_DIR}/project_on_wall_with_light ${CRFLAGS} || true

project_on_wall_with_light_cyl: minirt ${TEST_OBJ_DIR}/project_on_wall_with_light_cyl.o
	${CC} ${CFLAGS} ${TEST_OBJ_DIR}/project_on_wall_with_light_cyl.o \
		${MINIRT_OBJ_DIR}/graphics/*.o \
		${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/shading/*.o \
		${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o \
		${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/project_on_wall_with_light_cyl
	${TEST_BUILD_DIR}/project_on_wall_with_light_cyl ${CRFLAGS} || true

${TEST_OBJ_DIR}:
	@mkdir -p ${TEST_OBJ_DIR}

${TEST_OBJ_DIR}/%.o: ${TEST_SRC_DIR}/%.c | ${TEST_OBJ_DIR}
	${CC} ${CFLAGS} -I${TEST_INC_DIR} -I${MINIRT_INC_DIR} -I${MLX_DIR} -c $< -o $@

clean:
	${RM} ${TEST_OBJ_DIR}
	make -C ${MINIRT_DIR} clean

fclean: clean
	${RM} ${TEST_BUILD_DIR}
	make -C ${MINIRT_DIR} fclean

re: fclean all

.PHONY: all clean fclean minirt mlx_window project_on_wall project_on_wall_with_light re