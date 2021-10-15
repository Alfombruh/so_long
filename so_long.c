/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:56:44 by jofernan          #+#    #+#             */
/*   Updated: 2021/10/15 19:09:13 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_solong	data;

	map_check(argv[1], &data);
	ft_getdata(&data);
	if (ft_errors(argc, &data) == 0)
		return (0);
	ft_map(&data);
	return (0);
}
