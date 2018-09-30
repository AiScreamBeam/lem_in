#include "../includes/lemin.h"

void	initialize_ints(t_gen *all)
{
	all->nr_ant = 0;
	all->ants->room_nr = 0;
}

int main(void)
{
	t_gen	all;
	
	all.input = read_input(&all);
	find_info(&all);
//	initialize_ints(&all);
	find_path(&all);

	return (0);
	
}
