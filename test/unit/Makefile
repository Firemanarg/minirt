CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -fms-extensions -g
LIBFLAGS = -lcriterion -lm
CRFLAGS = --verbose=1
# CRFLAGS =

MINIRT_DIR = ../..
MINIRT_INC_DIR = ${MINIRT_DIR}/inc
MINIRT_OBJ_DIR = ${MINIRT_DIR}/build/obj

MLX_DIR	= ${MINIRT_DIR}/lib/minilibx-linux

TEST_DIR = .
TEST_INC_DIR = ${TEST_DIR}/inc
TEST_INC_FILES = ${addprefix ${TEST_INC_DIR}/, minirt_test.h}
TEST_SRC_DIR = ${TEST_DIR}/src
TEST_BUILD_DIR = ${TEST_DIR}/build
TEST_OBJ_DIR = ${TEST_DIR}/build/obj

all: apply_matrix_ops bin_search capped_cone cone_intersect cone_normal \
	capped_cylinder cylinder_intersect cylinder_normal \
	lighting matrix_vec3_multiply quicksort plane ray_transform reflect \
	scene sphere_hit sphere_intersect sphere_normal sphere_transform \
	truncated_cylinder var_array vec3_ops view_transform

minirt:
	@make -s -C ${MINIRT_DIR}

clean:
	${RM} ${TEST_OBJ_DIR}
	make -C ${MINIRT_DIR} clean

fclean: clean
	${RM} ${TEST_BUILD_DIR}
	make -C ${MINIRT_DIR} fclean

re: fclean all

