/*bugging.c */									
#include <stdio.h>
#include <stdlib.h>

static char buff [256];
static char* string;

int main (void)
{
	printf ("Please input a string: ");
	gets (string);
	printf ("Your string is: %s", string);

	return 0;
}

