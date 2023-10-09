CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -g  -fms-extensions
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

project_on_wall_with_light_cone: minirt ${TEST_OBJ_DIR}/project_on_wall_with_light_cone.o
	${CC} ${CFLAGS} ${TEST_OBJ_DIR}/project_on_wall_with_light_cone.o \
		${MINIRT_OBJ_DIR}/graphics/*.o \
		${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/shading/*.o \
		${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o \
		${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/project_on_wall_with_light_cone
	${TEST_BUILD_DIR}/project_on_wall_with_light_cone ${CRFLAGS} || true

project_on_wall_with_light_cylinder: minirt ${TEST_OBJ_DIR}/project_on_wall_with_light_cylinder.o
	${CC} ${CFLAGS} ${TEST_OBJ_DIR}/project_on_wall_with_light_cylinder.o \
		${MINIRT_OBJ_DIR}/graphics/*.o \
		${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/shading/*.o \
		${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o \
		${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/project_on_wall_with_light_cylinder
	${TEST_BUILD_DIR}/project_on_wall_with_light_cylinder ${CRFLAGS} || true

project_on_wall_with_light_plane: minirt ${TEST_OBJ_DIR}/project_on_wall_with_light_plane.o
	${CC} ${CFLAGS} ${TEST_OBJ_DIR}/project_on_wall_with_light_plane.o \
		${MINIRT_OBJ_DIR}/graphics/*.o \
		${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/shading/*.o \
		${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o \
		${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/project_on_wall_with_light_plane
	${TEST_BUILD_DIR}/project_on_wall_with_light_plane ${CRFLAGS} || true

project_on_wall_with_light_sphere: minirt ${TEST_OBJ_DIR}/project_on_wall_with_light_sphere.o
	${CC} ${CFLAGS} ${TEST_OBJ_DIR}/project_on_wall_with_light_sphere.o \
		${MINIRT_OBJ_DIR}/graphics/*.o \
		${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/shading/*.o \
		${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o \
		${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/project_on_wall_with_light_sphere
	${TEST_BUILD_DIR}/project_on_wall_with_light_sphere ${CRFLAGS} || true

render_world_test_specular: minirt ${TEST_OBJ_DIR}/render_world_test_specular.o
	${CC} ${CFLAGS} ${TEST_OBJ_DIR}/render_world_test_specular.o \
		${MINIRT_OBJ_DIR}/graphics/*.o \
		${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/scene/*.o \
		${MINIRT_OBJ_DIR}/shading/*.o \
		${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o \
		${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/render_world_test_specular
	${TEST_BUILD_DIR}/render_world_test_specular ${CRFLAGS} || true

render_world_with_camera: minirt ${TEST_OBJ_DIR}/render_world_with_camera.o
	${CC} ${CFLAGS} ${TEST_OBJ_DIR}/render_world_with_camera.o \
		${MINIRT_OBJ_DIR}/graphics/*.o \
		${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/scene/*.o \
		${MINIRT_OBJ_DIR}/shading/*.o \
		${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o \
		${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/render_world_with_camera
	${TEST_BUILD_DIR}/render_world_with_camera ${CRFLAGS} || true

render_world_with_multiple_lights: minirt ${TEST_OBJ_DIR}/render_world_with_multiple_lights.o
	${CC} ${CFLAGS} ${TEST_OBJ_DIR}/render_world_with_multiple_lights.o \
		${MINIRT_OBJ_DIR}/graphics/*.o \
		${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/scene/*.o \
		${MINIRT_OBJ_DIR}/shading/*.o \
		${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o \
		${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/render_world_with_multiple_lights
	${TEST_BUILD_DIR}/render_world_with_multiple_lights ${CRFLAGS} || true

render_world_with_objects: minirt ${TEST_OBJ_DIR}/render_world_with_objects.o
	${CC} ${CFLAGS} ${TEST_OBJ_DIR}/render_world_with_objects.o \
		${MINIRT_OBJ_DIR}/graphics/*.o \
		${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/scene/*.o \
		${MINIRT_OBJ_DIR}/shading/*.o \
		${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o \
		${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/render_world_with_objects
	${TEST_BUILD_DIR}/render_world_with_objects ${CRFLAGS} || true

render_world_with_planes: minirt ${TEST_OBJ_DIR}/render_world_with_planes.o
	${CC} ${CFLAGS} ${TEST_OBJ_DIR}/render_world_with_planes.o \
		${MINIRT_OBJ_DIR}/graphics/*.o \
		${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/scene/*.o \
		${MINIRT_OBJ_DIR}/shading/*.o \
		${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o \
		${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/render_world_with_planes
	${TEST_BUILD_DIR}/render_world_with_planes ${CRFLAGS} || true

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

.PHONY: all clean fclean minirt mlx_window project_on_wall \
		project_on_wall_with_light_cone project_on_wall_with_light_cylinder \
		project_on_wall_with_light_plane project_on_wall_with_light_sphere \
		render_world_test_specular \
		render_world_with_camera render_world_with_multiple_lights \
		render_world_with_objects render_world_with_planes