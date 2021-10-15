/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moveright.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:32:42 by jofernan          #+#    #+#             */
/*   Updated: 2021/10/13 16:33:06 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ft_moveright(t_solong *data)
{
	data->pjfile = "./tiles/right.xpm";
	if (data->map[data->pjy][data->pjx + 1] != '1')
	{
		if (data->map[data->pjy][data->pjx + 1] == 'C')
		{	
			data->collected++;
			printf("COLLECTED: %d/%d\n", data->collected, data->collectables);
		}
		if (data->map[data->pjy][data->pjx + 1] == 'E')
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
		data->map[data->pjy][data->pjx + 1] = 'P';
		data->pjx++;
	}
	else
		return (0);
	return (1);
}
