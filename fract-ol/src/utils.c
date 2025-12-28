/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:11:34 by bayam             #+#    #+#             */
/*   Updated: 2025/12/26 15:11:37 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx_app.h"

double		ft_atof(char *s);
int			ft_strcmp(char *s1, char *s2);
void		adjust_zoom(t_data *data, double factor);
t_complex	complex_square(t_complex z);
int			is_valid_num(char *s);

t_complex	complex_square(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

void	adjust_zoom(t_data *data, double factor)
{
	data->zoom *= factor;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	is_valid_num(char *s)
{
	int	dot;
	int	i;

	dot = 0;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i] | (s[i] == '.' && !s[i + 1]))
		return (0);
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (dot++)
				return (0);
		}
		else if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

double	ft_atof(char *s)
{
	double	res;
	double	div;
	int		sign;

	res = 0.0;
	div = 1.0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign = -1;
	}
	while (*s >= '0' && *s <= '9')
		res = res * 10 + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s++ - '0');
		div *= 10;
	}
	return (sign * res / div);
}
