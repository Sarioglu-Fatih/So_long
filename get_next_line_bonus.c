/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsariogl <fsariogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:52:20 by fsariogl          #+#    #+#             */
/*   Updated: 2022/03/24 18:45:52 by fsariogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes_bonus/so_long_bonus.h"

int	ft_strlennl(char *str, int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		while (str[i] != '\0')
			i++;
		return (i);
	}
	else
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		return (i);
	}
	return (-1);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*str;

	i = 0;
	while (s1[i] != '\0' && s1[i - 1] != '\n')
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && s1[i - 1] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	if (str[0] == '\0')
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	i = ft_strlennl(s1, 0);
	j = ft_strlennl(s2, 1);
	str = malloc(sizeof(char) * (i + j + 2));
	if (!str)
		return (NULL);
	j = -1;
	while (s1[++j] != '\0')
		str[j] = s1[j];
	i = 0;
	str[j] = 'a';
	while (s2[i] != '\0' && s2[i - 1] != '\n')
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

void	raz(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlennl(buff, 1);
	if (buff[j] != '\0')
	{
		j++;
		while (buff[j] != '\0')
		{
			buff[i] = buff[j];
			i++;
			j++;
		}
		while (i < j)
		{
			buff[i] = '\0';
			i++;
		}
	}
}

char	*get_next_line(int fd)
{
	int			i;
	int			j;
	char		*str;
	static char	buff[BUFFER_SIZE + 1];

	i = 0;
	j = 1;
	if (fd < 0)
		return (NULL);
	str = ft_strdup(buff);
	while (j > 0 && buff[i] != '\n')
	{
		i = 0;
		while (buff[i] != '\0' && buff[i] != '\n' && i < BUFFER_SIZE)
			i++;
		if (buff[i] != '\n')
		{
			j = read(fd, buff, BUFFER_SIZE);
			buff[j] = '\0';
			str = ft_strjoin(str, buff);
		}
	}
	raz(buff);
	return (str);
}
