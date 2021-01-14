char gch()
{
	char c;
	while ((c = cin.get()) != EOF)
	{
		if (c == ' ' || c == ' ')
		{
			return c;
		}
	}
	return '?';
}
