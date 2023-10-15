/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parser_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:21:53 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/10/07 15:21:53 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_test.h"

Test(camera_parser, zeros)
{
	t_camera	*camera;

	camera = (t_camera *) parse_line("C 0,0,0 0,0,1 70");
	cr_expect(eq(int, camera->type, CAMERA));
	cr_expect(eq(dbl, camera->pos.x, 0.0));
	cr_expect(eq(dbl, camera->pos.y, 0.0));
	cr_expect(eq(dbl, camera->pos.z, 0.0));
	cr_expect(eq(dbl, camera->dir.x, 0.0));
	cr_expect(eq(dbl, camera->dir.y, 0.0));
	cr_expect(eq(dbl, camera->dir.z, 1.0));
	cr_expect(eq(int, camera->fov, 70));
	free(camera);
}

Test(camera_parser, negative_values)
{
	t_camera	*camera;

	camera = (t_camera *) parse_line("C -42,-42,-42 0,0,1 70");
	cr_expect(eq(int, camera->type, CAMERA));
	cr_expect(eq(dbl, camera->pos.x, -42.0));
	cr_expect(eq(dbl, camera->pos.y, -42.0));
	cr_expect(eq(dbl, camera->pos.z, -42.0));
	cr_expect(eq(dbl, camera->dir.x, 0.0));
	cr_expect(eq(dbl, camera->dir.y, 0.0));
	cr_expect(eq(dbl, camera->dir.z, 1.0));
	cr_expect(eq(int, camera->fov, 70));
	free(camera);
}

Test(camera_parser, wrong_dir)
{
	t_camera	*camera;

	camera = (t_camera *) parse_line("C 0,0,0 0,0,42 70");
	cr_expect(eq(camera, NULL));
	if (camera)
		free(camera);
}

Test(camera_parser, more_fields)
{
	t_camera	*camera;

	camera = (t_camera *) parse_line("C 0,0,0 0,0,1 70 42");
	cr_expect(eq(camera, NULL));
	if (camera)
		free(camera);
}

Test(camera_parser, less_fields)
{
	t_camera	*camera;

	camera = (t_camera *) parse_line("C 0,0,0 0,0,1");
	cr_expect(eq(camera, NULL));
	if (camera)
		free(camera);
}

Test(camera_parser, negative_fov)
{
	t_camera	*camera;

	camera = (t_camera *) parse_line("C 0,0,0 0,0,1 -70");
	cr_expect(eq(camera, NULL));
	if (camera)
		free(camera);
}

Test(camera_parser, wrong_chars_in_pos)
{
	t_camera	*camera;

	camera = (t_camera *) parse_line("C 0a,0a,0a 0,0,1 70");
	cr_expect(eq(camera, NULL));
	if (camera)
		free(camera);
}

Test(camera_parser, wrong_chars_in_dir)
{
	t_camera	*camera;

	camera = (t_camera *) parse_line("C 0,0,0 0a,0a,1a 70");
	cr_expect(eq(camera, NULL));
	if (camera)
		free(camera);
}

Test(camera_parser, wrong_chars_in_fov)
{
	t_camera	*camera;

	camera = (t_camera *) parse_line("C 0,0,0 0a,0a,1a 70x");
	cr_expect(eq(camera, NULL));
	if (camera)
		free(camera);
}
