/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:22:31 by gifulvi           #+#    #+#             */
/*   Updated: 2022/04/26 13:32:04 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	lenght(int nb, int base)
{
	int	count;

	count = 0;
	if (nb <= 0)
		++count;
	while (nb && ++count)
		nb /= base;
	return (count);
}

char	*ft_itoa(int nb)
{
	int			len;
	char		*str;
	const char	*digits = "0123456789";

	len = lenght(nb, 10);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = 0;
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
		str[0] = '-';
	while (nb)
	{
		if (nb > 0)
			str[--len] = digits[nb % 10];
		else
			str[--len] = digits[nb % 10 * -1];
		nb /= 10;
	}
	return (str);
}

void	read_all_file(int fd, t_game *g)
{
	char	temp[999999];
	char	*all_file;
	char	buffer[1];
	int		i;

	i = 0;
	temp[i] = 0;
	if (fd == -1)
		exit(0);
	while (read(fd, buffer, 1) == 1)
	{
		temp[i] = buffer[0];
		temp[i + 1] = '\0';
		if (!temp[i])
			break ;
		i++;
	}
	all_file = malloc(i + 1);
	i = -1;
	while (temp[++i])
		all_file[i] = temp[i];
	get_rows(&(g->map), all_file);
	get_columns(&(g->map), all_file);
}

void	helper(char *new_a, int i)
{
	if (new_a[i - 1] == '\n')
		new_a[i - 1] = '\0';
	new_a[i] = '\0';
}

char	*get_next_line(int fd)
{
	char	a[999999];
	char	buffer[1];
	char	*new_a;
	int		i;

	i = 0;
	a[i] = 0;
	while (read(fd, buffer, 1) == 1)
	{
		a[i] = buffer[0];
		a[i + 1] = '\0';
		if (a[i] == '\n' || !a[i])
			break ;
		i++;
	}
	if (!a[0])
		return (NULL);
	new_a = malloc(i + 1);
	if (!new_a)
		return (NULL);
	i = -1;
	while (a[++i])
		new_a[i] = a[i];
	helper(new_a, i);
	return (new_a);
}
