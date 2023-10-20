/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:45:04 by lsilva-q          #+#    #+#             */
/*   Updated: 2022/12/14 15:44:55 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>
# include <unistd.h>

// Private: Node Struct (Secondary Struct)
typedef struct s_ftnode
{
	struct s_ftnode	*next;
	struct s_ftnode	*prev;
	void			*content;
}	t_ftnode;

// Public: List Struct (Primary Struct)
typedef struct s_ftlist
{
	struct s_ftnode	*front;
	struct s_ftnode	*back;
	int				size;
}	t_ftlist;

// Public functions

	// List initialization

int			ft_lst_init(t_ftlist *lst);

	// List cleaning

void		ft_lst_clear(t_ftlist *lst, void (*f)(void *));

	// Setget

int			ft_lst_set(t_ftlist *lst, int index, void *content);
void		*ft_lst_get(t_ftlist *lst, int index);

	// Push

t_ftnode	*ft_lst_push(t_ftlist *lst, int index, void *content);
t_ftnode	*ft_lst_push_back(t_ftlist *lst, void *content);
t_ftnode	*ft_lst_push_front(t_ftlist *lst, void *content);

	// Pop

void		*ft_lst_pop(t_ftlist *lst, int index);
void		*ft_lst_pop_back(t_ftlist *lst);
void		*ft_lst_pop_front(t_ftlist *lst);

	// Utils

t_ftlist	*ft_lst_dup(t_ftlist *lst, void *(*copy_f)(void *));
int			ft_lst_swap_node(t_ftlist *lst, int index1, int index2);
void		**ft_lst_toarray(t_ftlist *lst);
int			ft_lst_is_empty(t_ftlist *lst);
void		*ft_lst_last(t_ftlist *lst);
void		*ft_lst_first(t_ftlist *lst);

// Private functions

t_ftnode	*ft_lst_push_front_node(t_ftlist *lst, t_ftnode *node);
t_ftnode	*ft_lst_push_back_node(t_ftlist *lst, t_ftnode *node);
t_ftnode	*ft_lst_push_node(t_ftlist *lst, int index, t_ftnode *node);
t_ftnode	*ft_lst_getnode(t_ftlist *lst, int index);
int			ft_lst_getindex(t_ftlist *lst, t_ftnode *node);
void		*ft_lst_pop_node(t_ftlist *lst, t_ftnode *node);
void		ft_node_free(t_ftnode *node);
t_ftnode	*ft_node_new(void *content);

// Testing

	// Push

t_ftnode	*ft_lst_push_ord(t_ftlist *lst, void *content,
				int (*lesser_func)(void *, void *));

	// Utils

t_ftnode	*ft_lst_find(t_ftlist *lst, void *value,
				int (*cmp_func)(void *, void *));

void		ft_lst_func_apply(t_ftlist *lst,
				void (*func)(void *, size_t, int, int));

#endif
