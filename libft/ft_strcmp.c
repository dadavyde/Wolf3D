/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 21:13:43 by dadavyde          #+#    #+#             */
/*   Updated: 2017/11/04 21:13:45 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				idx;
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char*)s1;
	s2_cpy = (unsigned char*)s2;
	idx = 0;
	while (s1_cpy[idx] != '\0' && s1_cpy[idx] == s2_cpy[idx])
		idx++;
	return (s1_cpy[idx] - s2_cpy[idx]);
}
