/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_xor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 04:04:22 by cboiron           #+#    #+#             */
/*   Updated: 2018/05/03 23:32:10 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	choose_op(int *arg, t_proc *proc)
{
	if (proc->instruction == 6)
		proc->reg[arg[2] - 1] = arg[0] & arg[1];
	else if (proc->instruction == 7)
		proc->reg[arg[2] - 1] = arg[0] | arg[1];
	else if (proc->instruction == 8)
		proc->reg[arg[2] - 1] = arg[0] ^ arg[1];
	if (proc->reg[arg[2] - 1] == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
}

static void	param_op_2(t_vm *vm, t_proc *proc, int *arg, int *pc)
{
	if (PARAM2 == REG)
	{
		arg[1] = get_reg(vm, pc);
		if (!(is_reg(arg[1])))
			return ;
		arg[1] = proc->reg[arg[1] - 1];
	}
	else if (PARAM2 == INDIRECT)
	{
		arg[1] = (short)get_ind(vm, pc);
		arg[1] %= IDX_MOD;
		arg[1] = get_value(vm, mod(proc->save_pc + arg[1], MEM_SIZE));
	}
	else if (PARAM2 == DIRECT)
		arg[1] = get_dir(vm, pc, proc->instruction);
	arg[2] = get_reg(vm, pc);
	if (!is_reg(arg[2]))
		return ;
	choose_op(arg, proc);
	proc->pc = *pc;
}

void		param_op(t_vm *vm, t_proc *proc, int *arg)
{
	int	pc;

	proc->pc++;
	pc = proc->pc + 1;
	if (PARAM1 == REG)
	{
		arg[0] = get_reg(vm, &pc);
		if (!is_reg(arg[0]))
			return ;
		arg[0] = proc->reg[arg[0] - 1];
	}
	else if (PARAM1 == INDIRECT)
	{
		arg[0] = (short)get_ind(vm, &pc);
		arg[0] %= IDX_MOD;
		arg[0] = get_value(vm, mod(proc->save_pc + arg[0], MEM_SIZE));
	}
	else if (PARAM1 == DIRECT)
		arg[0] = get_dir(vm, &pc, proc->instruction);
	param_op_2(vm, proc, arg, &pc);
}
