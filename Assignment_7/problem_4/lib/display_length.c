int my_strlen(const char *str)
{
	int i, length = 0;

	for(i = 0; str[i] != '\0'; i++)
	{
		length++;
	}

	return length;
}
