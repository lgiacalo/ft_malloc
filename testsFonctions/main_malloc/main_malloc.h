/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_malloc.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 13:59:03 by ymohl-cl          #+#    #+#             */
/*   Updated: 2018/10/23 19:11:21 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_MALLOC_H
# define MAIN_MALLOC_H

# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <xlocale.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include "../../include/malloc.h"

# define MEDIUM	5

void		tests_simples_malloc(void);
void		tests_complet_map_tiny(int tiny);
void		tests_complet_map_medium(int medium, int tiny);
void		tests_complet_map_large(int medium);
void		tests_multiple_map(int tiny);
void		tests_all_map(int tiny, int medium, int show_hex);
void		tests_complet_realloc(int tiny, int medium);
void		tests_corruption_memory(int tiny, int medium);
void		tests_getrlimit(void);
void		tests_multi_thread(int tiny, int medium);
void		tests_big_tests(void);

#endif /* !MAIN_MALLOC_H */
