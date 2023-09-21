/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ray_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 02:03:50 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/20 10:18:40 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_test.h>

Test(transform_ray, translate_ray)
{
	t_ray		ray;
	t_ray		result;
	t_matrix	*transform;
	t_vec3		transform_params = {.x = 3, .y = 4, .z = 5};
	t_vec3		start = {.x = 1, .y = 2, .z = 3};
	t_vec3		direction = {.x = 0, .y = 1, .z = 0};

	transform = matrix_translation(&transform_params);
	new_ray(&start, &direction, &ray);
	transform_ray(transform, &ray, &result);
	cr_expect(epsilon_eq(dbl, result.start.x, 4.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.start.y, 6.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.start.z, 8.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.direction.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.direction.y, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.direction.z, 0.0, EPSILON));
	matrix_free(transform);
}

Test(transform_ray, scale_ray)
{
	t_ray		ray;
	t_ray		result;
	t_matrix	*transform;
	t_vec3		transform_params = {.x = 2, .y = 3, .z = 4};
	t_vec3		start = {.x = 1, .y = 2, .z = 3};
	t_vec3		direction = {.x = 0, .y = 1, .z = 0};

	transform = matrix_scaling(&transform_params);
	new_ray(&start, &direction, &ray);
	transform_ray(transform, &ray, &result);
	cr_expect(epsilon_eq(dbl, result.start.x, 2.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.start.y, 6.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.start.z, 12.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.direction.x, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.direction.y, 3.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.direction.z, 0.0, EPSILON));
	matrix_free(transform);
}
