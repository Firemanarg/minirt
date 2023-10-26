/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 01:40:44 by gmachado          #+#    #+#             */
/*   Updated: 2023/10/15 22:08:39 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "graphics.h"
#include "parser.h"
#include "error.h"
#include "shading.h"

// static void	init(t_args *args, char *file_name);

int	main(int argc, char **argv)
{
	t_args	args;
	// t_err	err;

	args = (t_args){0};
	if (argc != 2)
	{
		print_error("Program", ERR_WRONG_USAGE, 0);
		// printf("Error\nUsage: ./miniRT <file.rt>\n");
		return (1);
	}
	args.scene = parse_file(argv[1]);
	if (args.scene == NULL)
	{
		print_error("Parsing", ERR_PARSING_FILE, 0);
		return (1);
	}
	else
		print_msg("Parsing", "Successfully parsed file", TXT_COLOR_GREEN);
		// printf("[Parsing]: Successfully parsed file\n");
	// init(&args, argv[1]);
	// err = render_image(args.scene, &args.mlx_data);
	// if (err != OK)
	// {
	// 	printf("Error during render\n");
	// 	return (1);
	// }
	free_scene(args.scene);
	// create_window(&args);
	return (0);
}

// static void	init(t_args *args, char *file_name)
// {
// 	args->scene = parse_file(file_name);
// 	if (args->scene == NULL)
// 	{
// 		// printf("Error parsing file\n");
// 		print_error("Parsing", ERR_PARSING_FILE, 0);
// 		exit(1);
// 	}
// 	init_args(args);
// }
