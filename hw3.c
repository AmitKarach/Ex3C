#include <stdio.h>
#include <string.h>
//simple pointer based shift,
//from pointer that i got from insertion function move I numbers right
void shift_element(int *arr, int i)
{
	int ind;
	if (i > 0)
	{
		for (ind = i; ind > 0; ind--)
		{
			//shift them right
			*(arr + ind) = *(arr + ind - 1);
		}
	}
}

void insertion_sort(int *arr, int len)
{
	int temp;
	//array itterate 
	for (int i = 0; i < len; i++)
	{
		int index = i;
		//needed to know where to send the shift
		while (index > 0 && *(arr + i) < *(arr + (index - 1)))
		{
			index = index - 1;
		}
		temp = *(arr + i);
		shift_element(arr + index, i - index);
		*(arr + index) = temp;
	}
}

int main()
{
	//based on project array will always be 50 hence define
#define arraysize 50
	int arr[arraysize];
	//scan array from file -- redirection
	for (int i = 0; i < arraysize; i++)
	{
		scanf("%d", &arr[i]);
	}
	// sort
	insertion_sort(arr, arraysize);
	//print ARRAY
	for (size_t i = 0; i < arraysize; i++)
	{
		printf("%d,", arr[i]);
	}

	return 0;
}
