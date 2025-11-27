int	ft_isspace(char c)
{
	if (c > 8 && c < 14 || c == 32)
		return(1);
	else
		return (0);
}

long int	ft_atol(char *nb)
{
	int	neg;
	int	n;

	neg = 1;
	while (ft_isspace(*nb))
		nb++;
	if (*nb == '-' || *nb == '+')
	{
		if(*nb == '-')
			neg = -1;
		nb++;
	}
	while (*nb >= '0' && *nb <= '9')
	{
		n = n * 10 + (*nb - 48); 
		nb++;
	}
	return (neg * n);
}

void	ft_parsing()
{

}
