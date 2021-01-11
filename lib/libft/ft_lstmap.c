#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*a;

	if (lst == NULL)
		return (NULL);
	if (lst)
	{
		a = (t_list *)malloc(sizeof(lst));
		if (a == NULL)
			return (NULL);
		a = f(lst);
		a->next = ft_lstmap(lst->next, f);
		return (a);
	}
	return (NULL);
}
