#include "first_last.h"

void first_last(int arr[], int size, int target, int *first, int *last)
{
	int     i;

	i = -1;
	while(size > ++i)
	{
		if(arr[i] == target)
		{
			*first = i;
			break;
		}
	}
	if(i == size)
	{
		*last = -1;
		*first = -1;
		return ;
	}
	while(--size >= i)
	{
		if(arr[size] == target)
		{
			*last = size;
			break;
		}
	}
}

/* 
int main()
{
	int arr[] = {4, -1, 2, 9, 101, 100, 9, 12, 0, 0};
	int     first;
	int     last;

	first_last(arr, 10, 9, &first, &last);
	printf("first: %d\n", first);
	printf("last: %d\n", last);
	return 0;
} */