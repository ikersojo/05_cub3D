/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:37:26 by mvalient          #+#    #+#             */
/*   Updated: 2022/10/05 08:53:47 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		if (s[i] == (c % 256))
			return ((char *)&s[i]);
	}
	if (s[i] == (c % 256))
		return ((char *)&s[i]);
	return (NULL);
}

int	ft_count_until(int n, const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == n)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*ns;

	if (!s1 && !s2)
		return (NULL);
	len = ft_count_until(0, s1) + ft_count_until(0, s2);
	if (!len)
		return (NULL);
	ns = malloc(len + 1);
	if (!ns)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i])
			ns[i] = s1[i];
	else
		i = 0;
	j = -1;
	while (s2[++j])
		ns[i++] = s2[j];
	ns[i] = '\0';
	free(s1);
	return (ns);
}

void	*ft_free_malloc(void *s)
{
	free(s);
	return (NULL);
}

char	*ft_gnl_strdup(char *ntf, const char *s)
{
	int		i;
	int		j;
	char	*news;

	if (!ft_gnl_strchr(ntf, '\n'))
		return (ft_free_malloc(ntf));
	i = ft_count_until(0, s) + 1;
	if (i == 1)
		return (ft_free_malloc(ntf));
	news = malloc(i);
	j = 0;
	if (!news)
		return (NULL);
	while (i--)
	{
		news[j] = s[j];
		j++;
	}
	free(ntf);
	return (news);
}
