/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:07:03 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/12 13:09:40 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_load(t_list *g)
{
	char	*tab;

	tab = NULL;
	while (get_strchr(tab, '\n') == 0)
	{
		g->len = read(g->fd, g->tabs, 1);
		g->tabs[g->len] = '\0';
		if (g->len < 0)
			return (NULL);
		if (g->len == 0)
			return (tab);
		g->temp = tab;
		tab = get_strjoin(g->temp, g->tabs);
		free(g->temp);
		if (g->tabs[0] == '\n')
			break ;
	}
	return (tab);
}

char	*get_next_line(int fd)
{
	static char	*tab;
	t_list		main;

	tab = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	main.fd = fd;
	main.tabs = (char *)malloc(sizeof(char) * 2);
	if (main.tabs == NULL)
		return (NULL);
	tab = get_load(&main);
	free(main.tabs);
	return (tab);
}

/* taille des structures !!!
 * test des size de 1 à 10 000 000 ok
 * fd pointer sur fichiers standart ou entrées standart !!!
*/
