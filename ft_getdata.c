/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:40:30 by jofernan          #+#    #+#             */
/*   Updated: 2021/10/15 17:20:41 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_characterinfo(t_solong *data, int i, int j)
{
	data->pjx = j;
	data->pjy = i;
	data->pjcheck = 1;
}

static void	ft_exitinfo(t_solong *data, int i, int j)
{
	data->exitx = j;
	data->exity = i;
	data->exitcheck = 1;
}

void	ft_getdata(t_solong *data)
{
	int	i;
	int	j;

	i = 0;
	data->collectables = 0;
	while (i < data->tall)
	{
		j = 0;
		while (j < data->wide)
		{
			if (data->map[i][j] == 'P')
				ft_characterinfo(data, i, j);
			if (data->map[i][j] == 'C')
				data->collectables++;
			if (data->map[i][j] == 'E')
				ft_exitinfo(data, i, j);
			j++;
		}
		i++;
	}
}
