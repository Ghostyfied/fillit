/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/13 12:02:59 by awehlbur       #+#    #+#                */
/*   Updated: 2019/02/14 16:47:12 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

int main(int ac, char **av)
{
	int fd;
	t_field temp[27];

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit [filehereplz]\n");
		return (0);
	}
	fd = open(av[1],O_RDONLY);
	bzero(temp, sizeof(t_field) * 27);
	if (fd <= 0)
		return (0);
	ft_count_tetri(fd, temp);
	return (0);
}
