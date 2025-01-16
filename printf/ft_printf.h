/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:18:53 by ailbezer          #+#    #+#             */
/*   Updated: 2024/10/25 11:24:33 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

void	ft_print_int(int n, int *count);
void	ft_putchar_c(int c, int *count);
void	ft_print_str(char *s, int *count);
int		ft_printf(const char *format, ...);
void	ft_check(va_list arg, int c, int *count);
void	ft_print_unsint(unsigned int n, int *count );
void	ft_print_address(unsigned long pointer, int *count);
void	ft_print_hex(unsigned int hex_num, int *count, char hex);

#endif
