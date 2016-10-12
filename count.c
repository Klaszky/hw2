#include "count.h"

int main(int argc, char argv[])
{
	char *address = "0x7f1a9804ae19";
	char *end;
	long test;
	test = strtol(address, &end, 10);
	 
	printf("%s\n", address);
	printf("%l\n", test);
	return 0;
}

