#include "sorting.h"
#include<stdlib.h>


void swap(unsigned int* n, unsigned int* m)
{
	int temp = *n;
	*n = *m;
	*m = temp;
}


static unsigned int* merge(unsigned int arrB[], int sizeB, unsigned int arrC[],
	int sizeC, unsigned int mergedArray[], int* op)
{
	int i = 0, j = 0, k = 0;
	while (i < sizeB && j < sizeC)
	{
		(*op)++;
		//printf("\n b[%d] = %d, c[%d] = %d \n", i, arrB[i], j, arrC[j]);
		if (arrB[i] <= arrC[j])
		{
			mergedArray[k] = arrB[i];
			//printf("\n b[%d] = %d, mergedArray[%d] = %d \n", i, arrB[i], k, mergedArray[k]);
			i++;
		}
		else {
			mergedArray[k] = arrC[j];
			//printf("\n mergedArray[%d] = %d, c[%d] = %d \n", k, mergedArray[k], j, arrC[j]);
			j++;
		}
		k++;
	}
	if (i == sizeB)
	{
		for (int t = j; t < sizeC; t++)
		{
			(*op)++;
			mergedArray[k] = arrC[t];
			//printf("\n mergedArray[%d] = %d, c[%d] = %d \n", k, mergedArray[k], j, arrC[t]);
			k++;
		}
	}
	else {
		for (int t = i; t < sizeB; t++)
		{
			(*op)++;
			mergedArray[k] = arrB[t];
			//printf("\n mergedArray[%d] = %d, c[%d] = %d \n", k, mergedArray[k], j, arrB[t]);
			k++;
		}
	}
	return mergedArray;
}


static unsigned int* copy(unsigned int copyArray[], unsigned int orginal[], int sizeCopy, int* op)
{
	for (int n = 0; n < sizeCopy; n++)
	{
		copyArray[n] = orginal[n];
		(*op)++;
	}
	return copyArray;
}






void printArray(int arr[], int size)
{
	printf("\n Sorted array is: \n");
	for (int i = 0; i < size; i++) {
		printf("%d, ", arr[i]);
	}
	printf("\n");
}


unsigned int* selectSort(unsigned int arr[], int size, int* op)
{
	//int size = sizeof(arr);
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{

			 // eller ++*op; 
			//printf("\n aar[j]= %d, arr[min]= %d \n", arr[j], arr[min]);
			//printf("\n j= %d, min= %d \n", j, min);
			if (arr[j] < arr[min])
			{
				(*op)++;
				//printf("op = %d", *op); 
				min = j;
			}
		}
		swap(&arr[i], &arr[min]);
	
	}
	return arr;
}


unsigned int* insertSort(unsigned int arr[], int size, int* op)
{
	unsigned int v;
	int j, i;
	for (i = 1; i < size; i++)
	{
		v = arr[i];
		//printf("\ni=%d", i);
		j = i - 1;
		while (j >= 0 && arr[j] > v)
		{
			//printf("\nj=%d", j); 
			(*op)++;
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = v;
		//(*op)++;
		/*
		printf("\n array is: \n");
		for (int i = 0; i < size; i++) {
			printf("%d, ", arr[i]);
		}
		*/
	}
	return arr;
	//tim complexity is O(n^2)
}

int m = 0;
unsigned int* mergeSort(unsigned int aa[], int size, int *op)
{
	unsigned int* arrayB = (unsigned int*)malloc(sizeof(unsigned int) * (size / 2));
	unsigned int* arrayC = (unsigned int*)malloc(sizeof(unsigned int) * (size - size / 2));
	//(*op)++;
	m++;
	//printf("\n forward recurs m= %d, \n", m);
	if (arrayB != NULL && arrayC != NULL)
	{
		if (size > 1)
		{
			copy(arrayB, aa, size / 2, &op);
			/*printf("\n arrayB size= %d ", size / 2);
			for (int r = 0; r < size / 2; r++)
			{
				printf("%d, ", arrayB[r]);
			}
			*/
			copy(arrayC, aa + (size / 2), (size - size / 2), &op);
			/*
			printf("\n arrayC size= %d ", (size - size / 2));
			for (int r = 0; r < (size - size / 2); r++)
			{
				printf("%d, ", arrayC[r]);
			}
			*/
			mergeSort(arrayB, size / 2, &op);
			/*
			printf("\n arrayB size= %d ", size / 2);
			for (int r = 0; r < size / 2; r++)
			{
				printf("%d, ", arrayB[r]);
			}
			*/
			mergeSort(arrayC, (size - size / 2), &op);
			/*
			printf("\n arrayC size= %d ", (size - size / 2));
			for (int r = 0; r < (size - size / 2); r++)
			{
				printf("%d, ", arrayC[r]);
			}
			*/
			merge(arrayB, size / 2, arrayC, (size - size / 2), aa, &op);
			/*
			printf("\n arrayC size= %d ", (size));
			for (int r = 0; r < (size); r++)
			{
				printf("%d, ", aa[r]);
			}
			*/
		}
		//printf("\n backward recurs m= %d, \n", m);
		free(arrayB);
		free(arrayC);
		return aa;
	}
	//printf("\n backward recurs m= %d, \n", m);

	//printf("\n Memory allocation failed!"); 
	free(arrayB);
	free(arrayC);
	return NULL; 
	
}