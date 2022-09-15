/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:01:46 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/16 10:50:14 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	get_load(t_list *g)
{
	g->len = read(g->fd, g->post, BUFFER_SIZE);
	if (g->len < 0)
	{
		g->tabs[0] = '\0';
		return ;
	}
	while (g->len > 0)
	{
		g->post[g->len] = '\0';
		g->temp = g->tabs;
		g->tabs = get_strjoin(g->temp, g->post);
		free(g->temp);
		if (g->tabs == NULL)
			return ;
		if (get_strchr(g->post, '\n') != 0)
			return ;
		g->len = read(g->fd, g->post, BUFFER_SIZE);
	}
}

static void	get_split(t_list *g, char *tab)
{
	size_t	len_n;
	size_t	i;

	len_n = get_strchr(g->tabs, '\n');
	if (len_n == 0)
	{
		tab[0] = '\0';
		return ;
	}
	len_n -= 1;
	i = 0;
	while (g->tabs[len_n + i + 1] != '\0')
	{
		tab[i] = g->tabs[len_n + i + 1];
		i++;
	}
	g->tabs[len_n + 1] = '\0';
	tab[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	tab[BUFFER_SIZE + 1];
	t_list		main;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	main.fd = fd;
	main.post = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	main.tabs = get_strjoin("", tab);
	if (main.post == NULL || main.tabs == NULL)
		return (NULL);
	get_load(&main);
	free(main.post);
	if (main.len < 0)
	{
		free(main.tabs);
		return (NULL);
	}
	get_split(&main, tab);
	if (main.len == 0 && tab[0] == '\0' && main.tabs[0] == '\0')
	{
		free(main.tabs);
		return (NULL);
	}
	return (main.tabs);
}

/* taille des structures !!!
 * test des size de 1 à 10 000 000 ok
 * fd pointer sur fichiers standart ou entrées standart !!!
*/
