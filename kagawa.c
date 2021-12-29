/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kagawa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snara <snara@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:40:38 by snara             #+#    #+#             */
/*   Updated: 2021/12/29 18:02:31 by snara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(char const *s, int c)
{
	while (*s && *s != (char)c)
		++s;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

ssize_t	ft_put_udon(char *s)
{
	ssize_t	i = 0;

	while (s[i])
	{
		if (ft_strchr("udonUDON", s[i]))
			write(1, "\n", 1);
		write(1, &s[i], 1);
		++i;
	}
	return i;
}

int	main()
{
	ft_put_udon("udon oishii\n");
	return (0);
}
