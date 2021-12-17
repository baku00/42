#include <stdio.h>

int main()
{
	#ifdef HELLO
		printf("%d\n", HELLO);
	#else
		printf("Good bye\n");
	#endif
	return 0;
}
