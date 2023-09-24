/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:57:56 by gmachado          #+#    #+#             */
/*   Updated: 2023/09/23 16:07:48 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_test.h>

Test(obj_reflect, incident_45deg)
{
	t_vec3	incident = {.x = 1, .y = -1, .z = 0};
	t_vec3	normal = {.x = 0, .y = 1, .z = 0};
	t_vec3	reflected;

	reflect(&incident, &normal, &reflected);
	cr_expect(epsilon_eq(dbl, reflected.x, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, reflected.y,1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, reflected.z, 0.0, EPSILON));
}

Test(obj_reflect, slant_surface)
{
	t_vec3	incident = {.x = 0, .y = -1, .z = 0};
	t_vec3	normal = {.x = M_SQRT1_2, .y = M_SQRT1_2, .z = 0};
	t_vec3	reflected;

	reflect(&incident, &normal, &reflected);
	cr_expect(epsilon_eq(dbl, reflected.x, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, reflected.y, 0.0, EPSILON));
	cr_expect(epsilon_eq(dbl, reflected.z, 0.0, EPSILON));
}