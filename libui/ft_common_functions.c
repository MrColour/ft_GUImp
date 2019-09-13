/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:40:09 by kmira             #+#    #+#             */
/*   Updated: 2019/09/12 22:42:21 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	append_container(t_linker *links, t_gen_box *container)
{
	t_linker *node;

	node = links;
	while (node->next != NULL)
		node = node->next;
	node->next = malloc(sizeof(*node->next) * (1));
	node->next->data = container;
	node->next->next = NULL;
}

void	*common_read_state(void *self, char *string)
{
	void	*result;

	result = NULL;
	if (strcmp(string, "ACTIVE") == 0)
	{
		result = malloc(sizeof(char) * (1));
		if ((*(int *)self & 1) == 0)
			*(char *)result = 1;
		return (result);
	}
	if (strcmp(string, "HOVER") == 0)
	{
		result = malloc(sizeof(char) * (1));
		if ((*(int *)self & 2) != 0)
		{
			*(char *)result = 1;
			printf("Parent reads I am hoverd!\n");
		}
		return (result);
	}
	(void)self;
	return (result);
}

int		if_parent_is_active(t_gen_box *parent, void *self, t_events *event)
{
	void	*data;

	data = parent->read_state(parent->self_state, "HOVER");
	if (*(char *)data == 1)
	{
		printf("Parent: %s said he was hovered!\n", parent->name);
		free(data);
		return (1);
	}
	(void)self;
	(void)event;
	return (0);
}

int		always_active(t_gen_box *parent, void *self, t_events *event)
{
	(void)parent;
	(void)self;
	(void)event;
	return (1);
}
