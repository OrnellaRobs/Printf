
int		ft_intlen(int value, int base)
{
	int i;

	i = 1;
	while (value >= base)
	{
		value = value / base;
		i++;
	}
	return (i);
}

char    *ft_itoa_base(int value, int base)
{
	int len;
	int sign;
	int i;
	char *str;
	char alphabet[] = "0123456789ABCDEF";

	sign = 0;
	i = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (value < -2147483647)
		return ("-2147483648");
	if (base == 10 && (value < 0))
	{
		value *= -1;
		sign = 1;
	}
	if (value < 0)
		value *= -1;
	len = ft_intlen(value, base) + sign;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (sign == 1)
		str[0] = '-';
	while (--len >= (0 + sign))
	{
		str[len] = alphabet[value % base];
		value = value / base;
	}
	return (str);
}
