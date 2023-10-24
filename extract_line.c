char	*extract_line(char **src)
{
	char	*p;

	p = concatenate(p, *src, '\n');
	clean(&(*src));
	return (p);
}

