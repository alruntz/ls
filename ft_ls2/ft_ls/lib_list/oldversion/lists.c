#include <stdlib.h>
#include <string.h>

#define	CONTENT struct s_content

typedef struct		s_test
{
	int	n1;
	int	n2;
}			t_test;

typedef struct		s_content
{
	void		*data;
	int		tri;
	CONTENT		*next;
	CONTENT		*back;
	size_t		id;
	size_t		size_data;

}			t_content;

typedef struct		s_list
{
	t_content	*last;
	t_content	*first;
	size_t		last_id;
	size_t		size;
}			t_list;

t_list			*new_list(void);
t_content 		*push_back(t_list **lst, void *data, size_t size_data);
t_content 		*new_content(void *data, size_t size_data);
void			remove(t_list *list, t_content *content);

void            	swap_content(t_content **c1, t_content **c2);
void            	tri(t_list **lst);

void			**to_array(t_list *lst);
t_list			*to_list(void **arr, size_t size_data);
t_list          	*get_if(t_list *lst, int (f)(void *), int val);


t_list		*new_list(void)
{
	t_list *ret;

	ret = malloc(sizeof(t_list));
	ret->last = NULL;
	ret->first = NULL;
	ret->last_id = 0;
	ret->size = 0;
	return (ret);
}

t_content	*new_content(void *data, size_t size_data)
{
	t_content *ret;
	ret = NULL;

	ret = malloc(sizeof(t_content));
	ret->data = malloc(size_data);
	ret->data = memcpy(ret->data, data, size_data);
	ret->tri = 0;
	ret->size_data = size_data;
	ret->next = NULL;
	ret->back = NULL;
	return (ret);
}

t_content	*push_back(t_list **lst, void *data, size_t size_data)
{
	t_content *ret;

	ret = new_content(data, size_data);
	if (!(*lst)->first)
		(*lst)->first = ret;
	else
		(*lst)->last->next = ret;
	ret->back = (*lst)->last;
	(*lst)->last = ret;
	(*lst)->last_id++;
	ret->id = (*lst)->last_id;
	(*lst)->size++;
	return (ret);
}

void		remove(t_list *list, t_content *content)
{
	content->back->next = content->next;
	list->size--;
	free(content);
}

void		swap_content(t_content **c1, t_content **c2)
{
	t_content tmp;
	tmp = **c1;
	(*c1)->data = (*c2)->data;
	(*c1)->tri = (*c2)->tri;
	(*c2)->data = tmp.data;
	(*c2)->tri = tmp.tri;
}

void		tri(t_list **lst)
{
	t_content *content;
	t_content *tmp_content;
	int b;
	
	b = 1;
	content = (*lst)->first;
	while (b)
	{
	   b = 0;
		while (content)
		{
			tmp_content = (*lst)->first;
			while (tmp_content)
			{
				if (content->tri < tmp_content->tri)
				{
					swap_content(&content, &tmp_content);
					b = 1;
				}
				tmp_content = tmp_content->next;
			}
				content = content->next;
		}
	}
}

void		**to_array(t_list *lst)
{
	void **ret;
	t_content *content;
	size_t i;

	ret = malloc(lst->size * lst->first->size_data + 1);
	i = 0;
	content = lst->first;
	while(content)
	{
		ret[i] = content->data;//memcpy(ret[i], content->data, content->size_data);
		i++;
		content = content->next;
	}
	ret[i] = NULL;
	return (ret);
}

t_list		*to_list(void **arr, size_t size_data)
{
	t_list *ret;
	int i;
	
	ret = new_list();
	i = -1;
	while(arr[++i])
		push_back(&ret, arr[i], size_data);
	return (ret);
}


t_list		*get_if(t_list *lst, int (f)(void *), int val)
{
	t_list *ret;
	t_content *content;

	content = lst->first;
	ret = new_list();
	while(content)
	{
		if (f(content->data) == val)
			push_back(&ret, content->data, content->size_data);
		content = content->next;
	}
	return (ret);
}
t_test	*new_test(int n1, int n2)
{
	t_test *ret;

	ret = malloc(sizeof(ret));
	ret->n1 = n1;
	ret->n2 = n2;
	return (ret);
}

int test_func(void *test)
{
	if (((t_test*)(test))->n1 < 10)
		return (1);
	return (0);
}

/*int	main(void)
{
	t_list *lst = new_list();
	t_content *content;

	push_back(&lst, new_test(2, 5), sizeof(t_test));
	push_back(&lst, new_test(1, 19), sizeof(t_test));
	push_back(&lst, new_test(15, 21), sizeof(t_test));
	push_back(&lst, new_test(2, 48), sizeof(t_test));
	push_back(&lst, new_test(15, 7), sizeof(t_test));
	push_back(&lst, new_test(3, 21), sizeof(t_test));
	content = lst->first;
	//remove(lst, content->next);
	while (content)
	{
		content->tri = ((t_test *)(content->data))->n2;
		content = content->next;
	}
	//tri(&lst);
	//swap_content(&(lst->first), &(lst->last));
	content = lst->first;
	while (content)
	{
		printf("%d\n", ((t_test *)(content->data))->n1);
		content = content->next;
	}
	t_test **tests = (t_test **)to_array(lst);
	t_list *list = to_list((void **)tests, sizeof(t_test));
	printf("=>%d", tests[0]->n1);
	printf("==>%d", ((t_test *)(list->first->next->data))->n1);
	t_list *get = get_if(list, test_func, 1);
	t_content *tmp_get = get->first;
	while(tmp_get)
	{
		printf("-->%d<--\n", ((t_test *)(tmp_get->data))->n1);
		tmp_get = tmp_get->next;
	}
	return (0);
}*/
