long long int	ft_atoi(char* str)
{
	int				i;
	long long int	val;
	long long int	charge;

	i = 0;
	val = 0;
	charge = 1;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			val = val * 10 + str[i] - '0';
		else if (str[i - 1] >= '0' && str[i - 1] <= '9')
			break;
		else if (str[i] == '-')
			charge *= -1;
		else if (str[i] != '+')
			charge = 1;
		i++;
	}
	return (val * charge);
}