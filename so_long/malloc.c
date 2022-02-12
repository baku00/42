#include <malloc/malloc.h>
#include <stdio.h>

int main(){
	printf("Malloc: %u\n", malloc_size());
	return 0;
}
