/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:24:56 by bkwamme           #+#    #+#             */
/*   Updated: 2024/05/01 15:16:01 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>

# define ESC 65307
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define WIDTH 700
# define HEIGHT 700
# define C 99

typedef struct s_fractol
{
	void		*mlx;
	void		*window;
	void		*image;
	void		*img_adr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			x;
	int			y;
	double		zx;
	double		zy;
	double		cx;
	double		cy;
	int			color;
	double		offset_x;
	double		offset_y;
	double		zoom;
	char		name;
	int			max_iterations;
}				t_fractol;

//create_instance
int			destroy_mlx(t_fractol *fractol);
t_fractol	*create_instance(t_fractol *fractol, char **argv,
				double cx, double cy);
void		init_mlx(t_fractol *fractol);
//event_listener
int			mouse_event(int event, int x, int y, t_fractol *fractol);
int			event_listener(int event, t_fractol *fractol);
//draw_fractol
void		draw_julia(t_fractol *fractol);
void		julia_formula(t_fractol *fractol);
void		draw_mandelbrot(t_fractol *fractol);
void		mandelbrot_formula(t_fractol *fractol);
//main
int			draw_fractol(t_fractol *fractol, float cx, float cy);
//ft_atof
double		ft_atof(const char *nptr);

#endif
