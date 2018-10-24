/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:41:05 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/24 15:49:11 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/resource.h>
#include "../include/malloc.h"

int main(void)
{

	printf("Valeur getpagesize() = %d \n)", getpagesize());
	printf("Struct t_env : %lu\n", sizeof(t_env));
	printf("Struct t_zone : %lu\n", sizeof(t_zone));
	printf("Struct t_header : %lu\n", sizeof(t_header));

	return (0);
}
