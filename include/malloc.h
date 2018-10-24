/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:40:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/10/24 23:20:53 by lgiacalo         ###   ########.fr       */
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

typedef struct			s_ret
{
	void				*prev;
	void				*new;
	void				*suiv;
}						t_ret;


void					*ft_malloc(size_t size);

void					*ft_mmap(size_t size);
t_zone					*ft_mmap_zone(size_t size);
t_header				*ft_mmap_header(size_t size);

t_env					*env(void);

void					*ft_error_mmap(char *str);
void					*ft_error_munmap(char *str);

/*
**	Print
*/

void					show_alloc_mem(void);

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
