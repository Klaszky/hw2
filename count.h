#include <stdio.h>
#include <string.h>

#define MAX 1000

void *malloc(size_t size);
void free(void *ptr);
int fscanf(FILE *stream, const char *format, ...);
int strcmp(const char *string1, const char *string2);
size_t strlen(const char *str);

struct hashItem
{
	char *adress;
};

struct hashItem *hashArr[MAX];
struct hashItem *item;
