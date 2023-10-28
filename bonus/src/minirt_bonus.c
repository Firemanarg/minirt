/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 01:40:44 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/27 11:49:16 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "graphics_bonus.h"
#include "parser_bonus.h"
#include "error_bonus.h"
#include "shading_bonus.h"

static int	check_usage(int argc);
static int	parse_and_check_scene(t_args *args, char *file_name);
static int	render_and_check_image(t_args *args);

int	main(int argc, char **argv)
{
	t_args	args;

	args = (t_args){0};
	minirt_title();
	if (check_usage(argc))
		return (!baracapy());
	if (parse_and_check_scene(&args, argv[1]))
		return (!baracapy());
	init_args(&args);
	if (render_and_check_image(&args))
		return (!baracapy());
	free_scene(args.scene);
	create_window(&args);
	return (baracapy());
}

static int	check_usage(int argc)
{
	if (argc != 2)
	{
		print_error("Program", ERR_WRONG_USAGE, 0);
		print_msg("Warning", "Usage: ./miniRT <file.rt>", TXT_COLOR_YELLOW);
		return (1);
	}
	return (0);
}

static int	parse_and_check_scene(t_args *args, char *file_name)
{
	args->scene = parse_file(file_name);
	if (args->scene == NULL)
	{
		print_error("Parsing", ERR_PARSING_FILE, 0);
		print_msg("Warning", "File could not be parsed", TXT_COLOR_YELLOW);
		return (1);
	}
	else
		print_msg("Parsing", "Successfully parsed file", TXT_COLOR_GREEN);
	return (0);
}

static int	render_and_check_image(t_args *args)
{
	t_err	err;

	err = render_image(args->scene, &args->mlx_data);
	if (err != OK)
	{
		print_error("Rendering", ERR_RENDERING, 0);
		print_msg("Warning", "Image could not be rendered", TXT_COLOR_YELLOW);
		return (1);
	}
	return (0);
}
