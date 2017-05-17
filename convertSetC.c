
int do_print_wchar(int i, t_tp *dt, int bin, int *lim)
{
	char *str;

	str = ft_itoa_base((uintmax_t)i, 2, 'a'); // binaire
	if (bin != 0 && dt->pre != -1 && (test_next(*lim, str) == -1))
	{
		free(str);
		*lim = 0;
		return (0);
	}
	if (ft_strlen(str) <= 7) // traitement comment un char classique
	{
		if (bin == 0)
			do_print_ad((unsigned char)i, dt);
		else
		{
			write(1, (unsigned char *)&i, 1);
			dt->nb += 1;
			*lim = *lim - 1;
		}
	}
	else
		do_mask_set(str, dt, bin, lim); // traitement wchar
	free(str);
	return (0);
}

void do_mask_set(char *str, t_tp *dt, int bin, int *lim) // str -> binaire
{
	char *ptr;
	int si;

	ptr = NULL;
	si = ft_strlen(str);
	if (si <= 11)
	{
		ptr = ft_strdup("110xxxxx 10xxxxxx");
		do_fill_ms(ptr, str);
		print_val_int(ptr, dt, bin, lim);
	}
	else if (si > 11 && si <= 16)
	{
		ptr = ft_strdup("1110xxxx 10xxxxxx 10xxxxxx");
		do_fill_ms(ptr, str);
		print_val_int(ptr, dt, bin, lim);
	}
	else if (si > 16)
	{
		ptr = ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
		do_fill_ms(ptr, str);
		print_val_int(ptr, dt, bin, lim);
	}
	free(ptr);
}

void norm_fill_ms(char **ptr, char **str, int *i)
{
	char *tmp1;

	*i = 0;
	tmp1 = *ptr;
	while (*tmp1)
		tmp1++;
	tmp1--;
	*ptr = tmp1;
	tmp1 = *str;
	while (*tmp1)
	{
		tmp1++;
		*i += 1;
	}
	tmp1--;
	*str = tmp1;
}

void do_fill_ms(char *ptr, char *str)
{
	char *buf;
	int i;

	buf = ptr;
	norm_fill_ms(&ptr, &str, &i);
	while (i != 0)
	{
		if (*ptr == 'x')
		{
			*ptr = *str;
			str--;
			i--;
		}
		ptr--;
	}
	while (*buf)
	{
		if (*buf == 'x')
			*buf = '0';
		buf++;
	}
}

int get_int(char *str)
{
	long int i;
	long int b;

	b = powa_int(2, 7);
	i = 0;
	while (*str)
	{
		if (*str == '1')
			i += b;
		b = b / 2;
		str++;
	}
	return (i);
}

long int powa_int(long int i, int b)
{
	long int st;

	st = i;
	b--;
	while (b)
	{
		i *= st;
		b--;
	}
	return (i);
}

void print_val_int(char *ptr, t_tp *dt, int bin, int *lim)
{
	char **tab;
	char i;
	int ind;

	ind = 0;
	tab = ft_strsplit(ptr, ' ');
	if (dt->flag[2] == '0' && bin == 0)
		print_char_tim((dt->flag[1] == '1') ? '0' : ' ', dt->field_s - 1, dt);
	while (tab[ind]) // separation des octets
	{
		i = (char)get_int(tab[ind]); // transformation en int
		write(1, &i, 1);
		ind++;
		dt->nb += 1;
		if (bin != 0)
			*lim = *lim - 1;
	}
	if (dt->flag[2] == '1' && bin == 0)
		print_char_tim((dt->flag[1] == '1') ? '0' : ' ', dt->field_s - 1, dt);
	free_tab(tab);
}
