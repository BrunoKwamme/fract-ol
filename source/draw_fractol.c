/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:55:54 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/29 21:55:54 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	put_color_to_pixel(t_fractol *fractol, int x, int y, int color)
{
	int	*buffer;

	buffer = fractol->img_adr;
	buffer[(y * fractol->size_line / 4) + x] = color;
}

void	draw_julia(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < WIDTH)
	{
		while (fractol->y < HEIGHT)
		{
			julia_formula(fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
}

void	julia_formula(t_fractol *fractol)
{
	int		i;
	double	tmp;

	fractol->zx = fractol->x / fractol->zoom + fractol->offset_x;
	fractol->zy = fractol->y / fractol->zoom + fractol->offset_y;
	i = 0;
	while (++i < fractol->max_iterations)
	{
		tmp = fractol->zx;
		fractol->zx = fractol->zx * fractol->zx - fractol->zy
			* fractol->zy + fractol->cx;
		fractol->zy = 2 * fractol->zy * tmp + fractol->cy;
		if (fractol->zx * fractol->zx + fractol->zy
			* fractol->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractol->max_iterations)
		put_color_to_pixel(fractol, fractol->x, fractol->y, 0x000000);
	else
		put_color_to_pixel(fractol, fractol->x, fractol->y, (fractol->color * (i
					% 255)));
}

void	draw_mandelbrot(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->y = 0;
	while (fractol->x < WIDTH)
	{
		while (fractol->y < HEIGHT)
		{
			mandelbrot_formula(fractol);
			fractol->y++;
		}
		fractol->x++;
		fractol->y = 0;
	}
}

void	mandelbrot_formula(t_fractol *fractol)
{
	int		i;
	double	x_temp;

	i = 0;
	fractol->zx = 0.0;
	fractol->zy = 0.0;
	fractol->cx = (fractol->x / fractol->zoom) + fractol->offset_x;
	fractol->cy = (fractol->y / fractol->zoom) + fractol->offset_y;
	while (++i < fractol->max_iterations)
	{
		x_temp = fractol->zx * fractol->zx - fractol->zy * fractol->zy
			+ fractol->cx;
		fractol->zy = 2. * fractol->zx * fractol->zy + fractol->cy;
		fractol->zx = x_temp;
		if (fractol->zx * fractol->zx + fractol->zy
			* fractol->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractol->max_iterations)
		put_color_to_pixel(fractol, fractol->x, fractol->y, 0x000000);
	else
		put_color_to_pixel(fractol, fractol->x, fractol->y, (fractol->color
				* i));
}
