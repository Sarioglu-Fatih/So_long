/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:00:08 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/25 14:56:06 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

static char	*ft_itoas(int n, char *str, long long int nb, int count)
{
	if (n < 0)
		str[0] = '-';
	str[count] = '\0';
	nb = n;
	if (nb < 0)
		nb = nb * -1;
	count--;
	if (n == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[count] = (nb % 10) + '0';
		nb = nb / 10;
		count--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	long long int	nb;
	int				count;

	count = 0;
	nb = (long long int)n;
	if (n == 0)
		count++;
	if (n < 0)
		count++;
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	return (ft_itoas(n, str, nb, count));
}
