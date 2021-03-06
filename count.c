#include "count.h"

struct hashTable *hashT = NULL;

int main(int argc, char *argv[])
{
	// some set up stuff
	//////////////////////////
	int tableSize = 1000;
	int uniqueAdds = 0;

	char *mode = "r";
	char str[20];
	

	hashT = (struct hashTable*)calloc(tableSize, sizeof(struct hashTable));
	FILE *filePointer;

	// error check for a file
	///////////////////////
	if(argc == 1)
	{
		printf("error\n");
		return 0;
	}
	else
	{
		// if file is empty, just report 0
		////////////////////
		filePointer = fopen(argv[1], mode);
		if(filePointer == NULL)
		{
			printf("error\n");
			return 0;
		}
	}

	// iterates over the file  getting the addresses out
	//////////////////////////
	while(fscanf(filePointer, "%s", str) != EOF)
	{
		// addtoHashT returns 1 if it adds a new
		// address and zero if not. so, this will
		// only be incremented for unique addresses
		//////////////////////////
		uniqueAdds += addtoHashT(hashKey(str, tableSize), str);
	}

	// report num addresses
	/////////////////////////
	printf("%d\n", uniqueAdds);

	return 0;

}

// takes my char string and creats a hash index
// from its contents
//////////////////////////
int hashKey(char *str, int tableSize)
{
	if(isXdig(str))
	{
		int i, sum = 0;
		for(i = 0; i < strlen(str); i++)
		{
			if(i == 0 || i == 1)
			{
				continue;
			}

			sum += str[i];
		}

		sum = ((sum*2654435761) % tableSize);

		return sum;
	}
	else
	{
		// this value is treated like a flag
		// so that this won't be hashed
		//////////////////////////
		return -1;
	}
}

struct node * newNode(int key, char *addr)
{
	struct node * nNode;
	nNode = (struct node *)malloc(sizeof(struct node));
	nNode->key = key;
	strcpy(nNode->address, addr);
	nNode->next = NULL;
	return nNode;
}

int addtoHashT(int key, char *addr)
{
	// if is isn't a valid hex address is just returns
	//////////////////////////
	if(key == -1)
	{
		return 0;
	}

	// if it is a valid hex address is goes about making
	// a new node and searching for it in the table
	//////////////////////////
	struct node *nNode = newNode(key, addr);
	if(!hashT[key].head)
	{
		hashT[key].head = nNode;
		return 1;
	}
	else
	{
		/*change this */
		if(hashSearch(key, addr))
		{
			free(nNode);
			return 0;
		}
		else
		{
			nNode->next = hashT[key].head;
			hashT[key].head = nNode;
			return 1;
		}
	}
}

int hashSearch(int key, char *addr)
{
	struct node * current = hashT[key].head;
	while(current != NULL)
	{
		if(!strcmp(current->address, addr))
		{
			// returns true if there is already the same address
			// in the hash table
			return 1;
		}
		else
		{
			current = current->next;
		}
	}

	return 0;
}

int isXdig(char *input)
{
	int flag = 1;
	int i;

	if(strlen(input) <= 2)
	{
		flag = 0;
		return flag;
	}

	if(input[0] == '0' && input [1] == 'x')
	{
		for(i = 2; i < strlen(input); i++)
		{
			if(!isxdigit(input[i]))
			{
				flag = 0;
				return flag;
			}
		}
	}
	else
	{
		flag = 0;
		return flag;
	}

	return flag;
}