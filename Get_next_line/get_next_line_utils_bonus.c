/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleguina <cleguina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:26:10 by cova              #+#    #+#             */
/*   Updated: 2023/06/20 21:20:34 by cleguina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s1;
	size_t			pos;

	pos = 0;
	s1 = (unsigned char *)s;
	while (pos < n)
	{
		s1[pos] = '\0';
		pos++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		len_s2;
	int		len_s1;
	int		i;
	int		j;

	if (!s1)
	{	
		s1 = malloc (1);
		if (!s1)
			return (free(s1), NULL);
		ft_bzero(s1, 1);
	}
	len_s1 = ft_strlen (s1);
	len_s2 = ft_strlen (s2);
	s3 = malloc (sizeof(char) * (len_s1 + len_s2) + 1);
	if (s3 == NULL)
		return (free(s1), NULL);
	i = -1;
	while (++i < len_s1)
		s3[i] = s1[i];
	j = 0;
	while (j <= len_s2)
		s3[i++] = s2[j++];
	return (free (s1), s3);
}

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = c;
	while (*s != '\0')
	{
		if (*s == cc)
			return ((char *)s);
		s++;
	}
	if (cc == '\0')
		return ((char *)s);
	return (NULL);
}

/* char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_length;
	char	*result;
	int		i;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (!s1)
			return (free(s1), s1 = NULL, NULL);
		ft_bzero(s1, 1);
	}
	if (!s1 || !s2)
		return (free(s1), s1 = NULL, NULL);
	s1_length = ft_strlen(s1);
	result = (char *)malloc((s1_length + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (free(s1), s1 = NULL, NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	i = -1;
	while (s2[++i])
		result[s1_length + i] = s2[i];
	result[s1_length + i] = '\0';
	return (free(s1), s1 = NULL, result);
} */
