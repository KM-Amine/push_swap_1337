/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:30:45 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/15 09:44:04 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "limits.h"

void	exit_fuction(void);
int		ft_atoi_max(const char *str, int *check);
char	***total_generator(int argc, char **argv);
char	**data_joiner(char ***total, int argc);
char	**check_duplicates(char **final);
void	free_total(char ***total, int argc);
void	error_detector(char **argv, int i, int j);
int		*numbers_converter(char **final,int *len);
void	free_total(char ***total, int argc);
char	**argument_analyser(int argc, char **argv);

#endif