/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 10:19:33 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/06 10:54:10 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char	*str = "bonjour";

	printf("--------- conversion s ---------\n\n");
	//
	// ft_printf("%s\n", str);
	// printf("%s\n\n", str);
	//
	// ft_printf("%-s\n", str);
	// printf("%-s\n\n", str);
	//
	// ft_printf("%s\n", str);
	// printf("%s\n\n", str);
	//
	// ft_printf("%04s\n", str);
	// printf("%04s\n\n", str);
	//
	// ft_printf("%04s\n", str);
	// printf("%04s\n\n", str);

	// ft_printf("%013s\n", NULL);
	// printf("%013s\n\n", NULL);

	// ft_printf("%013s\n", str);
	// printf("%013s\n\n", str);
	//
	// ft_printf("%013s\n", str);
	// printf("%013s\n\n", str);

	ft_printf("%-7.5s\n", str);
	printf("%-7.5s\n\n", str);

	// ft_printf("%7.5s\n", str);
	// printf("%7.5s\n\n", str);

	ft_printf("%-7.5s\n", str);
	printf("%-7.5s\n\n", str);

	// ft_printf("%7.5s\n", str);
	// printf("%7.5s\n\n", str);
	//
	// ft_printf("%5.5s\n", str);
	// printf("%5.5s\n\n", str);
	//
	// ft_printf("%5.5s\n", str);
	// printf("%5.5s\n\n", str);
	//
	// ft_printf("%-5.5s\n", str);
	// printf("%-5.5s\n\n", str);
	//
	// ft_printf("%-5.5s\n", str);
	// printf("%-5.5s\n\n", str);
	//
	// ft_printf("%-1.5s\n", str);
	// printf("%-1.5s\n\n", str);
	//
	// ft_printf("%1.5s\n", str);
	// printf("%1.5s\n\n", str);
	//
	// ft_printf("%-1.5s\n", str);
	// printf("%-1.5s\n\n", str);
	//
	// ft_printf("%1.5s\n", str);
	// printf("%1.5s\n\n", str);

	// printf("--------- conversion d ---------\n\n");
	//
	//
	// ft_printf("%+d\n", 12);
	// printf("%+u\n\n", 12);

	// ft_printf("%d\n", 12);
	// printf("%d\n\n", 12);
	//
	// ft_printf("%d\n", -12);
	// printf("%d\n\n", -12);
	//
	// ft_printf("%04d\n", -12);
	// printf("%04d\n\n", -12);
	//
	// ft_printf("%04d\n", 12);
	// printf("%04d\n\n", 12);
	//
	// ft_printf("%013d\n", -12);
	// printf("%013d\n\n", -12);
	//
	// ft_printf("%013d\n", 12);
	// printf("%013d\n\n", 12);
	//
	// ft_printf("%-7.5d\n", -12);
	// printf("%-7.5d\n\n", -12);
	//
	// ft_printf("%7.5d\n", -12);
	// printf("%7.5d\n\n", -12);
	//
	// ft_printf("%-7.5d\n", -12);
	// printf("%-7.5d\n\n", -12);
	//
	// ft_printf("%7.5d\n", 12);
	// printf("%7.5d\n\n", 12);
	//
	// ft_printf("%5.5d\n", -12);
	// printf("%5.5d\n\n", -12);
	//
	// ft_printf("%5.5d\n", 12);
	// printf("%5.5d\n\n", 12);
	//
	// ft_printf("%-5.5d\n", 12);
	// printf("%-5.5d\n\n", 12);
	//
	// ft_printf("%-5.5d\n", -12);
	// printf("%-5.5d\n\n", -12);
	//
	// ft_printf("%-1.5d\n", -12);
	// printf("%-1.5d\n\n", -12);
	//
	// ft_printf("%1.5d\n", 12);
	// printf("%1.5d\n\n", 12);
	//
	// ft_printf("%-1.5d\n", 12);
	// printf("%-1.5d\n\n", 12);
	//
	// ft_printf("%1.5d\n", -12);
	// printf("%1.5d\n\n", -12);

	// printf("--------- conversion u ---------\n\n");
	//
	// ft_printf("%u\n", 12);
	// printf("%u\n\n", 12);
	//
	// ft_printf("%-u\n", -12);
	// printf("%-u\n\n", -12);
	//
	// ft_printf("%u\n", -12);
	// printf("%u\n\n", -12);
	//
	// ft_printf("%04u\n", -12);
	// printf("%04u\n\n", -12);
	//
	// ft_printf("%04u\n", 12);
	// printf("%04u\n\n", 12);
	//
	// ft_printf("%013u\n", -12);
	// printf("%013u\n\n", -12);
	//
	// ft_printf("%013u\n", 12);
	// printf("%013u\n\n", 12);
	//
	// ft_printf("%-7.5u\n", -12);
	// printf("%-7.5u\n\n", -12);
	//
	// ft_printf("%7.5u\n", -12);
	// printf("%7.5u\n\n", -12);
	//
	// ft_printf("%-7.5u\n", -12);
	// printf("%-7.5u\n\n", -12);
	//
	// ft_printf("%7.5u\n", 12);
	// printf("%7.5u\n\n", 12);
	//
	// ft_printf("%5.5u\n", -12);
	// printf("%5.5u\n\n", -12);
	//
	// ft_printf("%5.5u\n", 12);
	// printf("%5.5u\n\n", 12);
	//
	// ft_printf("%-5.5u\n", 12);
	// printf("%-5.5u\n\n", 12);
	//
	// ft_printf("%-5.5u\n", -12);
	// printf("%-5.5u\n\n", -12);
	//
	// ft_printf("%-1.5u\n", -12);
	// printf("%-1.5u\n\n", -12);
	//
	// ft_printf("%1.5u\n", 12);
	// printf("%1.5u\n\n", 12);
	//
	// ft_printf("%-1.5u\n", 12);
	// printf("%-1.5u\n\n", 12);
	//
	// ft_printf("%1.5u\n", -12);
	// printf("%1.5u\n\n", -12);


	return 0;
}
