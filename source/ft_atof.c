/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwamme <bkwamme@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:02:20 by bkwamme           #+#    #+#             */
/*   Updated: 2024/05/01 10:44:47 by bkwamme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	decimal_atof(const char *nptr, int i)
{
	int		flag;
	double	temp;

	temp = 0;
	flag = 1;
	while (nptr[++i] >= '0' && nptr[i] <= '9')
	{
		temp = (temp * 10 + nptr[i] - 48);
		flag *= 10;
	}
	temp /= flag;
	return (temp);
}

int	check_signal(const char *nptr, int i)
{
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			return (1);
	}
	return (0);
}

double	ft_atof(const char *nptr)
{
	double	atof;
	int		i;
	int		m;

	atof = 0;
	i = 0;
	m = 0;
	while (nptr[i] == 32 || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	m += check_signal(nptr, i);
	if (m == 1)
		i++;
	while ((nptr[i] >= '0' && nptr[i] <= '9') || nptr[i] == '.')
	{
		if (nptr[i] == '.')
		{
			atof += decimal_atof(nptr, i);
			break ;
		}
		atof = atof * 10 + (nptr[i] - 48);
		i++;
	}
	if (m == 1)
		return (-atof);
	return (atof);
}
