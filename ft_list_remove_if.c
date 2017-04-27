// #include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct			s_list
{
		struct s_list	*next;
		void 			*data;
}						t_list;

void 	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*tmp;
	t_list	*last_elem;

	current = *begin_list;
	tmp = NULL;
	last_elem = NULL;
	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
		{
			if (current == *begin_list)
				*begin_list = current->next;
			else
				last_elem->next = current->next;
			tmp = current;
			current = current->next;
			free(tmp);
		}
		else
		{
			last_elem = current;
			current = current->next;
		}
	}
}

int main(void)
{
	t_list *begin_list;
	t_list *tmp;
	int i;

	i = 0;
	tmp = NULL;
	while (i < 4)
	{
		begin_list = malloc(sizeof(t_list));
		if (i == 0)
			begin_list->data =  "OK";
		if (i == 1)
			begin_list->data =  "OK";
		if (i == 2)
			begin_list->data =  "OK";
		if (i == 3)
			begin_list->data =  "OK";
		begin_list->next = tmp;
		tmp = begin_list;
		i++;
	}
	printf("avant\n");
	while(tmp)
	{
		printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
	printf("apres\n");
	ft_list_remove_if(&begin_list, "OK", &strcmp);
	while(begin_list)
	{
		printf("%s\n", begin_list->data);
		begin_list = begin_list->next;
	}
}
