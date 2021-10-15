/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movefoward.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:30:29 by jofernan          #+#    #+#             */
/*   Updated: 2021/10/13 16:33:58 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ft_moveforward(t_solong *data)
{
	data->pjfile = "./tiles/back.xpm";
	if (data->map[data->pjy - 1][data->pjx] != '1')
	{
		if (data->map[data->pjy - 1][data->pjx] == 'C')
		{
			data->collected++;
			printf("COLLECTED: %d/%d\n", data->collected, data->collectables);
		}
		if (data->map[data->pjy - 1][data->pjx] == 'E')
		{	
			if (data->collected != data->collectables)
				return (0);
			if (data->collected == data->collectables)
			{
				mlx_destroy_window(data->mlx, data->win);
				exit(1);
			}
		}
		data->map[data->pjy][data->pjx] = 0;
		data->map[data->pjy - 1][data->pjx] = 'P';
		data->pjy--;
	}
	else
		return (0);
	return (1);
}
