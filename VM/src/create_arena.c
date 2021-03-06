/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 07:28:06 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/04 03:06:50 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dump_arena(t_vm *vm)
{
	int	i;
	int	mem;

	mem = 64;
	i = 0;
	ft_printf("0x0000 : ");
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != MEM_SIZE && i != 0 && i != 64)
		{
			ft_printf("\n");
			ft_printf("%#06x : ", mem);
			mem += 64;
		}
		else if (i == 64)
		{
			ft_printf("\n");
			ft_printf("%#06x : ", mem);
			mem += 64;
		}
		ft_printf("%02x ", vm->arena[i]);
		i++;
	}
	ft_printf("\n");
}

void	create_arena(t_vm *vm)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		vm->arena[i] = 0;
		i++;
	}
}
