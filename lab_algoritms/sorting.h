
/*
*
*
*
*/

#ifndef _sorting_
#define _sorting_






/*
*
*Swap function uses for swaping two functions. 
*
*/
void swap(unsigned int* n, unsigned int* m);

/*
*
*This printArray function uses for printing the elelments after 
* the functions done thire task. 
*
*/
void printArray(int arr[], int size); 
/*
* 
* This function sorter an elements. It takes unsigned element array, 
* size of the arrays elements and counter that counts how many times
* the function will execut. 
* 
*/
unsigned int* selectSort(unsigned int arr[], int size, int* op);


/*
*This function sorter an elements. It takes unsigned element array, 
* size of the arrays elements and counter that counts how many times
* the function will execut.
* So this function works the same as the selectSort do. But, in diferent way. 
*
*/
unsigned int* insertSort(unsigned int arr[], int size, int* op);



/*
*MergeSort function merged and sortod elelments. It takes an 
* unsigned array, size of an array and executing counter as 
* a parameter. Then it riturns merged sorted array. 
*
*
*/

unsigned int* mergeSort(unsigned int aa[], int size, int* op);

/*
*
*
*
*/


//void* quicksort(int arr[], int size);




#endif // !