apply_matrix_ops: minirt ${TEST_OBJ_DIR}/apply_matrix_ops_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/apply_matrix_ops_test.o ${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/apply_matrix_ops_test
	@${TEST_BUILD_DIR}/apply_matrix_ops_test ${CRFLAGS} || true

apply_matrix_ops_leaks: minirt ${TEST_OBJ_DIR}/apply_matrix_ops_leaks.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/apply_matrix_ops_leaks.o ${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/apply_matrix_ops_leaks
	@${TEST_BUILD_DIR}/apply_matrix_ops_leaks ${CRFLAGS} || true

bin_search: minirt ${TEST_OBJ_DIR}/bin_search_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/bin_search_test.o ${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/bin_search_test
	@${TEST_BUILD_DIR}/bin_search_test ${CRFLAGS} || true

capped_cone: minirt ${TEST_OBJ_DIR}/capped_cone_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/capped_cone_test.o ${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o ${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${MINIRT_OBJ_DIR}/matrix/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/capped_cone_test
	@${TEST_BUILD_DIR}/capped_cone_test ${CRFLAGS} || true

capped_cylinder: minirt ${TEST_OBJ_DIR}/capped_cylinder_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/capped_cylinder_test.o ${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o ${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${MINIRT_OBJ_DIR}/matrix/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/capped_cylinder_test
	@${TEST_BUILD_DIR}/capped_cylinder_test ${CRFLAGS} || true

cone_intersect: minirt ${TEST_OBJ_DIR}/cone_intersect_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/cone_intersect_test.o ${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o ${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${MINIRT_OBJ_DIR}/matrix/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/cone_intersect_test
	@${TEST_BUILD_DIR}/cone_intersect_test ${CRFLAGS} || true

cone_normal: minirt ${TEST_OBJ_DIR}/cone_normal_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/cone_normal_test.o ${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/shading/*.o ${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/objects/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/cone_normal_test
	@${TEST_BUILD_DIR}/cone_normal_test ${CRFLAGS} || true

cylinder_intersect: minirt ${TEST_OBJ_DIR}/cylinder_intersect_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/cylinder_intersect_test.o ${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o ${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${MINIRT_OBJ_DIR}/matrix/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/cylinder_intersect_test
	@${TEST_BUILD_DIR}/cylinder_intersect_test ${CRFLAGS} || true

cylinder_normal: minirt ${TEST_OBJ_DIR}/cylinder_normal_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/cylinder_normal_test.o ${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/shading/*.o ${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/objects/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/cylinder_normal_test
	@${TEST_BUILD_DIR}/cylinder_normal_test ${CRFLAGS} || true

lighting: ${TEST_OBJ_DIR}/lighting_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/lighting_test.o ${MINIRT_OBJ_DIR}/vec3/*.o \
		 ${MINIRT_OBJ_DIR}/projection/*.o ${MINIRT_OBJ_DIR}/shading/*.o \
		 ${MINIRT_OBJ_DIR}/varray/*.o ${MINIRT_OBJ_DIR}/matrix/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/lighting_test
	@${TEST_BUILD_DIR}/lighting_test ${CRFLAGS} || true

matrix_vec3_multiply: minirt ${TEST_OBJ_DIR}/matrix_vec3_multiply_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/matrix_vec3_multiply_test.o ${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/matrix_vec3_multiply_test
	@${TEST_BUILD_DIR}/matrix_vec3_multiply_test ${CRFLAGS} || true

quicksort: minirt ${TEST_OBJ_DIR}/quicksort_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/quicksort_test.o ${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/quicksort_test
	@${TEST_BUILD_DIR}/quicksort_test ${CRFLAGS} || true

plane: minirt ${TEST_OBJ_DIR}/plane_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/plane_test.o ${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/shading/*.o ${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/objects/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/plane_test
	@${TEST_BUILD_DIR}/plane_test ${CRFLAGS} || true

ray_transform: minirt ${TEST_OBJ_DIR}/ray_transform_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/ray_transform_test.o ${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/varray/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/ray_transform_test
	@${TEST_BUILD_DIR}/ray_transform_test ${CRFLAGS} || true

reflect: minirt ${TEST_OBJ_DIR}/reflect_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/reflect_test.o ${MINIRT_OBJ_DIR}/vec3/*.o \
		 ${MINIRT_OBJ_DIR}/projection/*.o ${MINIRT_OBJ_DIR}/shading/*.o \
		 ${MINIRT_OBJ_DIR}/varray/*.o ${MINIRT_OBJ_DIR}/matrix/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/reflect_test
	@${TEST_BUILD_DIR}/reflect_test ${CRFLAGS} || true

scene: minirt ${TEST_OBJ_DIR}/scene_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/scene_test.o ${MINIRT_OBJ_DIR}/vec3/*.o \
		 ${MINIRT_OBJ_DIR}/objects/*.o \
		 ${MINIRT_OBJ_DIR}/projection/*.o ${MINIRT_OBJ_DIR}/scene/*.o \
		 ${MINIRT_OBJ_DIR}/shading/*.o ${MINIRT_OBJ_DIR}/varray/*.o \
		 ${MINIRT_OBJ_DIR}/matrix/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/scene_test
	@${TEST_BUILD_DIR}/scene_test ${CRFLAGS} || true

sphere_hit: minirt ${TEST_OBJ_DIR}/sphere_hit_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/sphere_hit_test.o ${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o ${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${MINIRT_OBJ_DIR}/matrix/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/sphere_hit_test
	@${TEST_BUILD_DIR}/sphere_hit_test ${CRFLAGS} || true

sphere_intersect: minirt ${TEST_OBJ_DIR}/sphere_intersect_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/sphere_intersect_test.o ${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o ${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${MINIRT_OBJ_DIR}/matrix/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/sphere_intersect_test
	@${TEST_BUILD_DIR}/sphere_intersect_test ${CRFLAGS} || true

sphere_normal: minirt ${TEST_OBJ_DIR}/sphere_normal_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/sphere_normal_test.o ${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/shading/*.o ${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/objects/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/sphere_normal_test
	@${TEST_BUILD_DIR}/sphere_normal_test ${CRFLAGS} || true

sphere_transform: minirt ${TEST_OBJ_DIR}/sphere_transform_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/sphere_transform_test.o ${MINIRT_OBJ_DIR}/matrix/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${MINIRT_OBJ_DIR}/projection/*.o \
		${MINIRT_OBJ_DIR}/varray/*.o ${MINIRT_OBJ_DIR}/objects/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/sphere_transform_test
	@${TEST_BUILD_DIR}/sphere_transform_test ${CRFLAGS} || true

truncated_cylinder: minirt ${TEST_OBJ_DIR}/truncated_cylinder_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/truncated_cylinder_test.o ${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/projection/*.o ${MINIRT_OBJ_DIR}/objects/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${MINIRT_OBJ_DIR}/matrix/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/truncated_cylinder_test
	@${TEST_BUILD_DIR}/truncated_cylinder_test ${CRFLAGS} || true

var_array: minirt ${TEST_OBJ_DIR}/var_array_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/var_array_test.o ${MINIRT_OBJ_DIR}/varray/*.o \
		${MINIRT_OBJ_DIR}/vec3/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/var_array_test
	@${TEST_BUILD_DIR}/var_array_test ${CRFLAGS} || true

vec3_ops: minirt ${TEST_OBJ_DIR}/vec3_ops_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/vec3_ops_test.o ${MINIRT_OBJ_DIR}/vec3/*.o \
		${LIBFLAGS} -o ${TEST_BUILD_DIR}/vec3_ops_test
	@${TEST_BUILD_DIR}/vec3_ops_test ${CRFLAGS} || true

view_transform: minirt ${TEST_OBJ_DIR}/view_transform_test.o
	@${CC} ${CFLAGS} ${TEST_OBJ_DIR}/view_transform_test.o ${MINIRT_OBJ_DIR}/vec3/*.o \
		 ${MINIRT_OBJ_DIR}/scene/view.o \
		 ${MINIRT_OBJ_DIR}/matrix/*.o ${LIBFLAGS} \
		-o ${TEST_BUILD_DIR}/view_transform
	@${TEST_BUILD_DIR}/view_transform ${CRFLAGS} || true

${TEST_OBJ_DIR}:
	@mkdir -p ${TEST_OBJ_DIR}

${TEST_OBJ_DIR}/%.o: ${TEST_SRC_DIR}/%.c | ${TEST_OBJ_DIR}
	@${CC} ${CFLAGS} -I${TEST_INC_DIR} -I${MINIRT_INC_DIR} -I${MLX_DIR} -c $< -o $@

.PHONY: all minirt clean fclean re apply_matrix_ops bin_search \
		capped_cone cone_intersect cone_normal \
		capped_cylinder cylinder_intersect cylinder_normal \
		lighting matrix_vec3_multiply quicksort \
		plane ray_transform reflect scene \
		sphere_hit sphere_intersect sphere_normal sphere_transform \
		truncated_cylinder var_array vec3_ops view_transform