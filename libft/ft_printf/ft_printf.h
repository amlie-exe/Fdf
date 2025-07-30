/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amhan <amhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:24:17 by amhan             #+#    #+#             */
/*   Updated: 2025/07/09 16:42:19 by amhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_print_c(char c, int *count_chars);
void	ft_print_s(char *s, int *count_chars);
void	ft_print_d(int nb, int *count_chars);
void	ft_print_u(unsigned int nb, int *count_chars);
void	ft_print_p(void *address, int *count_chars);
void	ft_print_hexlower(unsigned int nb, int *count_chars);
void	ft_print_hexupper(unsigned int nb, int *count_chars);

#endif