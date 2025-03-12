/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolet-l <msolet-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:53:08 by msolet-l          #+#    #+#             */
/*   Updated: 2024/10/28 17:54:38 by msolet-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd2(char c, int fd)
{
	return (write(fd, &c, 1));
}

void	ft_put_and_free(char *argc, int *len)
{
	if (argc)
	{
		if (ft_putstr_fd2(argc, 1) != -1 && len >= 0)
			*len += ft_strlen((const char *)argc);
		else
			*len = -1;
		free(argc);
	}
}

static int	ft_get_str(const char *format, int i, int *len, va_list *ap)
{
	char	*argc;

	argc = NULL;
	if (format[i + 1] == 'c')
		ft_printc(va_arg(*ap, int), 1, len);
	else if (format[i + 1] == '%')
		argc = ft_strdup("%");
	else if (format[i + 1] == 's')
		argc = printf_s(va_arg(*ap, const char *));
	else if (format[i + 1] == 'x' || format[i + 1] == 'X')
		argc = ft_ltoa_hexa(va_arg(*ap, unsigned int), format[i + 1]);
	else if (format[i + 1] == 'p')
		argc = printf_p(va_arg(*ap, unsigned long long));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		argc = ft_itoa(va_arg(*ap, int));
	else if (format[i + 1] == 'u')
		argc = ft_utoa(va_arg(*ap, unsigned int));
	else if (format[i + 1])
		argc = ft_substr(format, i, 2);
	else
		return (0);
	ft_put_and_free(argc, len);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	if (format == 0)
		return (-1);
	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!ft_get_str(format, i, &len, &ap))
				return (-1);
			i++;
		}
		else
			ft_putlen(format, i, &len);
		i++;
	}
	va_end(ap);
	return (len);
}
