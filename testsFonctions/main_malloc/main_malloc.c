/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 13:57:05 by ymohl-cl          #+#    #+#             */
/*   Updated: 2018/10/24 19:18:38 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_malloc.h"

// La defragmentation doit etre argumente en soutenance. Pas de tests specifique
// Idem pour les variables d'environnements.
// L'utilisation de getPagesize doit etre justifie en soutenance, pas de test specifique.
//t_struct		g_stt = {NULL, NULL, NULL, 0};

//pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

int		main(void)
{
	int			tiny;
	int			medium;
	int			show_hex;

	(void)tiny;
	(void)medium;
	(void)show_hex;
	show_hex = 1;
	tiny = 128;
	medium = 512;
	srand(time(NULL));
//	tests_simples_malloc();
//	tests_complet_map_tiny(tiny);
//	tests_complet_map_medium(medium, tiny);
//	tests_complet_map_large(medium);
	tests_multiple_map(tiny);
//	tests_big_tests();
	tests_all_map(tiny, medium, show_hex);
//	tests_complet_realloc(tiny, medium);
	tests_getrlimit();
//	tests_multi_thread(tiny, medium);
//	tests_corruption_memory(tiny, medium);
	return (0);
}
