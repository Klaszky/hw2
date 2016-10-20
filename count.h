#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void *malloc(size_t size);
void *calloc(size_t nitems, size_t size);
void free(void *ptr);

int fscanf(FILE *stream, const char *format, ...);

int strcmp(const char *string1, const char *string2);
size_t strlen(const char *str);

char *strcpy(char *destination, const char *source);

int hashKey(char *str, int tableSize);
int addtoHashT(int key, char *addr);
int hashSearch(int key, char *addr);
int isXdig(char *input);


struct node
{
	int key;
	char address[20];
	struct node *next;
};

struct hashTable
{
	struct node *head;
};
