#include <stdlib.h>
#include "list.h"

/* Init function's pointer */
void		InitMethod2(t_list *new)
{
  new->swap_contains = &SwapContains;
  new->foreach = &ForEachElem;
  new->list_to_tab = &ListToTab;
  new->tab_to_list = &TabToList;
  new->merge = &Merge;
  new->count = &CountElem;
  new->find = &FindElem;
  new->remove = &RemoveElem;
  new->extract = &ExtractElem;
  new->extract_at = &ExtractAtElem;
  new->extract_from_to = &ExtractFromTo;
  new->sort = &SortList;
  new->remove_if = &RemoveElemIf;
}

/* Init function's pointer */
void		InitMethod1(t_list *new)
{
  new->destroy = &DestroyList;
  new->len = &SizeList;
  new->index = &IndexList;
  new->is_empty = &IsEmptyList;
  new->push_front = &PushFront;
  new->push_back = &PushBack;
  new->pop_front = &PopFront;
  new->pop_back = &PopBack;
  new->begin = &BeginList;
  new->end = &EndList;
  new->current = &CurrentList;
  new->current_next = &IncCurrentList;
  new->current_prev = &DecCurrentList;
  new->current_reset = &ResetCurrent;
  new->front = &GetFront;
  new->back = &GetBack;
  new->at = &GetAt;
  new->get_current = &GetCurrent;
  new->insert_value = &InsertContain;
  new->insert_atvalue = &InsertAtContain;
  new->insert_elem = &InsertElem;
  new->insert_atelem = &InsertAtElem;
}

/* Init list status */
t_list		*CreateList()
{
  t_list	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->_size = 0;
  new->_index = 0;
  new->_current = NULL;
  new->_head = NULL;
  new->_tail = NULL;
  InitMethod1(new);
  InitMethod2(new);
  return (new);
}

/* Free list */
void		DestroyList(t_list *list, void (*free_func)(void *))
{
  if (!list)
    return ;
  DestroyNodeList(list->_head, free_func);
  list->_head = NULL;
  free(list);
}
