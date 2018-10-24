/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 15:20:47 by ymohl-cl          #+#    #+#             */
/*   Updated: 2015/03/19 15:21:57 by ymohl-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../depot/malloc.h"

void print(char *s)
{
	write(1, s, strlen(s));
}

int main()
{
	char *addr;

	addr = malloc(16);
	free(NULL);
	free((void *)addr + 5);
	if (realloc((void *)addr + 5, 10) == NULL)
		print("Bonjours\n");
}
