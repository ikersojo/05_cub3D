/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:13:33 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/04 13:14:13 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION:
The function returns the min value of the integers provided as arguments.
---------------------------------------------------------------------------- */
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
