#ifndef LISTES_H
# define LISTES_H

typedef struct s_list
{
	int				nbr;
	char			index;
	int				nb_elem;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int nbr, char index);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstclear(t_list **lst, void (*del)(int));
void	ft_lstiter(t_list *lst, void (*f)(int));
t_list	*ft_lstmap(t_list *lst, void *(*f)(int), void (*del)(int));
void	ft_lstnext(t_list **lst);
int	*ft_save(int *numbers, int counter, int *index);
#endif
