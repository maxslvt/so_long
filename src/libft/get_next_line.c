/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:25:52 by msolet-l          #+#    #+#             */
/*   Updated: 2025/03/06 16:26:08 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strjoinlst(t_list **s1, char const *s2)
{
	size_t	i;
	t_list	*temp;
	char	*jsp;

	i = 0;
	while (*s1 && (*s1)->next != NULL)
		s1 = &(*s1)->next;
	while (s2 && s2[i])
	{
		jsp = malloc(sizeof(char));
		if (!jsp)
			return (0);
		jsp[0] = s2[i];
		temp = ft_lstnew(jsp);
		if (!temp)
			return (0);
		if (*s1)
			(*s1)->next = temp;
		else
			(*s1) = temp;
		s1 = &(*s1)->next;
		i++;
	}
	return (1);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

int	ft_strchr2(const t_list *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s)
	{
		if (*(char *)s->content == (char)c)
			return (i);
		i++;
		s = s->next;
	}
	return (-1);
}

char	*ft_line_cleaner(t_list **s)
{
	int		len;
	char	*line;
	int		i;
	t_list	*temp;

	len = ft_strchr2(*s, '\n') + 1;
	if (len <= 0)
		len = ft_lstsize(*s);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (*s != NULL && i < len)
	{
		line[i++] = *(char *)(*s)->content;
		temp = (*s);
		*s = (*s)->next;
		free(temp->content);
		free(temp);
	}
	line[len] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static t_list	*stash;
	long long		n;

	if (!stash)
		stash = NULL;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	n = 1;
	while ((ft_strchr2(stash, '\n') == -1) && n > 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buff[n] = '\0';
		if (!ft_strjoinlst(&stash, buff))
			return (NULL);
	}
	free(buff);
	if (stash == NULL)
		return (NULL);
	return (ft_line_cleaner(&stash));
}
