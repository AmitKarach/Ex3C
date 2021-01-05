#include <stdio.h>
#include <string.h>

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
	for (int i = 0; i < len; i++)
	{
		int index = i;
		while (index > 0 && *(arr + i) < *(arr + (index - 1)))
		{
			index--;
		}
		temp = *(arr + i);
		shift_element(arr + index, i - index);
		*(arr + index) = temp;
	}
}

int main()
{
#define arraysize 50
	int arr[arraysize];
	for (int i = 0; i < arraysize; i++)
	{
		scanf("%d", &arr[i]);
	}
	insertion_sort(arr, arraysize);
	for (size_t i = 0; i < arraysize; i++)
	{
		printf("%d,", arr[i]);
	}

	return 0;
}
