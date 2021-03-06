/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 13:37:29 by eliajin           #+#    #+#             */
/*   Updated: 2018/05/03 09:15:29 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_and(char *line, int index)
{
	char *tmp;
	char **splited;

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	if (ft_strcmp(tmp, "and") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	splited = ft_strsplit(tmp, SEPARATOR_CHAR);
	clear_split(splited);
	if (tab_len(splited) != 3)
		msg_error(ERR_NBR_ARG, index);
	if (isdir(splited[0]) == 0 && isindir(splited[0]) == 0 &&
		isreg(splited[0]) == 0)
		msg_error(ERR_ARG, index);
	if (isdir(splited[1]) == 0 && isindir(splited[1]) == 0 &&
		isreg(splited[1]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(splited[2]) == 0)
		msg_error(ERR_ARG, index);
	free(tmp);
	free_split(splited);
	return (1);
}

int	ft_or(char *line, int index)
{
	char *tmp;
	char **splited;

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	if (ft_strcmp(tmp, "or") != 0)
		return (0);
	tmp = ft_strsub(line, 2, ft_strlen(line));
	splited = ft_strsplit(tmp, SEPARATOR_CHAR);
	clear_split(splited);
	if (tab_len(splited) != 3)
		msg_error(ERR_NBR_ARG, index);
	if (isdir(splited[0]) == 0 && isindir(splited[0]) == 0 &&
		isreg(splited[0]) == 0)
		msg_error(ERR_ARG, index);
	if (isdir(splited[1]) == 0 && isindir(splited[1]) == 0 &&
		isreg(splited[1]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(splited[2]) == 0)
		msg_error(ERR_ARG, index);
	free(tmp);
	free_split(splited);
	return (1);
}

int	ft_xor(char *line, int index)
{
	char *tmp;
	char **splited;

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	if (ft_strcmp(tmp, "xor") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	splited = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(splited) != 3)
		msg_error(ERR_NBR_ARG, index);
	if (isdir(splited[0]) == 0 && isindir(splited[0]) == 0 &&
		isreg(splited[0]) == 0)
		msg_error(ERR_ARG, index);
	if (isdir(splited[1]) == 0 && isindir(splited[1]) == 0 &&
		isreg(splited[1]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(splited[2]) == 0)
		msg_error(ERR_ARG, index);
	free(tmp);
	free_split(splited);
	return (1);
}

int	ft_zjmp(char *line, int index)
{
	char *tmp;

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	if (ft_strcmp(tmp, "zjmp") != 0)
		return (0);
	tmp = ft_strsub(line, 4, ft_strlen(line));
	if (isdir(tmp) == 0)
		msg_error(ERR_ARG, index);
	free(tmp);
	return (1);
}

int	ft_ldi(char *line, int index)
{
	char *tmp;
	char **splited;

	tmp = ft_strsub(line, 0, search_char(line, ' '));
	if (ft_strcmp(tmp, "ldi") != 0)
		return (0);
	tmp = ft_strsub(line, 3, ft_strlen(line));
	splited = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (tab_len(splited) != 3)
		msg_error(ERR_NBR_ARG, index);
	if (isdir(splited[0]) == 0 && isindir(splited[0]) == 0 &&
		isreg(splited[0]) == 0)
		msg_error(ERR_ARG, index);
	if (isdir(splited[1]) == 0 && isreg(splited[1]) == 0)
		msg_error(ERR_ARG, index);
	if (isreg(splited[2]) == 0)
		msg_error(ERR_ARG, index);
	free(tmp);
	free_split(splited);
	return (1);
}
