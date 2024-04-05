/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:44:52 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 11:00:07 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libr.h"

int	process_specifier(const char *s, va_list ap)
{
	if (*s == 'c')
		return (ft_putchar_fd(va_arg(ap, unsigned long), 1));
	else if (*s == 's')
		return (ft_print_string(va_arg(ap, char *)));
	else if (*s == 'p')
		return (ft_print_pointer(va_arg(ap, unsigned long)));
	else if (*s == '%')
		return (ft_putchar_fd('%', 1));
	else if (*s == 'd' || *s == 'i')
		return (ft_print_signed(va_arg(ap, unsigned long)));
	else if (*s == 'u')
		return (ft_print_unsigned(va_arg(ap, unsigned long)));
	else if (*s == 'x')
		return (ft_print_hex(va_arg(ap, unsigned long), 'a'));
	else if (*s == 'X')
		return (ft_print_hex(va_arg(ap, unsigned long), 'A'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(ap, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
			count += process_specifier((char *)(++s), ap);
		else
			count += ft_putchar_fd(*s, 1);
		s++;
	}
	va_end(ap);
	return (count);
}
/*
int	main(void)
{
char *str = "Let it happen";
printf("\t**  Printing normal string and 
returning the count  as signed int  **\n");
	ft_printf("%d  ", ft_printf("hello \t"));
	printf("%d  \n", printf("hello \t"));
	printf("\n<=========>\n");
	printf("\t**Printing composed string 
	with s placeholder and other chars**\n");
	ft_printf("%d" ,ft_printf("%s let it happen \t", str));
	printf("%d\n" ,printf("%s let it happen \t", str));
	printf("\n<=========>\n");
	ft_printf("%d\n", 5555);
	printf("%d\n", 5555);
	int x = 12345;
	printf("\n<=========>\n");
	ft_printf("%d\n", ft_printf("%d\n", x));
	printf("%d\n", printf("%d\n", x));
	printf("\n<=========>\n");
	printf("\t*** Printing a 
	haxadecimal value ***\n");
	ft_printf("%d\n" ,ft_printf("%X\n", 342342342));
	printf("%d\n" ,printf("%X\n", 342342342));
	printf("\n<=========>\n");
	ft_printf("\n%d\n" ,ft_printf("Tyler durden
	 located at %p, says to %s", str, str));
	printf("\n%d\n" ,printf("Tyler durden 
	located at %p, says to %s", str, str));
	printf("\n<=========>\n");
	ft_printf("\n%d\n", ft_printf("\n%x\n", 43123443));
	printf("\n%d\n", printf("\n%x\n", 43123443));
	printf("\n<=========>\n");
	ft_printf("%d\n" ,ft_printf("%p\n", NULL));
	printf("%d\n" ,printf("%p\n", NULL));
	printf("\n<=========>\n");
	printf("\t**** big test ****\n");
	ft_printf("\n%d\n" ,ft_printf("Tyler durden 
	located at %p, says to %s", str, str));
	printf("\n%d\n" ,printf("Tyler durden 
	located at %p, says to %s", str, str));
	printf("\n<=========>\n");
	printf("%u\n", -55);
	printf("%d\n" ,printf("%s\n", NULL));
	printf("%d\n" ,printf("%s\n", NULL));
	ft_printf("%u\n", -55);
	return (0);
	}*/