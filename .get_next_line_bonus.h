/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:35:03 by pwolff            #+#    #+#             */
/*   Updated: 2022/03/12 13:10:03 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	int		len;
	char	*temp;
	char	*tabs;
	int		fd;
}		t_list;

char	*get_next_line(int fd);
char	*get_strjoin(char const *s1, char const *s2);
size_t	get_strchr(const char *s, int c);

#endif
