/* copies the specified nbr of bytes and null-terminates right after */
char	*cub_strncpy(char *dest, char *src, size_t bytes)
{
	size_t	i;

	if (!dest)
		return (src);
	if (!src)
		return (dest);
	i = 0;
	while (src[i] && i < bytes)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = 0;
	return (dest);
}
