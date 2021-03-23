/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kochi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:00:28 by tayamamo          #+#    #+#             */
/*   Updated: 2021/03/23 10:09:08 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	char		*lastd;
	const char	*lasts;

	d = dst;
	s = src;
	if (d == NULL && s == NULL)
		return (dst);
	if (d < s)
		while (n--)
			*(d++) = *(s++);
	else
	{
		lasts = s + (n - 1);
		lastd = d + (n - 1);
		while (n--)
			*(lastd--) = *(lasts--);
	}
	return (dst);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i])
		i++;
	return (i);
}

int	main(void)
{
	char	*s;
	size_t	n;

	n = ft_strlen("uni ga kirei desu.\n");
	s = malloc(n + 1);
	if (s == NULL)
		return (1);
	ft_memmove(s, "uni ga kirei desu.\n", n);
	s[n] = '\0';
	write(1, s, n);
	free(s);
	return (0);
}
