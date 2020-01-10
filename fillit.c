/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/13 12:17:06 by awehlbur       #+#    #+#                */
/*   Updated: 2019/02/14 16:55:59 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_calc_coordinate(const char *str, char f[4])
{
	int			i;
	t_field		s1;

	i = 0;
	f[0] = 3;
	f[1] = 3;
	f[2] = 0;
	f[3] = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i % 5 < f[0])
				f[0] = i % 5;
			if (i / 5 < f[1])
				f[1] = i / 5;
			if (i % 5 > f[2])
				f[2] = i % 5;
			if (i / 5 > f[3])
				f[3] = i / 5;
		}
		i++;
	}
}

t_field			ft_get_tetri(const char *str, const char curr)
{
	int			h1;
	int			l1;
	t_field 	field;
	char		f[4];

	ft_calc_coordinate(str, f);
	field.w = f[2] - f[0] + 1;
	field.h = f[3] - f[1] + 1;
	field.coor = curr;
	printf("test honderd: %c\n", field.coor);
	field.v = 0;
	field.last = NULL;
	h1 = 0;
	while (h1 < field.h)
	{
		l1 = 0;
		while (l1 < field.w)
		{
			if (str[(f[0] + l1) + (f[1] + h1) * 5] == '#')
			{
				ft_putstr("halo\n");
				field.v |= (1L << (16 * (h1 + 1) - 1 - l1));
				printf("test1: %d\n", field.w);
			}
			l1++;
		}
		h1++;
	}
	return (field);
}
int			ft_check_valid_block(char *str)
{
	int		i;
	int		k;

	k = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i + 1 < 20 && str[i + 1] == '#')
				k++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				k++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				k++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				k++;
		}
		i++;
	}
	if (k == 6 || k == 8)
		return (1);
	return (0);
}

int			ft_check_grid(char *str, int count)
{
	int		i;
	int		k;
	int		x;

	i = 0;
	k = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] != '#' || str[i] != '.'))
				return (1);
			if (str[i] == '#' && ++k > 4)
				return (1);
		}
		else if (str[i] != '\n')
			return (1);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (1);
	x = ft_check_valid_block(str);
	if (x != 1)
		return (1);
	return (0);
}

int			ft_count_tetri(int fd, t_field *str)
{
	char	buf[22];
	char	curr;
	int		i;
	int		k;
	int		count;
	t_field field;

	curr = 'A';
	i = 0;
	while ((count = read(fd, buf, 21)) >= 20)
	{

		if (ft_check_grid(buf, count) != 0)
			{
				printf("test lul: %d\n", field.h);
				ft_putstr("that went wrong\n");
				return (0);
			}
		ft_get_tetri(buf, curr);
		curr++;
	}
	if (count != 0)
		return (0);
	return (curr);
}
