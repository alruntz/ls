# ifndef LIST_H 
#define LIST_H

#include <stdlib.h>

#define LST_CONTENT struct s_lst_content

typedef struct      s_lst_content
{
    void        	*data;
    void			*tri;
    LST_CONTENT     *next;
    LST_CONTENT     *back;
    size_t     		 id;
	size_t			size_tri;
    size_t     	 	size_data;

}           t_lst_content;

typedef struct      s_list
{
    t_lst_content   *last;
    t_lst_content   *first;
    size_t      last_id;
    size_t      size;
}           t_list;

t_list				*new_list(void);
t_lst_content		*push_back(t_list **lst, void *data, size_t size_data);
t_lst_content		*push_front(t_list **lst, void *data, size_t size_data);
t_lst_content		*new_lst_content(void *data, size_t size_data);
void				lst_remove(t_list *list, t_lst_content *lst_content);

void				**to_array(t_list *lst);
t_list				*to_list(void **arr, size_t size_data);
t_list				*get_if(t_list *lst, int (f)(void *), int val);

void				swap_lst_content(t_lst_content **c1, t_lst_content **c2);
void				tri(t_list **list, int invers);

void				*ft_memalloc(size_t content_size);
void				*ft_memcpy(void *dest, const void *src, size_t n);
int					ft_strcmp(const char *s1, const char *s2);

#endif
