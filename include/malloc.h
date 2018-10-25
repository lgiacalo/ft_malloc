/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:40:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/25 05:14:49 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/mman.h>
# include <unistd.h>

/*
**	// ne pas mettre la fonction getpagesize() dans le define
** // ORDRE : taille pour les free
** // 		 : adresse pour les taken
*/

# define PAGESIZE					getpagesize()
# define TINY_ZONE					(8 * PAGESIZE)
# define TINY_MAX_ALLOC				128
# define SMALL_ZONE					(32 * PAGESIZE)
# define SMALL_MAX_ALLOC			1024
# define TRUE						1
# define FALSE						0

# define HEADER(l)					((t_header *)(l))
# define HEADER_NEXT(l)				(((t_header *)(l))->next)
# define HEADER_MAILLON_NEXT(l)		(t_header *)(((char *)(((t_header *)l) + 1)) + ((t_header *)l)->len)

# define ZONE(l)					((t_zone *)(l))
# define ZONE_NEXT(l)				(((t_zone *)(l))->next_zone)
# define ZONE_MAILLON_NEXT(l)		(t_zone *)(((char *)(((t_zone *)l) + 1)) + ((t_zone *)l)->len_zone)


typedef	struct			s_header
{
	size_t				len;
	struct s_header		*next;
}						t_header;

typedef struct			s_zone
{
	size_t				len_zone;
	t_header			*taken;
	t_header			*free;
	struct s_zone		*next_zone;
}						t_zone;

typedef struct			s_env
{
	t_zone				*tiny;
	t_zone				*small;
	t_header			*large;
}						t_env;



void					*malloc(size_t size);
void					free(void *ptr);
void					*realloc(void *ptr, size_t size);

void					*ft_malloc(size_t size);
t_header				*ft_malloc_boucle_header(t_zone *zone, size_t size);

void					ft_free(void *ptr);
int						ft_verif_adr_ptr(void *ptr);

void					*ft_realloc(void *ptr, size_t size);

/*
**	Fonctions map
*/

void					*ft_mmap(size_t size);
t_zone					*ft_mmap_zone(size_t size);
t_header				*ft_mmap_header(size_t size);

t_env					*env(void);
size_t					ft_align_16(size_t size);

/*
**	Fonctions list Header
*/

int						ft_hlst_add_end(t_header **first, t_header *add);
int						ft_hlst_add_malloc(t_header **first, t_header *add);
int						ft_hlst_add_free(t_header **first, t_header *add);
t_header				*ft_hlst_extract_size(t_header **first, size_t size, int (*condition)(void *s, size_t size));
t_header				*ft_hlst_extract_adr(t_header **first, t_header *sup);

/*
** Fonctions list Zone
*/

int						ft_zlst_add_end(t_zone **first, t_zone *add);

/*
**	Fonctions Conditions
*/

int						ft_tri_size_more_header(void *s, size_t size);

/*
**	Fonctions errors
*/

void					*ft_error_mmap(char *str);
void					*ft_error_munmap(char *str);
void					*ft_error_list(char *str);
int						ft_error_condition(char *str);
void					*ft_error_adr(char *str);

/*
**	Print
*/

void					show_alloc_mem(void);
void					show_free_mem(void);

void					print_map(t_zone *zone);
void					print_list_header(t_header *header, char *str);
void					print_header(t_header *header, char *str);
void					print_zone(t_zone *zone);
void					print_env(t_env *env);
void					print_define_zone(void);

/*
**	Fonctions utiles
*/

size_t					ft_strlen(const char *s);
int						ft_putstr(char const *s);
int						ft_putchar(char c);
void					ft_aputnbr(long long int n);
void					ft_putpnbr_base(unsigned long long int n, char *base);
void					*ft_memmove(void *dst, const void *src, size_t len);

#endif
