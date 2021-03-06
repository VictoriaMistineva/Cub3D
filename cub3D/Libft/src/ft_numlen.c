int		ft_numlen(long number, int base)
{
	int		len;

	if (number == 0)
		return (1);
	len = (number < 0) ? 2 : 1;
	while (number /= base)
		len++;
	return (len);
}
