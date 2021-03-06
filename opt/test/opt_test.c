/*
** opt.c for  in /home/lelabo/rendu/PSU_2013_zappy/opt
**
** Made by lelabo_m
** Login   <lelabo@epitech.net>
**
** Started on  Tue May 13 11:00:21 2014 lelabo_m
** Last update Tue Jun 17 10:35:35 2014 Marc Le Labourier
*/

#include <stdlib.h>
#include "opt.h"

int	main(int ac, char **av)
{
  t_list	*opt;

  opt = opt_parse(ac, av, "abc");
  opt_verbose();
  if (opt == NULL)
    return (1);
  opt_display(opt);
  opt_delete(opt);
  return (0);
}
