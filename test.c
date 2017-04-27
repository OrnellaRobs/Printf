/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:27:58 by orazafin          #+#    #+#             */
/*   Updated: 2017/04/25 14:54:39 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
/*
int		ft_is_in(char elem, char *src)
{
	int i;


	i = 0;
	while(src[i])
	{
		if (src[i] == elem)
			return (1);
		i++;
	}
	return (0);
}

int		count_how_many_str_to_malloc(char *format)
{
	int i;
	int count;
	int state;
	int	count_percent;

	i = 0;
	count = 1;
	state = 0;
	count_percent = 0;
	while (format && format[i])
	{
		printf("%c   ||   percent = %d\n", format[i], count_percent);
		if (format[i] == '%' && format[i + 1] != '%' && !(count_percent % 2))
		{
			printf("------- \n1\n-------\n ");
			count_percent = 0;
			count++;
			printf("||| COUNT 1 = %d |||\n", count);
			while (ft_is_in(format[i], "sSpPdDioOuUxXcC") == 0)
			{
				i++;
			}
			state = 1;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			printf("------- \n2\n-------\n ");
			count_percent++;
		}
		else if (state == 1)
		{
			printf("------- \n3\n-------\n ");
			printf("||| COUNT 2 = %d |||\n", count);
			count++;
			state = 0;
		}
		i++;
	}
	return (count);
}
*/



// char	*ft_itoa_base(int n, int base);

#include <locale.h>
#include <unistd.h>

void	ft_strclr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

int		main(void)
{
	int i;

	// setlocale(LC_ALL,"");
	i = 0;
	char *str;

	str = malloc(sizeof(char) * 8);
	str = "bonjour";
	*str = 'a';
	ft_putstr(str);
	// ft_putstr("\n");
	// while (i < 2)
	// 	i++;
	// str[i] = '\0';
	// ft_putstr(str);
	// char *format = "test = %d et puis%%d ok %p";
	//printf("count = %d\n", count_how_many_str_to_malloc(format));
	// printf("%10.6sok\n", "bonjour");
	// printf("%d\n",printf("%.1s","bonjours"));
	// printf(" %d\n",printf("%S",L"🦄 "));
	// printf(" %d\n",printf("%x",123456789));
	// printf(" %d\n",printf("%X",123456789));
	// printf("%s\n", ft_itoa_base(-20,16));
	return (0);
}
/*
char	**parsing(char *format)
{
	int		i;
	int		j;
	char	state;
	char	**res;

	i = 0;
	state = 0;
	j = 1;
	while (format && format[i])
	{
		{
			j++;
			state = 1;
		}
		if (state == 1 && ft_is_in(format[i], "sSpPdDioOuUxXcC") == 1)
		{
			j++;
			state = 0;
		}
		i++;
	}
	i = 0;
	printf("")
	res = malloc(sizeof(char *) * j  + 1);
	res[j] = NULL;
	while(format && format[i])
	{
		if(format[i] == '%')
		{
			j++;
			i = 0;
		}
		//res[j][i] = ft_strjoin(res[j],format[i]);
		i++;
	}
	return (res);
}

int		ft_printf(const char *format, ...)
{
	parsing((char *)format);
	return(0);
}

 int	sum(unsigned int elem0, ...)
 {
	 int 		count;
	 int		tmp;
	 va_list	list;
	 int		result;

	 count = 1;
	 result = 0;
	 va_start(list, elem0);
	 while(va_arg(list,long))
	 {
		 count++;
	 }
	 va_end(list);
	 va_start(list, elem0);
	 result = elem0;
	 while(--count)
	 {
		printf("%d\n",va_arg(list,int));
	 }

	 va_end(list);
	 return (result);
 }

 int		main(void)
 {
	 int i;

	 i = 0;
	 printf("%d\n",sum(4,&i,"test",1,'c',60,'c','\0'));
	 printf("%p\n",&i);
	 printf("test = %-4d,%d,% d, %%d, %d%d",10,1,-1,1,1);
	 printf("%U\n",	0x0001F984 );
	 return (0);
 }
*/
