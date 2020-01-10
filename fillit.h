/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/13 12:07:25 by awehlbur       #+#    #+#                */
/*   Updated: 2019/02/14 16:47:38 by rvan-ket      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
#include "./libft/libft.h"

typedef struct				s_field
{
	unsigned long long			v;
	struct t_field				*last;
	unsigned char				content;
	unsigned char				w;
	unsigned char				h;
	unsigned char				coor;
}							t_field;

int			ft_count_tetri(int fd, t_field *str);
#endif
