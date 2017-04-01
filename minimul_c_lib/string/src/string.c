#include "string.h"


/*
   void *memcpy (void *, const void *, int)
   void *memmove (void *, const void *, int)
   void *memset (void *, int, int)
   void *memchr (const void *, int, int)
 */
int memcmp (const void *dst, const void *src, int n) 
{
	const char *a = dst;
	const char *b = src;
	if (!n)
		return 0;

	while ((n-- > 0) && (*a++ == *b++))
		;
	
	return (*a - *b);
}
int strlen (const char *str)
{ 
	int i = 0;
	while(*(str+i) !='\0') 
		i++;
	return i;
}

char *strcpy (char *dst, const char *src) 
{
	char *d = dst;
	while ((*dst++ = *src++));
	return d;
}


char *strncpy (char *dst, const char *src, int n)
{
	char *d = dst;
	while ((n-- > 0) && (*dst++ = *src++) );
	while (n > 0) {
		*dst++ = '\0';
		n--;
	}
	return d;
}
char *strcat (char *dst, const char *src) 
{
	int i = strlen(dst);
	while ((*(dst + i++) = (*src++)));

	return dst;
}
char *strncat (char *dst, const char *src, int n)
{
	int i = strlen(dst);
	while ((n-- > 0) && (*(dst+i++) = (*src++)));
	while (n > 0) {
		*(dst + i++) = '\0';
		n--;
	}		
	return dst;

}

int strcmp (char const* dst, const char *src)
{
	while ( *dst && *src) {
		if (*dst != *src)
			break;
		dst++;
		src++;
	}
	return (*dst - *src);

}


int strncmp (char const *dst, const char *src, int n)
{  

	while ( *dst && *src && n > 0) {
		if (*dst != *src)
			break;
		dst++;
		src++;
		n--;
	}
	return (*dst - *src);
}
char *strchr (char const *ptr, int c) 
{
	char s = (char)c;
	while ( (*ptr != '\0') && (*ptr != s))
	{
		ptr++;
	}
	return (*ptr == '\0' ? NULL : (char *)ptr);
}
char *strrchr (char const *ptr, int c)
{
	char *temp = NULL;
	char s = (char) c;
	while (*ptr != '\0') {
		if (*ptr == s)
			temp = (char *)ptr;
		ptr++;
	}
	return temp;
}

/*
   char *strcspn (const char *, const char *)
   char *strspn (const char *, const char *)
   char *strpbrk (const char *, const char *)
   char *strstr (const char *, const char *)
   char *strtok (const char *, const char *)
 */

