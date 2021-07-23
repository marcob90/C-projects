#include <stdlib.h>

/*function that create a pool of memory of a given size.
The starting byte will be divisible by the entered alignment*/
void* aligned_malloc(size_t required_bytes, size_t alignment){
	void* p1; //initial block
	void *p2; //aligned block inside initial block
	
	/*the offset makes sure the memory address is divisible
	by alignment. It also includes the address of where
	the pool of memory begins (sizeof(void*)) = 8 in the
	current system*/
	int offset = alignment - 1 + sizeof(void*);
	
	if((p1 = (void*)malloc(required_bytes + offset)) == NULL)
		return NULL;
		
	/*p2 has to point to a byte divisible by alignement.
	The required_bytes in input will fit after*/
	p2 = (void*)(((size_t)p1 + offset) & ~(alignment - 1));
	
	//save the address of the first byte
	*((size_t *)p2 - 1) = (size_t)p1;
	
	return p2;
}

void aligned_free(void *p2){
	void* p1 = (void *)(*((size_t *)p2 - 1));
	free(p1);
}

int main(){
	void* p = aligned_malloc(100, 16);
	aligned_free(p);
}
