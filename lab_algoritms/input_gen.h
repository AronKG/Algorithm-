/*
*This heder file uses to generet asending sorted, disending, 
* random sorted and almost sorted array. 
*/
#ifndef _input_gen_
#define _input_gen_


/*
* Takes unsigend orderabel integers as a parameter
and riturns asendinng array.
*/
unsigned int* sortedInput(unsigned int a[], int size);


/*
*Takes unsigend orderabel integers as a parameter
and riturns dsending rray
*
*
*/

unsigned int* sortedBackWard(unsigned int a[], int size);


/*
*
*takes unsigned integer as a parameter 
and riturns random sorted array
*
*/
unsigned int* randomInput(unsigned int a[], int size);


/*
*
*Takes unsigned integer elements and return almost
* sorted array
*
*/
unsigned int* almostSortedInput(unsigned int a[], int size);




#endif // !


