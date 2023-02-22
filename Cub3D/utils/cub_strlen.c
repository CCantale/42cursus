size_t	cub_strlen(char	*str)
{
	size_t	i;
	
	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}
