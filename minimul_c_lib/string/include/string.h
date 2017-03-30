#ifndef _STRING_H
#define _STRING_H

#ifndef NULL 
#define NULL ((void *)0)
#endif
/*
#ifndef __restrict 
#define __restrict restrict
#endif
*/

void *memcpy (void *, const void *, int);
void *memmove (void *, const void *, int);
void *memset (void *, int, int);
int memcmp (const void *, const void *, int);
void *memchr (const void *, int, int);

char *strcpy (char *, const char *);
char *strncpy (char *, const char *, int);

char *strcat (char *, const char *);
char *strncat (char *, const char *, int);


int strcmp (char const *, const char *);
int strncmp (char const *, const char *, int);

char *strchr (const char *, int);
char *strrchr (const char *, int);

char *strcspn (const char *, const char *);
char *strspn (const char *, const char *);
char *strpbrk (const char *, const char *);
char *strstr (const char *, const char *);
char *strtok (const char *, const char *);

int strlen (const char *);

char *strerror (int);

#endif
