#include "push_swap.h"

int	main(int ac, char **av)
{
	char **new_list;

	if (ac < 2)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (ac == 2)
	{
		new_list = ft_split((const char *)av[1], ' ');
		ft_parsing(new_list);
	}
	if (ac > 2)
	{
		ft_parsing(av);
	}
	return (0);
}
