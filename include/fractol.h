/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:24:56 by bkwamme           #+#    #+#             */
/*   Updated: 2024/04/29 17:27:20 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include <math.h>


itypedef struct s_fractol
{
    void    *mlx;
    void    *window;
    void    *image;
    void    *img_adr;
    int        bits_per_pixel;
    int        size_line;
    int        endian;
    int        x;
    int        y;
    double    zx;
    double    zy;
    double    cx;
    double    cy;
    int        color;
    double    offset_x;
    double    offset_y;
    double    zoom;
    char    *name;
    int        max_iterations;
}            t_fractol;

#endif
