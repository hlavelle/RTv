#include "../include/rtv1.h"

void	objs_free(t_obj *l)
{
	t_obj	*tmp;

	while (l)
	{
		tmp = l->next;
		free(l);
		l = tmp;
	}
}

void	light_free(t_light *l)
{
	t_light	*tmp;

	while (l)
	{
		tmp = l->next;
		free(l);
		l = tmp;
	}
}

t_obj	*new_obj(t_obj *curr)
{
	t_obj	*tmp;
	t_obj	*new;

	tmp = curr;
	new = (t_obj *)malloc(sizeof(t_obj));
	ft_bzero(new, sizeof(t_obj));
	if (tmp == NULL)
		return (new);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

t_light	*new_light(t_light *curr)
{
	t_light	*tmp;
	t_light	*new;

	tmp = curr;
	new = (t_light *)malloc(sizeof(t_light));
	ft_bzero(new, sizeof(t_light));
	if (tmp == NULL)
		return (new);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}
