/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:12:11 by emarette          #+#    #+#             */
/*   Updated: 2025/10/30 04:43:01 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isformat(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_putformat(char format, va_list arg)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar(va_arg(arg, int));
	if (format == 's')
		i += ft_putstr(va_arg(arg, char *));
	if (format == 'p')
		i += ft_putaddress(va_arg(arg, void *));
	if (format == 'd' || format == 'i')
		i += ft_putnbr(va_arg(arg, int));
	if (format == 'u')
		i += ft_putunbr(va_arg(arg, unsigned int));
	if (format == 'x')
		i += ft_puthex_lower(va_arg(arg, unsigned int));
	if (format == 'X')
		i += ft_puthex_upper(va_arg(arg, unsigned int));
	if (format == '%')
		i += ft_putpercent();
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	format;
	int		i;
	int		size;

	va_start(format, str);
	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_isformat(str[i + 1]) == 1)
		{
			i += 2;
			size += ft_putformat(str[i - 1], format);
		}
		else
			size += ft_putchar(str[i++]);
	}
	va_end(format);
	return (size);
}

/* int	main(void)
{
	//test without %
	ft_printf("wahooh \n");
	printf("wahooh \n");

	ft_printf("");
	printf("");

	//test %c
	ft_printf("%c\n", '\0');
	printf("%c\n", '\0');

	ft_printf("%c\n", 'c');
	printf("%c\n", 'c');

	ft_printf("%c\n", 256);
	printf("%c\n", 256);

	//test %s
	ft_printf("%s\n", "\0");
	printf("%s\n", "\0");

	// ft_printf(" NULL %s NULL \n", NULL);
	// printf(" NULL %s NULL \n", NULL);

	ft_printf("%s\n", "wahouh");
	printf("%s\n", "wahouh");

	ft_printf("%s\n", "zzz");
	printf("%s\n", "zzz");

	//test %p
	void *p1;
	p1 = NULL;
	ft_printf("%p\n", p1);
	printf("%p\n", p1);

	char *p2;
	p2 = "42";
	ft_printf("%p\n", p2);
	printf("%p\n", p2);

	char p3 = 'c';
	ft_printf("%p\n", &p3);
	printf("%p\n", &p3);

	//test %d
	ft_printf("%d\n", 0);
	printf("%d\n", 0);

	ft_printf("%d\n", 2147483647);
	printf("%d\n", 2147483647);

	ft_printf("%d  %d\n", 42, 32);
	printf("%d  %d\n", 42 , 32);

	ft_printf("%d\n", -2147483647);
	printf("%d\n", -2147483647);

	//test %i
	ft_printf("%i\n", 0);
	printf("%i\n", 0);

	ft_printf("%i\n", 2147483647);
	printf("%i\n", 2147483647);

	ft_printf("%i  %i\n", 42, 32);
	printf("%i  %i\n", 42 , 32);

	ft_printf("%i\n", -2147483647);
	printf("%i\n", -2147483647);

	//test %u
	ft_printf("%u\n", 0);
	printf("%u\n", 0);

	ft_printf("%u\n", 2147483647);
	printf("%u\n", 2147483647);

	ft_printf("%u  %u\n", 42, 32);
	printf("%u  %u\n", 42 , 32);

	ft_printf("%u\n", -2147483647);
	printf("%u\n", -2147483647);

	//test %x
	ft_printf("%x\n", 0);
	printf("%x\n", 0);

	ft_printf("%x\n", 42);
	printf("%x\n", 42);

	ft_printf("%x\n", -56);
	printf("%x\n", -56);

	//test %X
	ft_printf("%X\n", 0);
	printf("%X\n", 0);

	ft_printf("%X\n", 42);
	printf("%X\n", 42);

	ft_printf("%X\n", -56);
	printf("%X\n", -56);

	ft_printf("%X\n", 2147483647);
	printf("%X\n", 2147483647);

	//test %%
	ft_printf("%% %%\n");
	printf("%% %%\n");

	ft_printf("%%\n");
	printf("%%\n");

	//test mix
	char *ptr = "vilbrequin";
	ft_printf("%c %s %p %d %i %u %x %X %% \n",'a', "bcde", ptr, 42, 42,
		42, 42, 42);
	printf("%c %s %p %d %i %u %x %X %% \n",'a', "bcde", ptr, 42, 42, 42,
		42, 42);
} */
