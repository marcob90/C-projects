#include <stdio.h>

int fibonacci(int);
int arr[100];

int main(){
	int n; 
	int i;
	for(i = 0; i < 100; i++) arr[i] = -1;
	
	printf("Enter the position of Fibonacci sequence you want to get: ");
	scanf("%d", &n);
	printf("\nFibonacci (%d): %d", n, iterativeFibonacci(n));
	printf("\nFibonacci (%d): %d", n, fibonacci(n));
	printf("\nFibonacci (%d): %d", n, iterativeFibonacciMem(n));
	return 0;
}

//memoization
int fibonacci(int a){ 
	if(arr[a] != -1) return arr[a];
	
	if(1 == a || 0 == a)
		return arr[a] = a;
	else
		return arr[a] = fibonacci(a-1) + fibonacci(a-2);
}

//dynamic programming + memoization
int iterativeFibonacci(int a){
	int fib[a + 1];
	int i;
	
	//initialization to make the algorithm start
	fib[0] = 0;
	fib[1] = 1;
	
	for(i = 2; i < a + 1; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	
	return fib[a];
}

//dynamic programming + memory saving
int iterativeFibonacciMem(int n){
	int a = 0, b = 1, c;
	int i;
	
	if(n == 0) return n;
	
	for(i = 2; i <= n; i++){
		c = a + b;
		a = b;
		b = c;
	}
	
	return b;
}
