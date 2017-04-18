int strlen(const char *str) 
{
	int i = 0;
	if(str == NULL)
		return i;
	for( ; *(str+i) != '\0'; i++)
		;
	return i;
}
