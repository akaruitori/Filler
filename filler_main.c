/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtimeon <dtimeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:47:33 by dtimeon           #+#    #+#             */
/*   Updated: 2019/08/30 20:46:40 by dtimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			filler(void)
{
	char	*line;
	int		success_read_flag;
	// size_t	line_len;

	// if ((success_read_flag = get_next_line(STDIN_FILENO, &line)) >= 0)
	// {
		// line_len = ft_strlen(line);
		// write(1, "Success\n", 8);
		// write(1, line, line_len);
		success_read_flag = 0;
		while (get_next_line(STDIN_FILENO, &line) > 0)
		{
			if (ft_strequ(line, "**"))
				break;
			success_read_flag++;
		}
		write(1, "8 2", 3);
	// }
	// if (success_read_flag < 0)
		// return (0);
	return (1);

}

int			main(void)
{
	if (!filler())
	{
		perror("An error occured in filler function: ");
		return (1);
	}
	return (0);
}