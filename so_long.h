/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:58:47 by jofernan          #+#    #+#             */
/*   Updated: 2021/10/15 19:40:08 by jofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_solong
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		imgx;
	int		imgy;
	int		tall;
	int		wide;
	char	**map;
	int		pjx;
	int		pjy;
	int		exitx;
	int		exity;
	int		collectables;
	int		collected;
	int		moves;
	char	*pjfile;
	char	*exitfile;
	char	*gf;
	char	*wf;
	char	*mf;
	int		exitcheck;
	int		pjcheck;
}				t_solong;

void	map_check(char *map_name, t_solong *map);
int		ft_errors(int argc, t_solong *data);
void	ft_map(t_solong *data);
void	ft_getdata(t_solong *data);
int		ft_moveforward(t_solong *data);
int		ft_movedown(t_solong *data);
int		ft_moveleft(t_solong *data);
int		ft_moveright(t_solong *data);

#endif
