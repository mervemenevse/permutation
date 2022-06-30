#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <chrono>

using namespace std;

static int values = 0;
void backtracking(int, int*, int);
void printArray(int*, int);
int contains(int*, int);
int main()
{
	int length=4, option ;
	int* permutations = (int*)malloc(length * sizeof(int));
	for (int i = 0; i < length; ++i) {
		permutations[i] = i+1;
	}



		printf("Backtracking:\n");
		
	
		values = 0;
		backtracking(0, permutations, length);

	
	printf(" %i", values);
	
	free(permutations);
	return 0;
}

void backtracking(int init, int* permutations, int length) {
	int i;
	if (init == length) {
		printArray(permutations, length); 
		
	}
	else {
		for (i = init; i < length; ++i) {
			
			swap(permutations[init], permutations[i]);
			values++;
			backtracking(init + 1, permutations, length);
			values++;
			swap(permutations[init], permutations[i]);
		}
	}
}

void printArray(int* permutations, int length)
{
	int i;
	for (i = 0; i < length; ++i)
	{
		printf("%d", permutations[i]);
	}
	printf("\n");
}

int contains(int* permutations, int init)
{
	int i;
	for (i = init - 1; i >= 0; --i)
	{
		if (permutations[i] == permutations[init]) { return 0; }
	}
	return 1;
}
