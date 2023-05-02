/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:59:32 by thibnguy          #+#    #+#             */
/*   Updated: 2023/05/02 17:32:20 by thibnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_free_matrix(t_matrix mat)
{
	int	i;

	i = -1;
	while (i < mat.rows)
		free(mat.matrix[i]);
	free(mat.matrix);
}
