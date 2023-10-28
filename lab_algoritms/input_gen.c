#include "input_gen.h"
#include <time.h>
#include "sorting.h"


unsigned int* sortedInput(unsigned int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = i * 2; 
	}
}

unsigned int* sortedBackWard(unsigned int a[], int size)
{
	for(int i = size-1; i >= 0; i--)
	{
		a[size-i-1] = i * 2;
	}
}


static int checkIfInArray(unsigned int qq[], int size, unsigned int x)
{
	for (int i = 0; i < size; i++)
	{
		if (qq[i] == x)
			return 1;
	}
	return 0; 
}

unsigned int* randomInput(unsigned int a[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		int r = rand() % size+1; 
		if (checkIfInArray(a, size, r))
		{
			i--;
			continue; 
		}
		a[i] = r; 
	}
	return a; 
}


unsigned int* randInput(unsigned int a[], int size) {

	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		a[i] = rand() % size + 1;
	}
}


unsigned int* almostSortedInput(unsigned int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = i * 2;
	}
	swap(&a[(size/4)-1], &a[(3*size/4) - 1]);
	swap(&a[size / 2 - 1], &a[size - 1]);
	return a;
}







