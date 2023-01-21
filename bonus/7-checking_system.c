/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7-checking_system.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:14:59 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/21 14:39:17 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void cheking_system(t_stack *sta, t_stack *stb)
{
	char *str;
	char *all;
	char **instruct;
	(void)sta;
	(void)stb;

	all = "";
	while (1)
	{
		str =get_next_line(0);
		if (!str)
			break;
		if (ft_strlen(str) != 4 && ft_strlen(str) != 3)
			exit(1);
		if (ft_strncmp(str,"sa",2) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"sb",2) == 0)
			all =ft_strjoin(all,str);	
		else if (ft_strncmp(str,"ss",2) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"pa",2) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"pb",2) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"ra",2) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"rb",2) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"rr",2) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"rra",2) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"rra",2) == 0)
			all =ft_strjoin(all,str);
		else if (ft_strncmp(str,"rrb",2) == 0)
			all =ft_strjoin(all,str);
		else
			exit(1);
	}
	
	
	ft_printf("-----%s",all);
	// if(ft_strlen(str) > 3)
	// 	ft_printf("lol");
	exit(32);
}