# ifndef LIST_H 
#define LIST_H

#include <stdlib.h>

#define CONTENT struct s_content

typedef struct      s_content
{
    void        *data;
    int         tri;
    CONTENT     *next;
    CONTENT     *back;
    size_t      id;
    size_t      size_data;

}           t_content;

typedef struct      s_list
{
    t_content   *last;
    t_content   *first;
    size_t      last_id;
    size_t      size;
}           t_list;

t_list			*new_list(void);
t_content		*push_back(t_list **lst, void *data, size_t size_data);
t_content		*new_content(void *data, size_t size_data);
void			remove(t_list *list, t_content *content);

void			**to_array(t_list *lst);
t_list			*to_list(void **arr, size_t size_data);
t_list			*get_if(t_list *lst, int (f)(void *), int val);

void			swap_content(t_content **c1, t_content **c2);

#endif
