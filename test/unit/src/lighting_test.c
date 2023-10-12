/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:11:22 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/12 17:50:24 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt_test.h>

static void	get_default_material(t_material *material)
{
	set_material_color(material, 1.0, 1.0, 1.0);
	set_material_coefficients(material, 0.1, 0.9, 0.9);
	set_material_shininess(material, 200.0);
}

static void	pre_lighting(t_material *material, t_color *light_color,
				t_color *amb_lit, t_color *tmp)
{
	hadamard(&material->color, light_color, amb_lit);
	multiply(amb_lit, material->ambient, amb_lit);
	*tmp = material->color;
}

Test(lighting, eye_between_light_and_surface)
{
	t_precomp		p;
	t_color			amb_lit;
	t_color			result;
	t_material		material;
	t_point_light	light;

	get_default_material(&material);
	set_point_light(&(t_vec3){.x = 0, .y = 0, .z = -10},
		&(t_color){.r = 1, .g = 1, .b = 1}, &light);
	p.normal = (t_vec3){.x = 0, .y = 0, .z = -1};
	p.eye = (t_vec3){.x = 0, .y = 0, .z = -1};
	p.point = (t_vec3){.x = 0, .y = 0, .z = 0};
	p.in_shadow = FALSE;
	p.over_point = (t_vec3){.x = 0, .y = 0, .z = 0};
	pre_lighting(&material, &light.color, &amb_lit, &result);
	lighting(&p, &material, &light, &result);
	add(&result, &amb_lit, &result);
	cr_expect(epsilon_eq(dbl, result.r, 1.9, EPSILON));
	cr_expect(epsilon_eq(dbl, result.g, 1.9, EPSILON));
	cr_expect(epsilon_eq(dbl, result.b, 1.9, EPSILON));
}

Test(lighting, eye_between_light_and_surface_eye_45deg)
{
	t_precomp		p;
	t_color			amb_lit;
	t_color			result;
	t_material		material;
	t_point_light	light;

	get_default_material(&material);
	set_point_light(&(t_vec3){.x = 0, .y = 0, .z = -10},
		&(t_color){.r = 1, .g = 1, .b = 1}, &light);
	p.normal = (t_vec3){.x = 0, .y = 0, .z = -1};
	p.eye = (t_vec3){.x = 0, .y = M_SQRT1_2, .z = -M_SQRT1_2};
	p.point = (t_vec3){.x = 0, .y = 0, .z = 0};
	p.in_shadow = FALSE;
	p.over_point = (t_vec3){.x = 0, .y = 0, .z = 0};
	pre_lighting(&material, &light.color, &amb_lit, &result);
	lighting(&p, &material, &light, &result);
	add(&result, &amb_lit, &result);
	cr_expect(epsilon_eq(dbl, result.r, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.g, 1.0, EPSILON));
	cr_expect(epsilon_eq(dbl, result.b, 1.0, EPSILON));
}

Test(lighting, eye_opposite_surface_light_45deg)
{
	t_precomp		p;
	t_color			amb_lit;
	t_color			result;
	t_material		material;
	t_point_light	light;

	get_default_material(&material);
	set_point_light(&(t_vec3){.x = 0, .y = 10, .z = -10},
		&(t_color){.r = 1, .g = 1, .b = 1}, &light);
	p.normal = (t_vec3){.x = 0, .y = 0, .z = -1};
	p.eye = (t_vec3){.x = 0, .y = 0, .z = -1};
	p.point = (t_vec3){.x = 0, .y = 0, .z = 0};
	p.in_shadow = FALSE;
	p.over_point = (t_vec3){.x = 0, .y = 0, .z = 0};
	pre_lighting(&material, &light.color, &amb_lit, &result);
	lighting(&p, &material, &light, &result);
	add(&result, &amb_lit, &result);
	cr_expect(epsilon_eq(dbl, result.r, 0.7364, EPSILON));
	cr_expect(epsilon_eq(dbl, result.g, 0.7364, EPSILON));
	cr_expect(epsilon_eq(dbl, result.b, 0.7364, EPSILON));
}

Test(lighting, eye_in_path_of_reflection_vector)
{
	t_precomp		p;
	t_color			amb_lit;
	t_color			result;
	t_material		material;
	t_point_light	light;

	get_default_material(&material);
	set_point_light(&(t_vec3){.x = 0, .y = 10, .z = -10},
		&(t_color){.r = 1, .g = 1, .b = 1}, &light);
	p.normal = (t_vec3){.x = 0, .y = 0, .z = -1};
	p.eye = (t_vec3){.x = 0, .y = -M_SQRT1_2, .z = -M_SQRT1_2};
	p.point = (t_vec3){.x = 0, .y = 0, .z = 0};
	p.in_shadow = FALSE;
	p.over_point = (t_vec3){.x = 0, .y = 0, .z = 0};
	pre_lighting(&material, &light.color, &amb_lit, &result);
	lighting(&p, &material, &light, &result);
	add(&result, &amb_lit, &result);
	cr_expect(epsilon_eq(dbl, result.r, 1.6364, EPSILON));
	cr_expect(epsilon_eq(dbl, result.g, 1.6364, EPSILON));
	cr_expect(epsilon_eq(dbl, result.b, 1.6364, EPSILON));
}

Test(lighting, light_behind_surface)
{
	t_precomp		p;
	t_color			amb_lit;
	t_color			result;
	t_material		material;
	t_point_light	light;

	get_default_material(&material);
	set_point_light(&(t_vec3){.x = 0, .y = 0, .z = 10},
		&(t_color){.r = 1, .g = 1, .b = 1}, &light);
	p.normal = (t_vec3){.x = 0, .y = 0, .z = -1};
	p.eye = (t_vec3){.x = 0, .y = 0, .z = -1};
	p.point = (t_vec3){.x = 0, .y = 0, .z = 0};
	p.in_shadow = FALSE;
	p.over_point = (t_vec3){.x = 0, .y = 0, .z = 0};
	pre_lighting(&material, &light.color, &amb_lit, &result);
	lighting(&p, &material, &light, &result);
	add(&result, &amb_lit, &result);
	cr_expect(epsilon_eq(dbl, result.r, 0.1, EPSILON));
	cr_expect(epsilon_eq(dbl, result.g, 0.1, EPSILON));
	cr_expect(epsilon_eq(dbl, result.b, 0.1, EPSILON));
}

Test(lighting, point_in_shadow)
{
	t_precomp		p;
	t_color			amb_lit;
	t_color			result;
	t_material		material;
	t_point_light	light;

	get_default_material(&material);
	set_point_light(&(t_vec3){.x = 0, .y = 0, .z = -10},
		&(t_color){.r = 1, .g = 1, .b = 1}, &light);
	p.normal = (t_vec3){.x = 0, .y = 0, .z = -1};
	p.eye = (t_vec3){.x = 0, .y = 0, .z = -1};
	p.point = (t_vec3){.x = 0, .y = 0, .z = 0};
	p.in_shadow = TRUE;
	p.over_point = (t_vec3){.x = 0, .y = 0, .z = 0};
	pre_lighting(&material, &light.color, &amb_lit, &result);
	lighting(&p, &material, &light, &result);
	add(&result, &amb_lit, &result);
	cr_expect(epsilon_eq(dbl, result.r, 0.1, EPSILON));
	cr_expect(epsilon_eq(dbl, result.g, 0.1, EPSILON));
	cr_expect(epsilon_eq(dbl, result.b, 0.1, EPSILON));
}
