#include <minirt_test.h>

Test(tuple, test_tuple_is_point) {
	t_tuple	*p = new_tuple(4.3, -4.2, 3.1, 1.0);
	cr_expect(is_point(p) == TRUE, "p is a point");
	cr_expect(is_vector(p) == FALSE, "p is not a vector");
	free(p);
}

Test(tuple, test_tuple_is_vector) {
	t_tuple	*v = new_tuple(4.3, -4.2, 3.1, 0.0);
	cr_expect(is_point(v) == FALSE, "p is not a point");
	cr_expect(is_vector(v) == TRUE, "p is a vector");
	free(v);
}

Test(tuple, test_new_vector_is_correct_tuple) {
	t_tuple	*v = new_vector(4, -4, 3);
	cr_expect(epsilon_eq(dbl, v->x, 4.0, EPSILON));
	cr_expect(epsilon_eq(dbl, v->y, -4.0, EPSILON));
	cr_expect(epsilon_eq(dbl, v->z, 3.0, EPSILON));
	cr_expect(epsilon_eq(dbl, v->w, 0.0, EPSILON));
	free(v);
}

Test(tuple, test_new_point_is_correct_tuple) {
	t_tuple	*p = new_point(4, -4, 3);
	cr_expect(epsilon_eq(dbl, p->x, 4.0, EPSILON));
	cr_expect(epsilon_eq(dbl, p->y, -4.0, EPSILON));
	cr_expect(epsilon_eq(dbl, p->z, 3.0, EPSILON));
	cr_expect(epsilon_eq(dbl, p->w, 1.0, EPSILON));
	free(p);
}
