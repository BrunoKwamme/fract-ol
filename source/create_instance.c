/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:34:08 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/29 18:34:08 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_c(t_fractol *fractol, double cx, double cy)
{
	if (cx == -3 || cy == -3)
	{
		fractol->cx = -0.745429;
		fractol->cy = 0.05;
	}
	fractol->cx = cx;
	fractol->cy = cy;
}

int	destroy_mlx(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->image);
	mlx_destroy_window(fractol->mlx, fractol->window);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	free(fractol);
	ft_printf("The program was successfully closed !\n");
	exit (1);
	return (0);
}

t_fractol	*create_instance(t_fractol *fractol,
char **argv, double cx, double cy)
{
	fractol = ft_calloc(sizeof(t_fractol), 1);
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0
		|| ft_strncmp(argv[1], "julia", 6) == 0)
		fractol->name = argv[1];
	else
		return (NULL);
	check_c(fractol, cx, cy);
	fractol->mlx = mlx_init();
	fractol->window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, argv[1]);
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->img_adr = mlx_get_data_addr(fractol->image,
			&fractol->bits_per_pixel, &fractol->size_line, &fractol->endian);
	fractol->color = 0x08CF10A ;
	fractol->zoom = 200;
	fractol->x = 0;
	fractol->y = 0;
	fractol->offset_x = -1.80;
	fractol->offset_y = -1.80;
	fractol->max_iterations = 69;
	return (fractol);
}
