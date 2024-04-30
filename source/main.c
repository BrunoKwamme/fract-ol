/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:12:32 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/30 01:37:08 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_error(void)
{
	ft_printf("\nSó é possível cálcular fractol (mandelbrot) ou (julia)\n");
	ft_printf("julia aceita dois floats que influenciam no cálculo do fractol\n");
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
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->image, 0, 0);
	return (0);
}

int main(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol = NULL;
	if (argc != 4 && argc != 2)
		return (1);
	fractol = create_instance(fractol, argv);
	mlx_mouse_hook(fractol->window, mouse_event, fractol);
	mlx_key_hook(fractol->window, event_listener, fractol);
	draw_fractol(fractol, -0.745429, 0.05);
	//ft_printf("\n%d\n%d\n%d\n%d\n%d\n%lf\n%lf\n%lf\n%lf\n%d\n%lf\n%lf\n%lf\n%s\n%d\n", fractol->bits_per_pixel, fractol->size_line, fractol->endian,fractol->x, fractol->y,fractol->zx, fractol->zy, fractol->cx, fractol->cy, fractol->color,fractol->offset_x,fractol->offset_y, fractol->name,fractol->max_iterations);
	mlx_hook(fractol->window, 17, 0L, destroy_mlx, fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->image, 0,0);
	mlx_loop(fractol->mlx);
	return (0);
}
