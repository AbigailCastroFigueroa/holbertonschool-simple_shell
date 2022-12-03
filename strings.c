#include "shell.h"

/**
 * _strlen - return the lenght of the string.
 *@s: string given.
 *
 * Return: 0.
 */
int _strlen(char *s)
{
	int letters;

	letters = 0;
	while (s[letters] != 0)
		letters++;
	return (letters);
}

/**
 * _strcpy - copies a string pointed including the null
 * @src: original string.
 * @dest: copied string.
 *
 * Return: copied string.
 */
char *_strcpy(char *dest, char *src)
{
	int a = 0;
	int i;

	while (src[a] != 0)
		a++;

	for (i = 0; i < a && src[i] != 0; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strcmp - function that compare two given strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if both are equals, the ascii difference
 *         between the first unmatched tokens.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
		if (s1[i] == 0)
			return (0);
	return (s1[i] - s2[i]);
}

/**
 * _strcat - add a string at the end of the first one.
 * @dest: main string.
 * @src: string appended to dest.
 *
 * Return: The merge of both strings as one.
 */
char *_strcat(char *dest, char *src)
{
	int i, z;

	for (i = 0; dest[i] != 0; )
		i++;

	for (z = 0; src[z] != 0; z++)
	{
		dest[i] = src[z];
		i++;
	}
	return (dest);
}

/**
 * _strdup - duplicate a string
 * @str: string given
 *
 * Return: pointer to the string
 */
char *_strdup(char *str)
{
	char *p;
	int i = 0, length = _strlen(str);

	p = malloc(sizeof(char) * (length + 1));
	if (p == NULL)
		return (NULL);

	while (i < length)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
