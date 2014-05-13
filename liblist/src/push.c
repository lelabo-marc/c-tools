/*
** push.c for  in /home/lelabo_m/rendu/liblist-c/liblist/src
**
** Made by Marc Le Labourier
** Login   <lelabo_m@epitech.net>
**
** Started on  Mon Mar 10 13:52:09 2014 Marc Le Labourier
** Last update Mon Mar 10 15:02:58 2014 Marc Le Labourier
*/

#include <stdlib.h>
#include "list.h"

int	PushFront(t_list *list, void *elem)
{
  t_node	*new;

  if (!list || ((new = CreateNode(elem)) == NULL))
    return (1);
  new->next = list->_head;
  if (list->_head)
    list->_head->prev = new;
  list->_head = new;
  if (list->is_empty(list))
    {
      list->_current = list->_head;
      list->_index = 0;
      list->_tail = list->_head;
    }
  list->_size += 1;
  return (0);
}

int	PushBack(t_list *list, void *elem)
{
  t_node	*new;

  if (!list || ((new = CreateNode(elem)) == NULL))
    return (1);
  new->prev = list->_tail;
  if (list->_tail)
    list->_tail->next = new;
  list->_tail = new;
  if (list->is_empty(list))
    {
      list->_current = list->_tail;
      list->_index = 0;
      list->_head = list->_tail;
    }
  list->_size += 1;
  return (0);
}
