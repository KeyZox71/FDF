/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:50:36 by adjoly            #+#    #+#             */
/*   Updated: 2023/11/22 14:00:38 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_printconversion(char conversion, va_list args);
int		ft_putnbrulong(unsigned int n);
int		ft_putaddr(void *ptr);

int		ft_putstr(char *s);

int		ft_putnbrbase_p(unsigned long int n, char *base);
int		ft_putnbrbase(unsigned int n, char *base);
int		ft_putchar(char c);
int		ft_putnbr(int n);
size_t	ft_strlen(const char *s);

#endif