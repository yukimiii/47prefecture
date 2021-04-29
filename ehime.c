/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ehime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:57:08 by tayamamo          #+#    #+#             */
/*   Updated: 2021/04/01 16:02:26 by tayamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return(i);
	while(s[i])
		i++;
	return (i);
}

int	main(void)
{
	write(1, "shuuzen chu.\n", ft_strlen("shuuzen chu.\n"));
	return (0);
}
