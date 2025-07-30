/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:56:56 by amhan             #+#    #+#             */
/*   Updated: 2025/06/07 16:07:42 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_stash(int fd, char *stash);
static char	*join_buffer_to_stash(char *stash, char *buffer);
static char	*extract_line(char *stash);
static char	*stash_update_after_newline(char *stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	remainder = stash_update_after_newline(stash);
	free(stash);
	stash = remainder;
	return (line);
}

static char	*read_and_stash(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = join_buffer_to_stash(stash, buffer);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

static char	*join_buffer_to_stash(char *stash, char *buffer)
{
	char	*tmp;

	if (!stash)
		stash = ft_strdup(buffer);
	else
	{
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = tmp;
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	int		i;
	char	*line;
	char	*newline_ptr;
	int		line_len;

	if (!stash || stash[0] == '\0')
		return (NULL);
	newline_ptr = ft_strchr(stash, '\n');
	if (newline_ptr)
		line_len = (newline_ptr - stash) + 1;
	else
		line_len = ft_strlen(stash);
	line = malloc(line_len + 1);
	i = 0;
	while (i < line_len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*stash_update_after_newline(char *stash)
{
	char	*newline_ptr;
	char	*remainder;

	if (!stash)
		return (NULL);
	newline_ptr = ft_strchr(stash, '\n');
	if (!newline_ptr)
		return (NULL);
	else
		remainder = ft_strdup(newline_ptr + 1);
	return (remainder);
}
