/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:36:12 by jofernan          #+#    #+#             */
/*   Updated: 2021/10/15 18:18:57 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	ft_maperror(char **map, int wide, int tall)
{
	int	i;
	int	j;

	i = 0;
	while (i < tall)
	{
		j = 0;
		while (j < wide)
		{
			if (map[i][0] != '1' || map[i][wide - 1] != '1')
			{
				printf("ERROR\nMap is missing a wall\n");
				return (0);
			}
			if (map[0][j] != '1' || map[tall - 1][j] != '1')
			{
				printf("ERROR\nMap is missing a wall\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_data(t_solong data)
{
	if (data.pjcheck == 0)
	{
		printf("ERROR\nThere is no player in the map file\n");
		return (0);
	}
	if (data.exitcheck == 0)
	{
		printf("ERROR\nThere is no exit in the map file\n");
		return (0);
	}
	if (data.collectables == 0)
	{
		printf("ERROR\nThere are no collectables in the map file\n");
		return (0);
	}
	return (1);
}

int	ft_errors(int argc, t_solong *data)
{
	if (argc < 2 || argc > 2)
	{
		printf("ERROR\n");
		printf("You need to enter a map to play\ntry typing\t/solong maps/...\n");
		return (0);
	}
	if (ft_data(*data) == 0)
		return (0);
	if (ft_maperror(data->map, data->wide, data->tall) == 0)
		return (0);
	return (1);
}
