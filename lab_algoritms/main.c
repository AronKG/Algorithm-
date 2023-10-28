#include <stdio.h>
#include<time.h>
//#include <stdlib.h>
#include "sorting.h"





int main()
{
	unsigned int arr[] = { 89,45,68,90,29,34,17 };
	int size = sizeof(arr) / sizeof(arr[0]); 
	int op = 0;
	int option; 
	printf("\n array is: \n");
	for (int i = 0; i < size; i++) {
		printf("%d, ", arr[i]);
	}
	// to be removed ##############################
	/*
	int x[] = { 11,22, 33,77, };
	int y[] = { 2,19, 44};
	printf("\n x=");
	for (int r = 0; r < 4; r++)
	{
		printf("%d, ", x[r]);
	}
	printf("\n y=");
	for (int r = 0; r < 3; r++)
	{
		printf("%d, ", y[r]);
	}

	int xy[7]; 
	merge(x, 4, y, 3, xy);
	printf("\n xy="); 
	for (int r = 0; r < 7; r++)
	{
		printf("%d, ", xy[r]); 
	}

*/


	int a[2048];
	int s= 2048;
	almostSortedInput(a, s);
	sortedInput(a,s);
	sortedBackWard(a,s);
	randomInput(a, s);     //kan hända dubleter
	randInput(a, s);  // utan dubleter



	/*
	printf("\ngeneret array is\n "); 
	for (int y = 0; y < s; y++)
	{
		printf("%d, ", a[y]); 

	}
	*/

	clock_t start_t, end_t; 

	// ##############################
	printf("\nEnter\n1 to selectSort\n2 to insertSort\n3 to margeSort: "); 
	scanf_s("%d", &option); 
	switch (option)
	{
	case 1: 
		start_t = clock(); 
		selectSort(a, s, &op);    //100,000      //11.052 seconds
		end_t = clock();
		printf("\nNumber of opration in the Selectionsort is = %d", op);     //27
		printf("\n\n\n start_t = %d - end_t = %d = exec_t= %f\n", start_t, end_t, (double)(end_t - start_t)/CLOCKS_PER_SEC); 
		break;
	case 2:
		start_t = clock();
		insertSort(a, s, &op);	//100,000    //5.738 seconds
		end_t = clock();
		printf("\nNumber of opration in the insertsort is = %d", op);		//22
		printf("\nAfter insertSort function the arry will prints: ");
		printf("\n\n\n start_t = %d - end_t = %d = exec_t= %f\n", start_t, end_t, (double)(end_t - start_t) / CLOCKS_PER_SEC);

		break;
	case 3: 
		start_t = clock();
		mergeSort(a, s, &op);   //100,000      //0.122 seconds; 
		end_t = clock();
		printf("\nNumber of opration in the insertsort is = %d", op);
		printf("\nAfter mergeSort function the arry will prints: ");
		printf("\n\n\n start_t = %d - end_t = %d = exec_t= %f\n", start_t, end_t, (double)(end_t - start_t) / CLOCKS_PER_SEC);

	default:
		return 0;
	}
	//printArray(arr, size);
	return 0; 
}


