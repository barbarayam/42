/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:02:13 by bayam             #+#    #+#             */
/*   Updated: 2025/12/26 15:31:21 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx_app.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <unistd.h>

int		close_window(t_data *data);
int		handle_keypress(int keysym, t_data *data);
void	init_fractal(t_data *data);
int		handle_mouse(int button, int x, int y, t_data *data);

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	return (0);
}

void	init_fractal(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit(1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	data->zoom = 1.0;
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->size_line, &data->endian);
	mlx_hook(data->win_ptr, DestroyNotify,
		StructureNotifyMask, close_window, data);
	mlx_key_hook(data->win_ptr, handle_keypress, data);
	mlx_mouse_hook(data->win_ptr, handle_mouse, data);
	mlx_hook(data->win_ptr, 12, 0, render_fractal, data);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		adjust_zoom(data, 0.95);
	if (button == 5)
		adjust_zoom(data, 1.05);
	render_fractal(data);
	return (0);
}

int	main(int ac, char *av[])
{
	t_data	data;

	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		|| (ac == 4 && !ft_strcmp(av[1], "julia")))
	{
		data.name = av[1];
		if (ac == 4)
		{
			if (!is_valid_num(av[2]) || !is_valid_num(av[3]))
				return (write(1, "Error:Invalid numbers\n", 23), 1);
			data.julia_x = ft_atof(av[2]);
			data.julia_y = ft_atof(av[3]);
			if (data.julia_x > 2.0 || data.julia_x < -2.0
				|| data.julia_y > 2.0 || data.julia_y < -2.0)
				return (write(1, "Error:Values must be from -2 to 2\n", 36), 1);
		}
		init_fractal(&data);
		render_fractal(&data);
		mlx_loop(data.mlx_ptr);
	}
	else
	{
		write(1, "Usage: ./fractol mandelbrot or julia <x> <y>\n", 46);
	}
	return (0);
}
