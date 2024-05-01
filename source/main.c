/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:12:32 by bkwamme           #+#    #+#             */
/*   Updated: 2024/05/01 15:25:27 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_error(void)
{
	ft_putstr_fd("\nSó é possível cálcular fractol \
		(mandelbrot) ou (julia)\n", 2);
	ft_putstr_fd("julia aceita dois floats que influenciam\
		 no cálculo do fractol\n", 2);
}

int	draw_fractol(t_fractol *fractol, float cx, float cy)
{
	if (ft_strncmp(fractol->name, "mandelbrot", 11) == 0)
		draw_mandelbrot(fractol);
	else if (ft_strncmp(fractol->name, "julia", 6) == 0)
	{
		fractol->cx = cx;
		fractol->cy = cy;
		draw_julia(fractol);
	}
	else
	{
		print_error();
		destroy_mlx(fractol);
		return (1);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image, 0, 0);
	return (0);
}

int	arg_val(char **argv, double *cx, double *cy)
{
	if ((ft_atof(argv[2]) < -2 || ft_atof(argv[2]) > 2)
		&& (ft_atof(argv[3]) < -2 || ft_atof(argv[3]) > 2))
	{
		ft_putstr_fd("insira um valor entre -2 e 2", 2);
		return (1);
	}
	else
	{
		*cx = ft_atof(argv[2]);
		*cy = ft_atof(argv[3]);
		return (0);
	}
}

void	mlx_operations(t_fractol *fractol, char **argv, int argc)
{
	mlx_mouse_hook(fractol->window, mouse_event, fractol);
	mlx_key_hook(fractol->window, event_listener, fractol);
	if (argc == 2)
		draw_fractol(fractol, -0.745429, 0.05);
	else
		draw_fractol(fractol, ft_atof(argv[2]), ft_atof(argv[3]));
	mlx_hook(fractol->window, 17, 0L, destroy_mlx, fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image, 0, 0);
	mlx_loop(fractol->mlx);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;
	double		cx;
	double		cy;

	cx = -3;
	cy = -3;
	fractol = NULL;
	if (argc != 4 && argc != 2)
	{
		put_error();
		return (1);
	}
	if (argc == 4 && argv[2][0] != '\0' && argv[3][0] != '\0')
	{
		if (arg_val(argv, &cx, &cy) == 1)
		{
			put_error();
			return (1);
		}
	}
	fractol = create_instance(fractol, argv, cx, cy);
	if (!fractol)
		return (1);
	mlx_operations(fractol, argv, argc);
	return (0);
}
