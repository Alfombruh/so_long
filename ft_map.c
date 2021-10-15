/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:33:29 by jofernan          #+#    #+#             */
/*   Updated: 2021/10/15 17:56:22 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_windowput(t_solong *s, char c)
{
	s->img = mlx_xpm_file_to_image(s->mlx, s->gf, &s->imgx, &s->imgy);
	mlx_put_image_to_window(s->mlx, s->win, s->img, s->x * 64, s->y * 64);
	if (c == '1')
	{
		s->img = mlx_xpm_file_to_image(s->mlx, s->wf, &s->imgx, &s->imgy);
		mlx_put_image_to_window(s->mlx, s->win, s->img, s->x * 64, s->y * 64);
	}
	if (c == 'C')
	{
		s->img = mlx_xpm_file_to_image(s->mlx, s->mf, &s->imgx, &s->imgy);
		mlx_put_image_to_window(s->mlx, s->win, s->img, s->x * 64, s->y * 64);
	}
	if (c == 'P')
	{
		s->img = mlx_xpm_file_to_image(s->mlx, s->pjfile, &s->imgx, &s->imgy);
		mlx_put_image_to_window(s->mlx, s->win, s->img, s->x * 64, s->y * 64);
	}
	if (c == 'E')
	{
		s->img = mlx_xpm_file_to_image(s->mlx, s->exitfile, &s->imgx, &s->imgy);
		mlx_put_image_to_window(s->mlx, s->win, s->img, s->x * 64, s->y * 64);
	}
	mlx_string_put(s->mlx, s->win, (s->wide * 64) / 2, (s->tall * 64) + 16,
		0x9C9C9C, ft_itoa(s->moves));
}

static void	ft_printmap(t_solong *data)
{
	int	i;
	int	j;

	i = 0;
	if (data->collectables == data->collected)
		data->exitfile = "./tiles/exit2.xpm";
	while (i < data->tall)
	{
		j = 0;
		while (j < data->wide)
		{
			data->y = i;
			data->x = j;
			ft_windowput(data, data->map[i][j]);
			j++;
		}
		i++;
	}
}

static int	ft_movements(int keycode, t_solong *data)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{	
		mlx_clear_window(data->mlx, data->win);
		if (keycode == 13)
			data->moves += ft_moveforward(data);
		if (keycode == 0)
			data->moves += ft_moveleft(data);
		if (keycode == 1)
			data->moves += ft_movedown(data);
		if (keycode == 2)
			data->moves += ft_moveright(data);
		ft_printmap(data);
		printf("TOTAL MOVES: %d\n", data->moves);
	}
	else if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (1);
	}
	else
		printf("movement keys are WASD\n");
	return (0);
}

static int	ft_close(t_solong *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit (1);
	return (0);
}

void	ft_map(t_solong *data)
{
	data->moves = 0;
	data->collected = 0;
	data->pjfile = "./tiles/anthony.xpm";
	data->exitfile = "./tiles/exit.xpm";
	data->gf = "./tiles/grass.xpm";
	data->mf = "./tiles/money.xpm";
	data->wf = "./tiles/wall.xpm";
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (64 * data->wide),
			(64 * data->tall) + 32, "MARIO BROS 2");
	ft_printmap(data);
	mlx_hook(data->win, 2, 1L << 0, ft_movements, data);
	mlx_hook(data->win, 17, 0L << 0, ft_close, data);
	mlx_loop(data->mlx);
}	
