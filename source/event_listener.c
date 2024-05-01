/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:23:32 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/30 19:08:14 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom(t_fractol *fractol, int x, int y, int event)
{
	double	zoom;

	zoom = 1.20;
	if (event == SCROLL_UP)
	{
		fractol->offset_x = (x / fractol->zoom + fractol->offset_x)
			- (x / (fractol->zoom * zoom));
		fractol->offset_y = (y / fractol->zoom + fractol->offset_y)
			- (y / (fractol->zoom * zoom));
		fractol->zoom *= zoom;
	}
	else if (event == SCROLL_DOWN)
	{
		fractol->offset_x = (x / fractol->zoom + fractol->offset_x)
			- (x / (fractol->zoom / zoom));
		fractol->offset_y = (y / fractol->zoom + fractol->offset_y)
			- (y / (fractol->zoom / zoom));
		fractol->zoom /= zoom;
	}
}

int	mouse_event(int event, int x, int y, t_fractol *fractol)
{
	if (event == SCROLL_UP)
		zoom(fractol, x, y, SCROLL_UP);
	else if (event == SCROLL_DOWN)
		zoom(fractol, x, y, SCROLL_DOWN);
	draw_fractol(fractol, fractol->cx, fractol->cy);
	return (0);
}

int	event_listener(int event, t_fractol *fractol)
{
	if (event == ESC)
	{
		destroy_mlx(fractol);
		return (0);
	}
	else if (event == ARROW_UP)
		fractol->offset_y -= 20 / fractol->zoom;
	else if (event == ARROW_DOWN)
		fractol->offset_y += 20 / fractol->zoom;
	else if (event == ARROW_LEFT)
		fractol->offset_x -= 20 / fractol->zoom;
	else if (event == ARROW_RIGHT)
		fractol->offset_x += 20 / fractol->zoom;
	else if (event == C)
		fractol->color *= 255;
	draw_fractol(fractol, fractol->cx, fractol->cy);
	return (0);
}
