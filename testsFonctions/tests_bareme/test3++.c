/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3++.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 15:15:24 by ymohl-cl          #+#    #+#             */
/*   Updated: 2015/03/19 15:19:25 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../depot/malloc.h"

#define M (1024 * 1024)

void print(char *s)
{
	write(1, s, strlen(s));
}

int main()
{
	char *addr1;
	char *addr2;
	char *addr3;

	addr1 = (char*)malloc(16*M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr2 = (char*)malloc(16*M);
	addr3 = (char*)realloc(addr1, 128*M);
	addr3[127*M] = 42;
	print(addr3);
	return (0);
}

