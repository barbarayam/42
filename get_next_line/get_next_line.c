/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:06:49 by bayam             #+#    #+#             */
/*   Updated: 2025/08/24 20:01:57 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*read_buffer(int fd, int *bytes_read);
static char		*read_to_stash(int fd, char *stash);
static char		*extract_line(char *stash);
static char		*update_stash(char *stash);

static char	*read_buffer(int fd, int *bytes_read)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[*bytes_read] = '\0';
	return (buffer);
}

static char	*read_to_stash(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;
	char	*temp;

	bytes_read = 1;
	while (!stash || !ft_strchr(stash, '\n'))
	{
		buffer = read_buffer(fd, &bytes_read);
		if (!buffer)
			break ;
		temp = ft_strjoin(stash, buffer);
		free(buffer);
		if (!temp)
		{
			free(stash);
			return (NULL);
		}
		stash = temp;
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc (i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc (ft_strlen(stash) - i);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = update_stash(stash);
	if (!line)
	{
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
	}
	return (line);
}
